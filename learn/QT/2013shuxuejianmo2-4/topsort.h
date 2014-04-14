#ifndef TOPSORT_H
#define TOPSORT_H

#include <QImage>
#include <QList>
#include "arrange.h"
#include "b2.h"
#include "picnode.h"
#include <algorithm>

class topSort
{
public:
    int jdis;
    int err;
    int ldis;
    void resetJdisErr();

    topSort(QString afileName,int picNum);
    QImage pics[MaxPicNum+1];
    int PicNum;
    bool judges[MaxPicNum+1][4];
    QString fileName;

    QList<Arrange> arrv;
    Arrange nArr;

    QList<LineArrange> linev;
    LineArrange nline;

    int fmap[MaxPicNum+1][MaxPicNum+1];
    bool fvis[MaxPicNum+1];
    bool judgeWLine(LineArrange &a, LineArrange &b);
    bool judgeWLineStart(LineArrange &a);
    bool judgeWLineEnd(LineArrange &b);
    void ftopSort(int now,int x);
    void getFinalMap();

    int Wcompare(const QImage &a, const QImage &b);
    int Hcompare(const QImage &a, const QImage &b);
    bool judgeHqy(const QImage &a, int x, int i);
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
    int indu[MaxPicNum+1];
    void findLine(int picno,int x);
    void findLines();

    //
    static const int maxn=1000;
    int z[maxn][maxn];
    int tt[210];
    int pp[210][5];
    int pp2[210][5];
    void preJudgeLine();
    bool judgeLine(int a,int b);

    //
    QList<picNode> findMatch(int now,int dis);
    QList<picNode> findSameLine(int now);

    //
    QList<QList<LineArrange> > listSameLine();
};

#endif // TOPSORT_H
