#include "unionfind.h"

UnionFind::UnionFind()
{
    init();
}

void UnionFind::init()
{
    for(int i=0;i<MaxPicNum;i++)
        fa[i]=i;
}

int UnionFind::find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

void UnionFind::Union(int a,int b)
{
    a=find(a);b=find(b);
    fa[a]=b;
}

QList<int> UnionFind::getUnioned()
{
    bool used[MaxPicNum+1];
    memset(used,0,sizeof(used));
    for(int i=0;i<MaxPicNum;i++)
        if(fa[i]!=i)
            used[fa[i]]=1;
    QList<int> res;
    for(int i=0;i<MaxPicNum;i++)
        if(used[i])
            res.push_back(i);
    return res;
}
