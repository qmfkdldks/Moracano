#include "autosearchmanager.h"

AutoSearchManager::AutoSearchManager()
{
    // Get handle of Clipboard
    mClipboard = QApplication::clipboard();

    mWebView = new QWebView(0);
    mWebView->load(QUrl("http://spdic.naver.com/"));
    QObject::connect(mWebView, SIGNAL(loadFinished(bool)), this, SLOT(on_load_finished()));
//    ui->webViewLayout->addWidget(mWebView);

}

void AutoSearchManager::start()
{
    QObject::connect(mClipboard, SIGNAL(dataChanged()), this, SLOT(on_copy_changed()));
}

void AutoSearchManager::end()
{
    QObject::disconnect(mClipboard, SIGNAL(dataChanged()), this, SLOT(on_copy_changed()));
}

void AutoSearchManager::record(QString word, QString meaning)
{
    // If meaning has text prepend white space
    if(!meaning.isEmpty())
        meaning.prepend(" ");

    // counts the line number
    static float count = 1;

    // Open the file.
    mFile = new QFile(QDate::currentDate().toString(Qt::ISODate), this);
    // If user decide to log the search result
    if(mFile->open(QFile::Append) && logEnabled)
    {
        QTextStream stream(mFile);

        // fmod divide and get rest
        // every 10 line inserts line break.
        if(std::fmod(count , float(10)) == float(0))
            stream << word << meaning << endl;

        stream << word << meaning << endl;
        mFile->close();

        ++count;
    }
}

void AutoSearchManager::on_load_finished()
{
    QWebElementCollection coll = mWebView->page()->currentFrame()->findAllElements("ul.lst span.lst_txt");
    qDebug() << "Collection count :" << coll.count();

    if(coll.count() > 0)
    {

        foreach (const QWebElement& e, coll)
        {
            QString text = e.toInnerXml().remove(QRegExp("[\\n\\t\\r]"));
            qDebug() << text;
            mMeanings.append(text);
        }

        emit searchFinished();
    }
}

void AutoSearchManager::on_copy_changed()
{
    QString copy = mClipboard->text();
    // Change the page input value to the clipboard text
    mWebView->page()->currentFrame()->documentElement().findFirst("input#ac_input").setAttribute("value", copy);
    mWebView->page()->currentFrame()->evaluateJavaScript("searchSubmit();"); // Execute serach function

}

void AutoSearchManager::on_horizontalSlider_valueChanged(int value)
{
//    setWindowOpacity(qreal(value)/100);
}

QString AutoSearchManager::getCopyText() const
{
    return mCopyText;
}

void AutoSearchManager::setCopyText(const QString &copyText)
{
    mCopyText = copyText;
}

QList<QString> AutoSearchManager::getMeanings() const
{
    return mMeanings;
}

bool AutoSearchManager::getLogEnabled() const
{
    return logEnabled;
}

///

void AutoSearchManager::setLogEnabled(bool value)
{
    logEnabled = value;
}

QWebView *AutoSearchManager::webView() const
{
    return mWebView;
}
