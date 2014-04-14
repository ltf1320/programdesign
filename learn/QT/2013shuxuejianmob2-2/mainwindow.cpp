#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Ui_MainWindow()
{
    setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(work()));
    connect(saveMapact,SIGNAL(triggered()),this,SLOT(saveMap()));
    connect(openMapact,SIGNAL(clicked()),this,SLOT(loadMap()));
    connect(openArract,SIGNAL(triggered()),this,SLOT(loadArr()));
    connect(saveArract,SIGNAL(triggered()),this,SLOT(saveArr()));
    nextBtn->setVisible(false);
    preBtn->setVisible(false);
    addBtn->setVisible(false);
    delBtn->setVisible(false);
    redoBtn->setVisible(false);
    for(int i=0;i<11;i++)
        for(int j=0;j<19;j++)
        {
            arrLayout->addWidget(&arrs[j][i],j,i,4,4);
        }
}

void MainWindow::work()
{
    QString fileName=pathE->text();
    for(int i=0;i<fileName.length();i++)
        if(fileName[i]=='\\')
            fileName[i]='/';
    int picNum=numE->text().toInt();
    wd=new ImageWidget(NULL,fileName,picNum);
    nextBtn->setVisible(true);
    preBtn->setVisible(true);
    addBtn->setVisible(true);
    delBtn->setVisible(true);
    redoBtn->setVisible(true);
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(getNext()));
    connect(preBtn,SIGNAL(clicked()),this,SLOT(getPre()));
    connect(addBtn,SIGNAL(clicked()),this,SLOT(addEdge()));
    connect(delBtn,SIGNAL(clicked()),this,SLOT(delEdge()));
    connect(redoBtn,SIGNAL(clicked()),this,SLOT(redo()));
    updateLayout();
    wd->show();
}

void MainWindow::getNext()
{
    wd->getNext();
    updateLayout();
}

void MainWindow::getPre()
{
    wd->getPre();
    updateLayout();
}

void MainWindow::updateLayout()
{

    for(int i=0;i<Wid;i++)
        for(int j=0;j<Hei;j++)
        {
            arrs[i][j].setText(QString::number(wd->arr.ss[i][j]));
        }
}

void MainWindow::addEdge()
{
    int k=kEdit->text().toInt(),j=jEdit->text().toInt(),i=iEdit->text().toInt();
    wd->tp.map[k][i][j]=1;
}

void MainWindow::delEdge()
{
    int k=kEdit->text().toInt(),j=jEdit->text().toInt(),i=iEdit->text().toInt();
    wd->tp.map[k][i][j]=0;
}



void MainWindow::saveMap()
{
    QString fileName;
    fileName=QFileDialog::getSaveFileName(this);
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        for(int k=0;k<2;k++)
            for(int i=0;i<=wd->tp.PicNum;i++)
                for(int j=0;j<=wd->tp.PicNum;j++)
                {
                    out<<wd->tp.map[k][i][j]<<" ";
                }
    }
}

void MainWindow::loadMap()
{
    QString fileName;
    fileName=QFileDialog::getOpenFileName();
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        for(int k=0;k<2;k++)
            for(int i=0;i<=wd->tp.PicNum;i++)
                for(int j=0;j<=wd->tp.PicNum;j++)
                {
                    in>>wd->tp.map[k][i][j];
                }
    }
}

void MainWindow::saveArr()
{
    QString fileName;
    fileName=QFileDialog::getSaveFileName(this);
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<19;j++)
            {
                out<<wd->arr.ss[i][j]<<" ";
            }
            out<<endl;
        }
    }
}

void MainWindow::loadArr()
{
    QString fileName;
    fileName=QFileDialog::getOpenFileName();
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        for(int i=0;i<11;i++)
            for(int j=0;j<19;j++)
            {
                in>>wd->arr.ss[i][j];
            }
    }
}


void MainWindow::updateArr()
{
    updateLayout();
}


void MainWindow::redo()
{
    wd->redo();
    updateLayout();
}


void MainWindow::disp()
{
    for(int i=0;i<Wid;i++)
        for(int j=0;j<Hei;j++)
        {
            wd->arr.ss[i][j]=arrs[j][i].text().toInt();
        }
   wd->update();
}
