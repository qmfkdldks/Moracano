#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


// Custom
#include <moracanoengine.h>

#include "GUI/autosearchwidget.h"
#include "GUI/texteditor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
