#ifndef UNIONFIND_H
#define UNIONFIND_H
#include "b2.h"
#include <QList>
class UnionFind
{
public:
    UnionFind();
    int fa[MaxPicNum];
    void init();
    int find(int a);
    void Union(int a,int b);
    QList<int> getUnioned();
};

#endif // UNIONFIND_H
