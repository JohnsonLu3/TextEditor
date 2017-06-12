#include "texteditor.h"
#include "ui_texteditor.h"
#include "about.h"
#include <QClipboard>
#include <QMimeData>
#include <QFileDialog>
#include <QFile>
#include <QTextDocumentWriter>
#include <QTextCodec>
#include <QByteArray>
#include <QMessageBox>
#include <QFont>

bool EDITED = false;

/**
 * @brief saveEdites
 * Prompts a save dialog to check if the user wishes to save
 * their edits before continuing
 * @return user save choice
 */
int saveEdits(){
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    return ret;
}

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void TextEditor::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void TextEditor::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void TextEditor::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void TextEditor::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void TextEditor::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}

void TextEditor::on_actionAbout_triggered()
{
    About ab;
    ab.setModal(true);
    ab.exec();
}

void TextEditor::on_actionPrint_triggered()
{

}

void TextEditor::on_actionQuit_triggered()
{
    if(EDITED == true){
        int ret = saveEdits();
        if(ret == QMessageBox::Save){
            // save and quit
            TextEditor::on_actionSave_triggered();
            QApplication::quit();
        }else if(ret ==  QMessageBox::Discard){
            // don't save and quit
            QApplication::quit();
        }else{
            // cancel, do nothing
        }
    }else{
        QApplication::quit();
    }

}

/**
 * Save function
 *
 * Takes the text from the plainTextEdit and stores it
 * into a .txt file for future use
 */
void TextEditor::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                QDir::homePath(),
                tr("Text File (*.txt)")
                );

    QFile file(filename);
    QTextDocumentWriter writer(filename);
    writer.write(ui->plainTextEdit->document());

    QString textData = ui->plainTextEdit->toPlainText();


}

/**
 * Open Function
 *
 * Opens a .txt file and if there is already an open file
 * that was edited than prompt the user to save before
 * opening a new file
 */
void TextEditor::on_actionOpen_triggered()
{

    if(EDITED == true){
        int ret = saveEdits();
        if(ret == QMessageBox::Save){
            // save and quit
            TextEditor::on_actionSave_triggered();
            EDITED = false;
        }else if(ret ==  QMessageBox::Discard){
            EDITED = false;
        }else{
            // cancel, do nothing
            return;
        }
    }
        QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                QDir::homePath(),
                tr("Text File (*.txt)")
                );

        if(QFile::exists(filename)){
            QFile file(filename);
            file.open(QFile::ReadOnly);
            QByteArray textData = file.readAll();
            // QTextCodec *codec   = Qt::codecForHtml(textData);
            //QString    text     = codec->toUnicode(data);

            QString text = QString::fromLocal8Bit(textData);
            ui->plainTextEdit->setPlainText(text);
        }else{
            // FILE DOES NOT EXIST
            QMessageBox msgBox;
            msgBox.setInformativeText("File Does Not Exist!");
            msgBox.setText(filename);
            msgBox.exec();
        }


}

void TextEditor::on_actionNew_triggered()
{
    if(EDITED == true){
        int ret = saveEdits();
        if(ret == QMessageBox::Save){
            // save and quit
            TextEditor::on_actionSave_triggered();
            EDITED = true;
            ui->plainTextEdit->clear();
        }else if(ret ==  QMessageBox::Discard){
            EDITED = true;
            ui->plainTextEdit->clear();
        }else{
            // cancel, do nothing
        }
    }else{
        EDITED = true;
        ui->plainTextEdit->clear();
    }
}
