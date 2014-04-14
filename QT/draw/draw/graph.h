#ifndef GRAPH_H
#define GRAPH_H
#include "QVector"
#include "QPoint"
#include "QPainter"
#include "qmath.h"
#include <iostream>
#include <QDebug>

#define p2(x) ((x)*(x))
const qreal derr=10;
const qreal eps=1E-7;



class Graph
{
public:
    enum TypeId
    {
        TGraphs,
        TLine,
        TEllipse,
        TRectangle
    };
    virtual bool isFit(const QPointF &pt)=0;
    virtual void paint(QPainter &painter)=0;
    virtual void move(const QPointF &v)=0;
    virtual bool operator==(Graph* gr)=0;
    virtual int getTypeId()=0;
    virtual void save(QDataStream &stream)=0;
    virtual void read(QDataStream &stream)=0;
    virtual ~Graph();
    virtual Graph* clone()=0;
    static qreal getDis(const QPointF &a,const QPointF &b)
    {
        return sqrt(p2(a.x()-b.x())+p2(a.y()-b.y()));
    }
};

class Graphs:public Graph
{
private:
    const static int typeId=TGraphs;
    QVector<Graph*> son;
public:
    virtual void paint(QPainter &painter);
    virtual bool isFit(const QPointF &pt);
    virtual void move(const QPointF &v);
    virtual bool operator==(Graph* gr);
    virtual int getTypeId();
    virtual void save(QDataStream &stream);
    virtual void read(QDataStream &stream);
    bool empty();
    bool contains(Graph *gr);
    void push_back(Graph *gr);
    void remove(Graphs &grs);
    void clear();
    int size();
    virtual Graph* clone();
    virtual ~Graphs();
    class iterator//迭代器定义
    {
    private:
        iterator(Graphs *f);
        Graphs* fa;
        int index;
    public:
        void operator++(int);
        void  operator++();
        Graph* operator*();
        bool operator==(iterator a);
        bool operator!=(iterator a);
        friend class Graphs;
    };
    iterator begin();
    iterator end();
    void remove(iterator iter);
    iterator find(Graph *gr);
};


class Line :public Graph
{
    const static int typeId=TLine;
    QPointF a,b;
public:
    Line(){}
    qreal calDis(const QPointF &pt);
    Line(QPointF aa,QPointF bb):a(aa),b(bb){}
    virtual bool isFit(const QPointF &pt);
    virtual void paint(QPainter &painter);
    virtual void move(const QPointF &v);
    virtual bool operator==(Graph* gr);
    virtual void save(QDataStream &stream);
    virtual void read(QDataStream &stream);
    virtual int getTypeId();
    virtual ~Line();
    virtual Graph* clone();
};

class Rectangle:public Graph
{
    const static int typeId=TRectangle;
private:
    QPointF a,b;//topleft,bottomright
public:
    Rectangle(){}
    qreal calDis(const QPointF &pt);
    Rectangle(QPointF aa,QPointF bb);
    virtual bool isFit(const QPointF &pt);
    virtual void paint(QPainter &painter);
    virtual void move(const QPointF &v);
    virtual bool operator==(Graph* gr);
    virtual void save(QDataStream &stream);
    virtual void read(QDataStream &stream);
    virtual int getTypeId();
    virtual ~Rectangle();
    virtual Graph* clone();
};

class Ellipse:public Graph
{
private:
    const static int typeId=TEllipse;
    QPointF center;
    qreal rx,ry;
public:
    Ellipse(){}
    Ellipse(QPointF center, qreal rx, qreal ry);
    qreal calDis(const QPointF &pt);
    virtual bool isFit(const QPointF &pt);
    virtual void paint(QPainter &painter);
    virtual void move(const QPointF &v);
    virtual bool operator==(Graph* gr);
    virtual void save(QDataStream &stream);
    virtual void read(QDataStream &stream);
    virtual int getTypeId();
    virtual ~Ellipse();
    virtual Graph* clone();
};


#endif // GRAPH_H
