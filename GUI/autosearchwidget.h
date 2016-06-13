#ifndef AUTOSEARCHWIDGET_H
#define AUTOSEARCHWIDGET_H

#include <QWidget>
#include "Lib/autosearchmanager.h"
#include "meaningselector.h"

namespace Ui {
class AutoSearchWidget;
}

class AutoSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AutoSearchWidget(QWidget *parent = 0);
    ~AutoSearchWidget();

public slots:
    void onSearchFinished();

    ///
    /// \brief onMeaningSelected
    /// \param meaning
    /// This method is fired when meaningselector select a meaning.
    ///
    void onMeaningSelected(QString meaning);

private:
    Ui::AutoSearchWidget *ui;
    AutoSearchManager* manager;
    MeaningSelector* selector;
};

#endif // AUTOSEARCHWIDGET_H
