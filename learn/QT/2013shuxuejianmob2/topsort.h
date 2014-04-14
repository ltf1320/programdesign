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
    bool Wcompare(const QImage &a, const QImage &b, int err);
    bool Hcompare(const QImage &a, const QImage &b, int err);
    void getMap();
    void dosort(int i, int j);
    int map[2][MaxPicNum+1][MaxPicNum+1];
    bool vis[MaxPicNum+1];
    int indu[MaxPicNum+1];
    bool judgeWStart(const QImage &a);
    bool judgeWEnd(const QImage &a);
    bool judgeHStart(const QImage &a);
    bool judgeHEnd(const QImage &a);
    int PicNum;
    int Hei,Wid;
    bool judges[MaxPicNum+1];
    QString fileName;
};

#endif // TOPSORT_H
