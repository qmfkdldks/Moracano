#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Moracano");
    // w.setWindowFlags(Qt::WindowStaysOnTopHint);
    w.show();
    return a.exec();
}
