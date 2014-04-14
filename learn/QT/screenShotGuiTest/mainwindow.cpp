#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap result = QPixmap();
    result = QPixmap::grabWindow(QApplication::desktop()->winId()); //抓取当前屏幕的图片
    QString fileName=QString("F:\\相片\\%1").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss.jpg"));
    result.save(fileName);
    qDebug()<<fileName;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
