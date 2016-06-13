#ifndef CUTTER_H
#define CUTTER_H

#include <QString>
#include <QStringList>

#include <QDebug>

class Cutter
{
public:
    Cutter();
    ~Cutter()
    {
        mSourceCode.clear();
        mTargetCode.clear();
    }

    Cutter(const QString & inSourceCode);
    Cutter(const QString & inSourceCode, int inStart, int inEnd);

    /*!
     * \brief Set the information of the web element which you want to get.
     *
     * \param inTagName
     * \param inAttribute
     * \param inAttributeValue
     */

 //   void setTarget(const QString & inTagName, const QString & inAttribute, const QString & inAttributeValue);

    /*!
     * \brief Extract target web element.
     * Get the target element based on mSourceCode(original code)
     * using target's information. And assigns it to the mTargetCode.
     */
    void extractTarget();

    /*!
     * \brief Remove target web element.
     * Remove the target element from orignal source code. And assign the
     * rest code to the mTargetCode.
     */

    void removeTarget();

    /*!
     * \brief Is target valid.
     * \return return true if the target start and end position is initialized;
     */

    bool isTargetValid();

    /*!
     * \brief getElementRange
     * Get the start and end position of the target web element.
     * It's essential to get the target code.
     * \sa extractTarget();, removeTarget();
     */

    void getElementRange(const QString & inTagName, const QString & inAttribute, const QString & inAttributeValue);


    void setSourceCode(const QString &inSourceCode);
    void setSourceCode(const QStringList & inSourceCode);

    QStringList getSourceCode() const;

    QStringList getTargetCode() const;
    void setTargetCode(const QStringList &targetCode);

    int getStart() const;
    void setStart(int start);

    int getEnd() const;
    void setEnd(int end);

private:

    QStringList mSourceCode;
    QStringList mTargetCode;

    int mStart, mEnd; // Target start and end position of mSourceCode.
};

#endif // CUTTER_H
