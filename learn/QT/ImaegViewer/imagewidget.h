#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QPainter>
#include <QMimeData>
#include <QDragEnterEvent>
class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);

    void setPixMap(QString fileName);
    QPixmap getPixmap();
    void setAngle(qreal rotateAngle);
    void setbFit(bool fit);
    void setASize();
    bool bLarge();
    bool bSmall();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap pixmap;
    qreal angle;
    bool bFit;
    qreal scale;
    
public slots:
    
};

#endif // IMAGEWIDGET_H
