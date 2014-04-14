#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H
#include <QWidget>
#include <QImage>
#include "topsort.h"
class ImageWidget :public QWidget
{
public:
    explicit ImageWidget(QWidget* parent,QString fileName,int picNum);
    void paintEvent(QPaintEvent *event);
private:
    topSort tp;
    Arrange arr;
    int PicNum;
};

#endif // IMAGEWIDGET_H
