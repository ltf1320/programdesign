#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Ui_MainWindow()
{
    setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(work()));
}

  void MainWindow::work()
  {
      QString fileName=pathE->text();
      for(int i=0;i<fileName.length();i++)
          if(fileName[i]=='\\')
              fileName[i]='/';
      int picNum=numE->text().toInt();
      wd=new ImageWidget(NULL,fileName,picNum);
      wd->show();
  }
