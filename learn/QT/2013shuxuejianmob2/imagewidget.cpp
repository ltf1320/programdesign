#include "imagewidget.h"
#include <QPainter>
#include <QtCore>
ImageWidget::ImageWidget(QWidget *parent,QString fileName,int picNum)
    :QWidget(parent),tp(fileName,picNum)
{
    PicNum=picNum;
    int kn=0;
    for(int i=0;i<tp.Hei;i++)
        for(int j=0;j<tp.Wid;j++)
            arr.ss[i][j]=kn++;
    if(tp.arrv.size()>0)
    {
        qDebug()<<"YES";
        arr=tp.arrv.front();
    }
}

void ImageWidget:: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int x=0,y=0;
    QImage fixImage;
    int fd=3;
    for(int i=0;i<tp.Hei;i++)
    {
        for(int j=0;j<tp.Wid;j++)
        {
            fixImage=tp.pics[arr.ss[i][j]].scaled(fd*width()/tp.Wid,fd*height()/tp.Hei,Qt::KeepAspectRatio);
            painter.drawImage(x,y,fixImage);
            x+=fixImage.width();
        }
        y+=fixImage.height();
        x=0;
    }
}
