#include "texteditor.h"
#include "ui_texteditor.h"
#include "about.h"
#include <QClipboard>
#include <QMimeData>

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
    QApplication::quit();
}
