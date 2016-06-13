#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include "TextEditor/mrichtextedit.h"
namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = 0);
    ~TextEditor();

private:
    Ui::TextEditor *ui;
    MRichTextEdit *mTextEdit;
};

#endif // TEXTEDITOR_H
