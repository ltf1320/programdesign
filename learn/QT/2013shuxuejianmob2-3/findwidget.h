#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>
#include "b2.h"
#include "topsort.h"
#include <QList>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include "ui_findWidget.h"
#include <QDialog>
#include <QPainter>
#include "picnode.h"
#include "mainwindow.h"

class FindWidget : public QWidget,public Ui_findWidget
{
    Q_OBJECT
public:
    explicit FindWidget(MainWindow *mw,topSort *tp, QWidget *parent = 0);
    QList<picNode> lst;
    int index;
    topSort *tp;
    void paintEvent(QPaintEvent *event);
    MainWindow *mw;
    void updatej();

    void findMatch(int now,int dis);
    void findSameLine(int now);

private:


signals:
    
public slots:
    void getNext();
    void getPre();
};

#endif // FINDWIDGET_H
