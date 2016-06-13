#include "autosearchwidget.h"
#include "ui_autosearchwidget.h"

AutoSearchWidget::AutoSearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutoSearchWidget)
{
    ui->setupUi(this);

    QSplitter* mSplitter = new QSplitter(Qt::Vertical, this);

    manager = new AutoSearchManager;

//    this->startWatching();
    manager->setRecordingEnabled(true);

    QObject::connect(manager, SIGNAL(searchFinished()), this, SLOT(onSearchFinished()));

    // Add webview of manager to this widget's layout
//    manager->webView()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    ui->gridLayout->addWidget(manager->webView(), 0, 0, 1, 1);
    mSplitter->addWidget(manager->webView());

    selector = new MeaningSelector(this);
    QObject::connect(selector, SIGNAL(meaningSelected(QString)), this, SLOT(onMeaningSelected(QString)));
    mSplitter->addWidget(selector);

    qDebug() << Q_FUNC_INFO << selector->minimumSize();

    ui->gridLayout_2->addWidget(mSplitter);
}

AutoSearchWidget::~AutoSearchWidget()
{
    delete ui;
}

void AutoSearchWidget::onSearchFinished()
{
    selector->setMeanings(manager->getMeanings());
    this->update();
}

void AutoSearchWidget::onMeaningSelected(QString meaning)
{
    // Get Current copied text to write on the log.
    manager->record(manager->getCopyText(), meaning);

}

MeaningSelector *AutoSearchWidget::getSelector() const
{
    return selector;
}

void AutoSearchWidget::startWatching()
{
    manager->start();
}

void AutoSearchWidget::endWatching()
{
    manager->end();
}

void AutoSearchWidget::on_watchToggle_toggled(bool checked)
{
    (checked) ? startWatching():endWatching();
}
