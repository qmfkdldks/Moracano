#ifndef AUTOSEARCHMANAGER_H
#define AUTOSEARCHMANAGER_H

#include <QObject>
#include <QDebug>
#include <QClipboard>
#include <QtWebKitWidgets>

class AutoSearchManager : public QObject
{
Q_OBJECT
public:
    AutoSearchManager();

    ///
    /// \brief start
    /// Start watching the clipboard copy action.
    ///
    void start();

    ///
    /// \brief end
    /// End watching.
    ///
    ///
    void end();

    /// \brief record
    ///
    /// This method write word and meaning on the file in the smae folder.
    void record(QString word, QString meaning = QString());

    QWebView *webView() const;

    bool getRecordingEnabled() const;
    void setRecordingEnabled(bool value);

    QList<QString> getMeanings() const;

    QString getCopyText() const;
    void setCopyText(const QString &copyText);

signals:
    ///
    /// \brief searchFinished
    /// This method fired when word searching is finished.
    ///
    void searchFinished();

private slots:
    void on_load_finished();
    void on_copy_changed();

    void on_horizontalSlider_valueChanged(int value);

private:
    QWebView *mWebView;
    QClipboard *mClipboard;
    QFile *mFile;

    // Current clipboard text.
    QString mCopyText;
    // Searched Meaning List.
    QList<QString> mMeanings;
    // Whether enable recording
    bool recordingEnabled;
};

#endif // AUTOSEARCHMANAGER_H
