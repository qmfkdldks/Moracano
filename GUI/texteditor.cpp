#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    mTextEdit = new MRichTextEdit(this);
    this->setCentralWidget(mTextEdit);
}

TextEditor::~TextEditor()
{
    delete ui;
}
