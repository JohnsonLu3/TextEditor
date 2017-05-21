#include "texteditor.h"
#include "ui_texteditor.h"
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

}
