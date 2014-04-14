#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H
#include "b2.h"
#include <QWidget>
#include <QImage>
#include <QPushButton>
#include "topsort.h"
class ImageWidget :public QWidget
{
public:
    explicit ImageWidget(QWidget* parent,QString fileName,int picNum);
    void paintEvent(QPaintEvent *event);

    topSort tp;
    Arrange arr;
    int PicNum;
    int index;
    void redo();
public:
    void getNext();
    void getPre();
};

#endif // IMAGEWIDGET_H
