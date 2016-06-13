#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    qDebug() << Q_FUNC_INFO ;

    mFile = nullptr;
    
    QAction *openAction = new QAction("Open", this);
    QObject::connect(openAction, SIGNAL(triggered(bool)), this, SLOT(onFileOpenAction()));

    QAction *saveAction = new QAction("Save", this);
    QObject::connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(onFileSaveAction()));

    QMenu *fileMenu = new QMenu("File", this);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);

    ui->menubar->addMenu(fileMenu);
    
    mTextEdit = new MRichTextEdit(this);
    this->setCentralWidget(mTextEdit);
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::onFileOpenAction()
{
    clearFile();

    QFileDialog  dialog;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if(dialog.exec() == QDialog::Accepted)
    {
        qDebug() << Q_FUNC_INFO << "Selected path" << dialog.selectedFiles();
        mFile = new QFile(dialog.selectedFiles().first());
        if(mFile->open(QFile::ReadWrite))
        {

            QTextStream stream(mFile);
            this->mTextEdit->setText(stream.readAll());
        }
    }
}

void TextEditor::onFileSaveAction()
{
    clearFile();

    QFileDialog  dialog;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if(dialog.exec() == QDialog::Accepted)
    {
        qDebug() << Q_FUNC_INFO << "Selected path" << dialog.selectedFiles();
        mFile = new QFile(dialog.selectedFiles().first());

        if(mFile->open(QFile::WriteOnly))
        {
            QTextStream stream(mFile);
            stream << (this->mTextEdit->toPlainText());
        }
    }
}

MRichTextEdit *TextEditor::textEdit() const
{
    return mTextEdit;
}

void TextEditor::clearFile()
{
    if(mFile)
    {
        mFile->close();
        delete mFile;
        mFile = nullptr;
    }
}
