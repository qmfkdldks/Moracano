#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    mFile = nullptr;
    
    QAction *openAction = new QAction("Open", this);
    QObject::connect(openAction, SIGNAL(triggered(bool)), this, SLOT(onFileOpenAction()));

    QMenu *fileMenu = new QMenu("File", this);
    fileMenu->addAction(openAction);
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
        mFile->open(QFile::ReadWrite);

        QTextStream stream(mFile);
        this->mTextEdit->setText(stream.readAll());
    }
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
