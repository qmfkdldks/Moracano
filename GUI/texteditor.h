#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDebug>

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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

    MRichTextEdit *textEdit() const;

public slots:
    void onFileOpenAction();
    void onFileSaveAction();

private:
    Ui::TextEditor *ui;
    MRichTextEdit *mTextEdit;
    QFile *mFile;

    void clearFile();
};

#endif // TEXTEDITOR_H
