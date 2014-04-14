#ifndef TOPSORT_H
#define TOPSORT_H

#include <QImage>
#include <QList>
#include "arrange.h"



class topSort
{
public:
    topSort(QString afileName,int picNum);
    QImage pics[MaxPicNum+1];
    QList<Arrange> arrv;
    Arrange nArr;
    bool compare(const QImage &a, const QImage &b, int err);
    void getMap();
    void dosort(int n);
    int map[MaxPicNum+1][MaxPicNum+1];
    bool vis[MaxPicNum+1];
    int indu[MaxPicNum+1];
    bool judgeStart(const QImage &a);
    bool judgeEnd(const QImage &a);
    int PicNum;
    QString fileName;
};

#endif // TOPSORT_H
