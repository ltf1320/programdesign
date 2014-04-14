#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

 //   process.setProgram;
    QStringList list;
    list<<"-s"<<"-f"<<"-t 60000";
    process.start("shutdown",list);
    qDebug()<<process.pid();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
