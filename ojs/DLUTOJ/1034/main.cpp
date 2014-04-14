#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000+10;
const int maxm=100000+100;
int N,M;
int fa[maxn];
int suml,sumc;

struct EDGE
{
    int from,to,l,c;
    bool operator<(const EDGE &a)const
    {
        if(l==a.l) return c<a.c;
        return l<a.l;
    }
};
EDGE edge[maxm];
int find(int a)
{
    if(fa[a]==a) return fa[a];
    else return fa[a]=find(fa[a]);
}

void Union(int a,int b)
{
    fa[a]=b;
}

void kruscal()
{
    sort(edge,edge+M);
    suml=sumc=0;
    int tt=0;
    for(int i=0;i<M;i++)
    {
        if(find(edge[i].from)==find(edge[i].to))
            continue;
        Union(edge[i].from,edge[i].to);
        suml+=edge[i].l;
        sumc+=edge[i].c;
        tt++;
        if(tt==N-1) return;
    }
    suml=sumc=-1;
}

void input()
{
    for(int i=0;i<=N;i++)
        fa[i]=i;
    for(int i=0;i<M;i++)
        scanf("%d%d%d%d",&edge[i].from,&edge[i].to,&edge[i].l,&edge[i].c);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        kruscal();
        printf("%d %d\n",suml,sumc);
    }
    return 0;
}
