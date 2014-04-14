#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include "graph.h"
#include "factory.h"
#include "QMouseEvent"
#include "QKeyEvent"
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QFileDevice>
#include <QFileDialog>
class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
    Graphs graph;
    QPointF mouseStartPoint;
    Graphs chosedGraphs;
    Graphs *nowGraph;
    bool bemoving;
    bool iscopying;
    bool ctrlpressed;
    enum State
    {
        St_ChoseAndMove,
        St_DrawLine,
        St_DrawEllipse,
        St_DrawRec
    };
    State nowst;
signals:
    
public slots:
    void changeState(State st);
    void combine();
    void split();
    void save();
    void read();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // IMAGEWIDGET_H
