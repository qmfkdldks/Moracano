#include "site.h"

#include <QEventLoop>

Site::Site(QObject *parent) : Data(parent)
{

}

void Site::setData(QVariantList &inVector)
{
    if(inVector.size() == 8)
    {
        ID = inVector[0].toInt();
        mMainAddress = inVector[1].toUrl();
        mQueryBase = inVector[2].toUrl();
        mSearchKey = inVector[3].toString();
        mTagName = inVector[4].toString();
        mAttribute = inVector[5].toString();
        mAttributeValue = inVector[6].toString();
        mWebElementMode = static_cast<CuttingMode>(inVector[7].toInt());
    }
    else
        qDebug() << "SearchSite set data funtion's Vector size is not equivalent :" + inVector.size();
}

QVariantList Site::getData()
{
    QVariantList list;

    list
    << mMainAddress
    << mQueryBase
    << mSearchKey
    << mTagName
    << mAttribute
    << mAttributeValue
    << static_cast<int>(mWebElementMode);

    return list;
}

QStringList Site::getDataKeys()
{
    QStringList keys;
    keys
    << "MainAddress"
    << "QueryBase"
    << "SearchKey"
    << "TagName"
    << "Attribute"
    << "AttributeValue"
    << "WebElementMode";

    return keys;
}

///////////////////////////////////////////////////////////////////////////////

void Site::replyFinished()
{
    QNetworkReply *reply = dynamic_cast<QNetworkReply*>(QObject::sender());

    qDebug() << "Size :" << reply->size();

    if(reply->error())
    {
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << "1: " << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << "2: " << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << "3: " << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << "4: " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "5: " << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        QUrl redirectionUrl(reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString());
        qDebug() << "6: " << redirectionUrl.toDisplayString();


        if(!redirectionUrl.isEmpty())
        {
            qDebug() << "Redirection...";

//            QEventLoop loop;

//            QNetworkReply *redirectionReply = reply->manager()->get(QNetworkRequest(redirectionUrl));
//            QObject::connect(redirectionReply, SIGNAL(finished()), this, SLOT(replyFinished()));
//            QObject::connect(redirectionReply, SIGNAL(finished()), &loop, SLOT(quit()));

//            loop.exec();

            return;
        }
        else
        {
            qDebug() << reply->url();

            this->mWebElementManager.setSourceCode(QString(reply->readAll()));
            mWebElementManager.getElementRange(mTagName, mAttribute, mAttributeValue);

            switch (this->mWebElementMode)
            {
                case CuttingMode::extract:
                    mWebElementManager.extractTarget();
                    break;

                case CuttingMode::remove:
                    mWebElementManager.removeTarget();
                    break;

                default:
                    mWebElementManager.setTargetCode(mWebElementManager.getSourceCode());
                    break;
            }

            //Asynchronous
            emit cuttingFinished(this);
        }
    }

    reply->close();
    reply->deleteLater();
}

////////////////////////////////////////////////////////////////////////////

QString Site::getTargetCodeString()
{
    QStringList codeList = mWebElementManager.getTargetCode();
    //codeList.prepend(this->mMainAddress.toString());

    if(!codeList.empty())
        return codeList.join("\n");
    else
        return QString("is empty.");
}

////////////////////////////////////////////////////////////////////////////

QUrl Site::mainAddress() const
{
    return mMainAddress;
}

void Site::setMainAddress(const QUrl &mainAddress)
{
    mMainAddress = mainAddress;
}

QUrl Site::queryBase() const
{
    return mQueryBase;
}

void Site::setQueryBase(const QUrl &queryBase)
{
    mQueryBase = queryBase;
}

QString Site::searchKey() const
{
    return mSearchKey;
}

void Site::setSearchKey(const QString &searchQuery)
{
    mSearchKey = searchQuery;
}

QUrl Site::getSearchQuery(const QString &inWord)
{
    QUrlQuery query;

    if(mSearchKey == "")
    {
        return QUrl(this->mQueryBase.toString() + inWord);;
    }

    query.addQueryItem(mSearchKey, inWord);
    this->mQueryBase.setQuery(query);

    qDebug() << query.toString();
    qDebug() << this->queryBase().toString();

    return this->queryBase();
}

int Site::getID() const
{
    return ID;
}

void Site::setID(int value)
{
    ID = value;
}

int Site::getWebElementMode() const
{
    return static_cast<int>(mWebElementMode);
}

void Site::setWebElementMode(int inWebElementMode)
{
    mWebElementMode = static_cast<CuttingMode>(inWebElementMode);
}

void Site::setWebElementMode(const CuttingMode & inWebElementMode)
{
    this->mWebElementMode = inWebElementMode;
}

QString Site::getAttributeValue() const
{
    return mAttributeValue;
}

void Site::setAttributeValue(const QString &attributeValue)
{
    mAttributeValue = attributeValue;
}

QString Site::getAttribute() const
{
    return mAttribute;
}

void Site::setAttribute(const QString &attribute)
{
    mAttribute = attribute;
}

QString Site::getTagName() const
{
    return mTagName;
}

void Site::setTagName(const QString &tagName)
{
    mTagName = tagName;
}

