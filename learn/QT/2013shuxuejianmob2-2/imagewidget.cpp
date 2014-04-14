#include "imagewidget.h"
#include <QPainter>
#include <QtCore>
ImageWidget::ImageWidget(QWidget *parent,QString fileName,int picNum)
    :QWidget(parent),tp(fileName,picNum)
{
    PicNum=picNum;
    int kn=0;
    for(int i=0;i<Hei;i++)
        for(int j=0;j<Wid;j++)
            arr.ss[i][j]=kn++;
    index=0;
    arr=tp.arrv[index];
}

void ImageWidget:: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int x=0,y=0;
    int dx,dy;
    QImage fixImage;
    int fd=3;
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
        }
        y+=dy;
        x=0;
    }
}

void ImageWidget::getNext()
{
    index++;
    if(index>=tp.arrv.size())
        index=0;
    arr=tp.arrv[index];
    update();
}

void ImageWidget::getPre()
{
    index--;
    if(index<0)
        index=tp.arrv.size()-1;
    arr=tp.arrv[index];
    update();
}


void ImageWidget::redo()
{
    int kn=0;
    for(int i=0;i<Hei;i++)
        for(int j=0;j<Wid;j++)
            arr.ss[i][j]=kn++;
    tp.dosort();
    index=0;
    arr=tp.arrv[index];
}
