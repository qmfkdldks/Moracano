#ifndef MEANINGSELECTOR_H
#define MEANINGSELECTOR_H

#include <QDebug>

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QPushButton>


class MeaningSelector : public QWidget
{
Q_OBJECT
public:
    MeaningSelector(QWidget * parent = 0, Qt::WindowFlags f = 0);
    MeaningSelector(const QList<QString> &meanings, QWidget * parent = 0, Qt::WindowFlags f = 0);

    void setMeanings(const QList<QString>& meanings);
signals:
    void meaningSelected(QString meaning);

public slots:
    void onClicked();

private:
    QScrollArea *mScrollArea;
    QGridLayout *mGridLayout;

    QWidget *mButtonsWidget;

    QList<QPushButton*> mButtons;
    QString mSelectedMeaning;
};

#endif // MEANINGSELECTOR_H
