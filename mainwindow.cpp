#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    AutoSearchWidget *serachWiget = new AutoSearchWidget(this);
//    this->setCentralWidget(serachWiget);

//    TextEditor *editor = new TextEditor(this);
//    editor->show();

    SearchEditor * editor = new SearchEditor(this);
    this->setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}
