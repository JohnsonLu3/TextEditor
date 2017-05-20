#include "texteditor.h"
#include "ui_texteditor.h"

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
