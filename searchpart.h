#ifndef SEARCHPART_H
#define SEARCHPART_H

#include <QObject>
#include <QList>
#include <QWebView>

class SearchPart : public QObject
{
    Q_OBJECT
public:
    explicit SearchPart(QObject *parent = 0);

    ///
    /// \brief Search
    /// \param word
    ///
    void Search(QString &word);

    QList<QWebView *> viewList() const;
    void setViewList(const QList<QWebView *> &viewList);

signals:

public slots:

private:
    QList<QWebView*> mViewList;
};

#endif // SEARCHPART_H
