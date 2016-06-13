#include "meaningselector.h"

MeaningSelector::MeaningSelector(QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    mLayout = nullptr;
}

MeaningSelector::MeaningSelector(const QList<QString> &meanings, QWidget *parent)
{
    setMeanings(meanings);
}

void MeaningSelector::setMeanings(const QList<QString> &meanings)
{
    QLayout* clayout = this->layout();
    if(clayout)
    {
        qDebug() << Q_FUNC_INFO << "Delete children";
        // Delete All.
        QLayoutItem *item;
        while ((item = clayout->takeAt(0)) != 0)
        {
            delete item->widget();
            delete item;
        }
        delete clayout;
    }

    mLayout = new QHBoxLayout(this);


    foreach (const QString &str, meanings) {
        QPushButton* btn = new QPushButton(str, this);
        btn->adjustSize();
        mLayout->addWidget(btn);
        QObject::connect(btn, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        mButtons.append(btn);
    }

    this->setLayout(mLayout);
    this->repaint();
}

void MeaningSelector::onClicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(this->sender());
    qDebug() << btn->text() << "Clicked";

    mSelectedMeaning = btn->text();
    emit meaningSelected(mSelectedMeaning);
}
