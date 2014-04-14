#ifndef FACTORY_H
#define FACTORY_H

#include "graph.h"
/*
 抽象工厂模式
*/


class Factory
{
private:
    Factory();
public :
    static Graphs* createGraphs();
    static Graphs* createGraphs(Graphs &gr);
    static Graphs* createGraphs(Graphs *gr);
    static Line* createLine(QPointF a,QPointF b);
    static Rectangle* createRectangle(QPointF a,QPointF b);
    static Ellipse* createEllipse(QPointF center,qreal rx,qreal ry);
};

#endif // FACTORY_H
