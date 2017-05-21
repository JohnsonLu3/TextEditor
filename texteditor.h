#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = 0);
    ~TextEditor();

private slots:
    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSelect_All_triggered();

private:
    Ui::TextEditor *ui;
};

#endif // TEXTEDITOR_H
