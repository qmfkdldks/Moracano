#include "searcheditor.h"
#include "ui_searcheditor.h"

SearchEditor::SearchEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchEditor)
{
    ui->setupUi(this);


    mAutoSearchWidget = new AutoSearchWidget(this);
    mTextEditor = new TextEditor(this);
    mTextEditor->setMinimumSize(200, 100);

    mSplitter = new QSplitter(this);
    mSplitter->addWidget(mAutoSearchWidget);
    mSplitter->addWidget(mTextEditor);

    ui->gridLayout->addWidget(mSplitter);

    QObject::connect(
                mAutoSearchWidget->getSelector(),SIGNAL(meaningSelected(QString)),
                this, SLOT(onMeaningSelected(QString)));

//    QObject::connect(
//    ui->texteditor->textEdit()->getTextEdit(), SIGNAL(selectionChanged()),
//    this, SLOT(onSelectionChanged()));


}

SearchEditor::~SearchEditor()
{
    delete ui;
}

void SearchEditor::onMeaningSelected(QString meaning)
{
    QTextEdit* edit = mTextEditor->textEdit()->getTextEdit();
    QTextCursor cursor = edit->textCursor();

    if(cursor.hasSelection())
    {
        cursor.clearSelection();
    }

    QString form = " (" + meaning + ")";
    cursor.insertText(form);
    edit->setTextCursor(cursor);
}

void SearchEditor::onSelectionChanged()
{
//    ui->autosearchwidget
}
