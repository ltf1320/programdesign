#include "imagewidget.h"
#include <QPainter>
#include <QFile>
#include <QTextStream>
ImageWidget::ImageWidget(QWidget *parent,QString fileName,int picNum)
    :QWidget(parent),tp(fileName,picNum)
{
    PicNum=picNum;
    arr=tp.arrv.front();
    QFile file("d:/a1-2ans");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    for(int i=0;i<19;i++)
        out<<arr.ss[i]<<" ";

}

void ImageWidget:: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int x=0;
    for(int i=0;i<=PicNum;i++)
    {
        QImage fitImage=tp.pics[arr.ss[i]].scaled(width(),height(),Qt::KeepAspectRatio);
        painter.drawImage(x,0,fitImage);
        x+=fitImage.width();
    }
}
