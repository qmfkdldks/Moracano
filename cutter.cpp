#include "cutter.h"

Cutter::Cutter()
{

}

Cutter::Cutter(const QString &inSourceCode)
{
    setSourceCode(inSourceCode);
}

Cutter::Cutter(const QString &inSourceCode, int inStart, int inEnd) : mStart(inStart), mEnd(inEnd)
{
    setSourceCode(inSourceCode);
}

//void WebElementManager::setTarget(const QString &inTagName, const QString &inAttribute, const QString &inAttributeValue)
//{
//    mTagName = inTagName;
//    mAttribute = inAttribute;
//    mAttributeValue = inAttributeValue;

//    mCloseTag = "/" + mTagName;
//    mProperty = mAttribute + "=\"" + mAttributeValue + "\"";
//}

void Cutter::getElementRange(const QString & mTagName, const QString & mAttribute, const QString & mAttributeValue)
{
    QString mProperty(mAttribute + "=\"" + mAttributeValue + "\"");
    QString mCloseTag("/" + mTagName);

    QStringList::iterator it = mSourceCode.begin();

    bool isInElement = false;
    int num = 0;
    int start = 0;
    int end = 0;

    while(it != mSourceCode.end())
    {

        if(start == 0)
        {
            if(it->contains(mTagName) && it->contains(mProperty))
                start = num;
        }
        else if(end == 0)
        {
            if(it->contains(mCloseTag) && !isInElement)
                end = num;
            else if(it->contains(mTagName) && !isInElement)
                isInElement = true;
            else if(it->contains(mCloseTag) && isInElement)
                isInElement = false;
        }

        num++;
        it++;
    }

    mStart = start;
    mEnd = end;

    qDebug() << "Start & End" << mStart << "," << mEnd;
    qDebug() << mSourceCode.at(mStart) << mSourceCode.at(mEnd);
}

void Cutter::extractTarget()
{
    this->mTargetCode.clear();

    if(this->isTargetValid())
        for(int i = 0; i < this->mSourceCode.size(); i++)
            if(i >= mStart && i <= mEnd)
                this->mTargetCode << mSourceCode[i];
}

void Cutter::removeTarget()
{
    this->mTargetCode.clear();

    if(this->isTargetValid())
        for(int i = 0; i < this->mSourceCode.size(); i++)
            if(i < mStart || i > mEnd)
                this->mTargetCode << mSourceCode[i];
}

bool Cutter::isTargetValid()
{
    return (mStart > 0 && mEnd > 0) ? true : false;
}

///////////////////////////////////////////////////////////////////////////////

void Cutter::setSourceCode(const QString &inSourceCode)
{
    mSourceCode = (inSourceCode.split(QRegExp("\n"), QString::SkipEmptyParts));
}

void Cutter::setSourceCode(const QStringList &inSourceCode)
{
    mSourceCode = inSourceCode;
}

QStringList Cutter::getSourceCode() const
{
    return mSourceCode;
}

QStringList Cutter::getTargetCode() const
{
    return mTargetCode;
}

void Cutter::setTargetCode(const QStringList &targetCode)
{
    mTargetCode = targetCode;
}



///////////////////////////////////////////////////////////////////////////////

int Cutter::getStart() const
{
    return mStart;
}

void Cutter::setStart(int start)
{
    mStart = start;
}

int Cutter::getEnd() const
{
    return mEnd;
}

void Cutter::setEnd(int end)
{
    mEnd = end;
}

