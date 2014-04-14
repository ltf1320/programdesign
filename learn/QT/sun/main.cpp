#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <cmath>
#include <QOpenGLBuffer>
#include <QtOpenGL/QGLWidget>
const qreal PI=3.14159265;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsEllipseItem *sun=new QGraphicsEllipseItem(0,0,20,20);
    sun->setBrush(Qt::red);
    sun->setPen(QPen(Qt::red));

    QTimeLine *timeline=new QTimeLine(10000);
    timeline->setCurveShape(QTimeLine::LinearCurve);

    QGraphicsItemAnimation *animation=new QGraphicsItemAnimation;
    animation->setItem(sun);
    animation->setTimeLine(timeline);

    qreal x,y;
    qreal angle=PI;
    for(int i=0;i<=180;++i)
    {
        x=200.0*cos(angle);
        y=200.0*sin(angle);
        animation->setPosAt(i/180.0,QPointF(x,y));
        angle+=PI/180.0;
    }

    QGraphicsScene *scene=new QGraphicsScene();
    scene->addItem(sun);

    QGraphicsView *view=new QGraphicsView(scene);
    view->resize(640,480);
    view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    view->show();

    timeline->start();
    return a.exec();

    return a.exec();
}
