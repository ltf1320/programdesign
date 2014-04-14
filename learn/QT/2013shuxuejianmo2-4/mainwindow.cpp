#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Ui_MainWindow()
{
    setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(work()));
    connect(saveMapact,SIGNAL(triggered()),this,SLOT(saveMap()));
    connect(openMapact,SIGNAL(triggered()),this,SLOT(loadMap()));
    connect(openArract,SIGNAL(triggered()),this,SLOT(loadArr()));
    connect(saveArract,SIGNAL(triggered()),this,SLOT(saveArr()));
    nextBtn->setVisible(false);
    preBtn->setVisible(false);
    addBtn->setVisible(false);
    delBtn->setVisible(false);
    redoBtn->setVisible(false);
    findMBtn->setVisible(false);
    findSBtn->setVisible(false);
    listSBtn->setVisible(false);
    matchFBtn->setVisible(false);
    zinBtn->setVisible(false);
    zoutBtn->setVisible(false);
    for(int i=0;i<Hei;i++)
        for(int j=0;j<Wid;j++)
        {
            arrLayout->addWidget(&arrs[i][j],i,j,4,2);
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
    matchFBtn->setVisible(wd->tp.linev.size()==Hei);
    findMBtn->setVisible(true);
    findSBtn->setVisible(true);
    preBtn->setVisible(true);
    addBtn->setVisible(true);
    delBtn->setVisible(true);
    redoBtn->setVisible(true);
    nextBtn->setVisible(true);
    zinBtn->setVisible(true);
    zoutBtn->setVisible(true);
//    listSBtn->setVisible(true);
    connect(listSBtn,SIGNAL(clicked()),this,SLOT(listSameLine()));
    connect(findMBtn,SIGNAL(clicked()),this,SLOT(findMatch()));
    connect(findSBtn,SIGNAL(clicked()),this,SLOT(findSameLine()));
    connect(preBtn,SIGNAL(clicked()),this,SLOT(getPre()));
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(getNext()));
    connect(addBtn,SIGNAL(clicked()),this,SLOT(addEdge()));
    connect(delBtn,SIGNAL(clicked()),this,SLOT(delEdge()));
    connect(redoBtn,SIGNAL(clicked()),this,SLOT(redo()));
    connect(dispBtn,SIGNAL(clicked()),this,SLOT(disp()));
    connect(matchFBtn,SIGNAL(clicked()),this,SLOT(matchFinall()));
    connect(zinBtn,SIGNAL(clicked()),this,SLOT(zoomin()));
    connect(zoutBtn,SIGNAL(clicked()),this,SLOT(zoomout()));
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

void MainWindow::updatei()
{
    for(int i=Wid-1;i>=0;i--)
        if(wd->arr.ss[0][i]!=-1)
        {
            iEdit->setText(QString::number(wd->arr.ss[0][i]));
            nowE->setText(iEdit->text());
            break;
        }
}

void MainWindow::updateLayout()
{

    for(int i=0;i<Hei;i++)
        for(int j=0;j<Wid;j++)
        {
            arrs[i][j].setText(QString::number(wd->arr.ss[i][j]));
        }
    updatei();
}

void MainWindow::addEdge()
{
    int k=0,j=jEdit->text().toInt(),i=iEdit->text().toInt();
    wd->tp.map[k][i][j]=1;
    qDebug()<<"add "<<i<<" "<<j;
}

void MainWindow::delEdge()
{
    int k=0,j=jEdit->text().toInt(),i=iEdit->text().toInt();
    wd->tp.map[k][i][j]=0;
    qDebug()<<"del "<<i<<" "<<j;
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
    redo();
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
        QString str;
        for(int i=0;i<Hei;i++)
            for(int j=0;j<Wid;j++)
            {
                in>>str;
                wd->arr.ss[i][j]=str.toInt();
            }
    }
    updateLayout();
    wd->update();
}





void MainWindow::redo()
{
    wd->redo();
    updateLayout();
    wd->update();
    matchFBtn->setVisible(wd->tp.linev.size()==Hei);
}


void MainWindow::disp()
{
    for(int i=0;i<Hei;i++)
        for(int j=0;j<Wid;j++)
        {
            wd->arr.ss[i][j]=arrs[i][j].text().toInt();
        }
   wd->update();
}

void MainWindow::findMatch()
{
    fw=new FindWidget(this,&wd->tp);
    fw->findMatch(nowE->text().toInt(),jdisE->text().toInt());
    fw->show();
}

void MainWindow::findSameLine()
{
    fw=new FindWidget(this,&wd->tp);
    fw->findSameLine(nowE->text().toInt());
    fw->show();
}

void MainWindow::listSameLine()
{
    sw=new SameLineWidget(&wd->tp);
    sw->show();
}

void MainWindow::matchFinall()
{
    wd->tp.getFinalMap();
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(fgetNext()));
    connect(preBtn,SIGNAL(clicked()),this,SLOT(fgetPre()));
    wd->index=0;
    wd->arr.reset();
    if(wd->tp.arrv.size())
        wd->arr=wd->tp.arrv[wd->index];
    wd->update();
    updateLayout();
}

void MainWindow::fgetNext()
{
    wd->fgetNext();
    updateLayout();
}

void MainWindow::fgetPre()
{
    wd->fgetPre();
    updateLayout();
}

void MainWindow::zoomin()
{
    wd->fd+=0.3;
    wd->update();
}

void MainWindow::zoomout()
{
    wd->fd-=0.3;
    if(wd->fd<0)
        wd->fd=0;
    wd->update();
}
