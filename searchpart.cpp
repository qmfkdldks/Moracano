#include "searchpart.h"

SearchPart::SearchPart(QObject *parent) : QObject(parent)
{

}

void SearchPart::Search(QString &word)
{
    ///Todo: Test code.

}

QList<QWebView *> SearchPart::viewList() const
{
    return mViewList;
}

void SearchPart::setViewList(const QList<QWebView *> &viewList)
{
    mViewList = viewList;
}
