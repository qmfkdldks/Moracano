#include "autosearchwidget.h"
#include "ui_autosearchwidget.h"

AutoSearchWidget::AutoSearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutoSearchWidget)
{
    ui->setupUi(this);

    manager = new AutoSearchManager;
    manager->start();
    manager->setLogEnabled(true);

    QObject::connect(manager, SIGNAL(searchFinished()), this, SLOT(onSearchFinished()));

    // Add webview of manager to this widget's layout
    ui->gridLayout->addWidget(manager->webView(), 0, 0, 1, 1);

    selector = new MeaningSelector(this);
    QObject::connect(selector, SIGNAL(meaningSelected(QString)), this, SLOT(onMeaningSelected(QString)));
    ui->gridLayout->addWidget(selector, 1,0,1,1);
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
