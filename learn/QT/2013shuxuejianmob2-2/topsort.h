#ifndef TOPSORT_H
#define TOPSORT_H

#include <QImage>
#include <QList>
#include "arrange.h"
#include "b2.h"


class topSort
{
public:
    topSort(QString afileName,int picNum);
    QImage pics[MaxPicNum+1];
    int PicNum;
    bool judges[MaxPicNum+1][4];
    QString fileName;
    QList<Arrange> arrv;
    Arrange nArr;
    bool Wcompare(const QImage &a, const QImage &b, int err);
    bool Hcompare(const QImage &a, const QImage &b, int err);
    bool judgeWStart(const QImage &a);
    bool judgeWEnd(const QImage &a);
    bool judgeHStart(const QImage &a);
    bool judgeHEnd(const QImage &a);

    int map[2][MaxPicNum+1][MaxPicNum+1];
    void getMap();

    void dosort();

    bool pvis[MaxPicNum+1];
    void getPieces();
    void dfs(int picno,int i,int j);


};

#endif // TOPSORT_H
