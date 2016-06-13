#ifndef SEARCHEDITOR_H
#define SEARCHEDITOR_H

#include <QWidget>
#include <QSplitter>

#include "autosearchwidget.h"
#include "texteditor.h"

namespace Ui {
class SearchEditor;
}

class SearchEditor : public QWidget
{
    Q_OBJECT

public:
    explicit SearchEditor(QWidget *parent = 0);
    ~SearchEditor();

public slots:
    void onMeaningSelected(QString meaning);
    void onSelectionChanged();

private:
    Ui::SearchEditor *ui;

    QSplitter *mSplitter;

    AutoSearchWidget *mAutoSearchWidget;
    TextEditor *mTextEditor;
};

#endif // SEARCHEDITOR_H
