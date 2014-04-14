#ifndef SAMELINEWIDGET_H
#define SAMELINEWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <arrange.h>
#include <QList>
#include <QPainter>
#include "topsort.h"
#include "ui_SameLineWidget.h"
class SameLineWidget :
        public QMainWindow
        ,public Ui_SameLineWidget
{
    Q_OBJECT
public:
    explicit SameLineWidget(topSort * tp,QWidget *parent = 0);
    QList<QList<LineArrange> > lst;
    topSort *tp;
    int index;
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    void getNext();
    void getPre();
};


#endif // SAMELINEWIDGET_H
