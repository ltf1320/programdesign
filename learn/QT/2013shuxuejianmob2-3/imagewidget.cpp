#include "imagewidget.h"
#include <QPainter>
#include <QtCore>
ImageWidget::ImageWidget(QWidget *parent,QString fileName,int picNum)
    :QWidget(parent),tp(fileName,picNum)
{
    PicNum=picNum;
    arr.reset();
    lindex=0;
    arr.ss[0]=tp.linev[index];
    fd=1.0;

}

void ImageWidget:: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int x=0,y=0;
    int dx,dy;
    QImage fixImage;
    fixImage=tp.pics[arr.ss[0][0]].scaled(fd*width()/Wid,fd*height()/Hei,Qt::KeepAspectRatio);
    dx=fixImage.width();
    dy=fixImage.height();
    for(int i=0;i<Hei;i++)
    {
        for(int j=0;j<Wid;j++)
        {
            if(arr.ss[i][j]!=-1)
            {
                fixImage=tp.pics[arr.ss[i][j]].scaled(fd*width()/Wid,fd*height()/Hei,Qt::KeepAspectRatio);
                painter.drawImage(x,y,fixImage);
            }
            x+=dx;
            painter.drawLine(x,y,x,y+dy);
        }
        painter.drawLine(x,y,x+dx,y);
        y+=dy;
        x=0;
    }
}

void ImageWidget::getNext()
{
    lindex++;
    if(lindex>=tp.linev.size())
    {
        lindex=0;
        qDebug()<<"end";
    }
    arr.reset();
    arr.ss[0]=tp.linev[lindex];
    update();
}

void ImageWidget::getPre()
{
    lindex--;
    if(lindex<0)
        lindex=tp.linev.size()-1;
    arr.reset();
    arr.ss[0]=tp.linev[lindex];
    update();
}

void ImageWidget::fgetNext()
{
    index++;
    if(index>=tp.arrv.size())
    {
        index=0;
        qDebug()<<"end";
    }
    arr=tp.arrv[index];
    update();
}

void ImageWidget::fgetPre()
{
    index--;
    if(index<0)
        index=tp.arrv.size()-1;
    arr.reset();
    arr=tp.arrv[index];
    update();
}


void ImageWidget::redo()
{
    arr.reset();
    tp.findLines();
    if(lindex>tp.linev.size()-1)
        lindex=tp.linev.size()-1;
    arr.ss[0]=tp.linev[lindex];
}
