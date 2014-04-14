#include "factory.h"

Factory::Factory()
{

}

Graphs* Factory::createGraphs()
{
    return new Graphs();
}

Graphs* Factory::createGraphs(Graphs &gr)
{
    return (Graphs*)gr.clone();
}

 Line* Factory::createLine(QPointF a, QPointF b)
{
    return new Line(a,b);
}

 Rectangle* Factory::createRectangle(QPointF a,QPointF b)
 {
     return new Rectangle(a,b);
 }

 Ellipse* Factory::createEllipse(QPointF center,qreal rx,qreal ry)
 {
     return new Ellipse(center,rx,ry);
 }

 Graphs* Factory::createGraphs(Graphs *gr)
 {
     return (Graphs*)gr->clone();
 }

