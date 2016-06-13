#include "meaningselector.h"

MeaningSelector::MeaningSelector(QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    mGridLayout = new QGridLayout(this);
    mScrollArea = new QScrollArea(this);
    mScrollArea->setWidgetResizable(true);
    qDebug() << Q_FUNC_INFO << mScrollArea->minimumSize();
    mGridLayout->addWidget(mScrollArea);
    mButtonsWidget = nullptr;
}

MeaningSelector::MeaningSelector(const QList<QString> &meanings, QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    setMeanings(meanings);
}

void MeaningSelector::setMeanings(const QList<QString> &meanings)
{
//    std::for_each(mButtons.begin(), mButtons.end(), [this](QPushButton *btn){
//        qDebug() << btn << "Deleted";
//        btn->setVisible(false);
//        delete btn;
//    });

    if(mButtonsWidget)
    {
        QLayout* layout = mButtonsWidget->layout();
        if(layout)
        {
            QLayoutItem *item = nullptr;
            while(item = layout->takeAt(0))
                delete item;
            delete layout;
        }
        delete mButtonsWidget;
    }

    this->repaint();

    mButtonsWidget = new QWidget(0);
    QHBoxLayout *mLayout = new QHBoxLayout(0);

    foreach (const QString &str, meanings) {
        QPushButton* btn = new QPushButton(str, this);
        qDebug() << Q_FUNC_INFO << btn << "Created";
        btn->adjustSize();
        mLayout->addWidget(btn);
        QObject::connect(btn, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        mButtons.append(btn);
    }

    mButtonsWidget->setLayout(mLayout);
    mScrollArea->setWidget(mButtonsWidget);
}

void MeaningSelector::onClicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(this->sender());
    qDebug() << Q_FUNC_INFO << btn->text() << "Clicked";

    mSelectedMeaning = btn->text();
    emit meaningSelected((mSelectedMeaning).toUtf8());
}
