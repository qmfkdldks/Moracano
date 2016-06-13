#ifndef SITE_H
#define SITE_H

#include "data.h"

#include <QUrl>
#include <QUrlQuery>
#include <QNetworkReply>

#include "cutter.h"

enum class CuttingMode
{
    none = -1,extract, remove
};


class Site : public Data
{
Q_OBJECT
public:

    explicit Site(QObject * parent = 0);

    virtual void setData(QVariantList &inVector) override;
    virtual QVariantList getData() override;

    //! \brief getDataKeys
    //! \return A sequence of the variables' keys on database table.

    static QStringList getDataKeys();

    QString getTargetCodeString();
    QUrl getSearchQuery(const QString & inWord);

    QUrl mainAddress() const;
    void setMainAddress(const QUrl &mainAddress);

    QUrl queryBase() const;
    void setQueryBase(const QUrl &queryBase);

    QString searchKey() const;
    void setSearchKey(const QString &searchKey);

    QString getTagName() const;
    void setTagName(const QString &tagName);

    QString getAttribute() const;
    void setAttribute(const QString &attribute);

    QString getAttributeValue() const;
    void setAttributeValue(const QString &attributeValue);

    int getWebElementMode() const;
    void setWebElementMode(int webElementMode);

    void setWebElementMode(const CuttingMode &inWebElementMode);

    int getID() const;
    void setID(int value);

signals:
    void cuttingFinished(Site* site);

public slots:
    void replyFinished();

private:
    int ID;
    QUrl mMainAddress;
    QUrl mQueryBase;
    QString mSearchKey;

    QString mTagName, mAttribute, mAttributeValue;

    CuttingMode mWebElementMode = CuttingMode::extract;

    Cutter mWebElementManager;
};

#endif // SITE_H
