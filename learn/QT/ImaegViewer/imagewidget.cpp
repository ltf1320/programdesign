#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
 //   QDesktopWidget desktop;
 //   pixmap=QPixmap(desktop.width(),desktop.height());
    pixmap=QPixmap(parent->width(),parent->height());
    scale=1;
    angle=0;
    bFit=true;
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(angle)
    {
        QPointF center(width()/2.0,height()/2.0);
        painter.translate(center);
        painter.rotate(angle);
        painter.translate(-center);
    }
    if(bFit)
    {
        QPixmap fitPixmap=pixmap.scaled(width(),height(),Qt::KeepAspectRatio);
        painter.drawPixmap(0,0,fitPixmap);
    }
    else
    {
        resize(pixmap.size());
        painter.drawPixmap(0,0,pixmap);
    }
}

void ImageWidget::setPixMap(QString fileName)
{
    pixmap.load(fileName);
    update();
}

QPixmap ImageWidget::getPixmap()
{
    return pixmap;
}

void ImageWidget::setAngle(qreal rotateAngle)
{
    angle+=rotateAngle;
    update();
}

void ImageWidget::setbFit(bool fit)
{
    scale=1;
    bFit=fit;
    update();
}

void ImageWidget::setASize()
{
    setbFit(false);
}

bool ImageWidget::bLarge()
{
    if(scale>=3.0) return false;
    scale*=1.25;
    resize(size()*scale);
    update();
    return scale<3.0;
}

bool ImageWidget::bSmall()
{
    if(scale<=0.3333) return false;
    scale*=0.8;
    resize(size()*scale);
    update();
    return scale>0.3333;
}










