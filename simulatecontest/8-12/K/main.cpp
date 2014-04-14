#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=60;
const int maxm=maxn*maxn;
int N;
int fa[maxn];

int find(int a)
{
    if(fa[a]==a) return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

struct EDGE
{
    int from,to;
    bool used;
    double v;
    bool operator<(const EDGE &a) const
    {
        if(used==a.used)
            return v<a.v;
        else return used;
    }
};
EDGE edge[maxm];
int ent;

struct Node
{
    int x,y;
};
Node nds[maxn];

double getDis(int i,int j)
{
    return sqrt((0.0+nds[i].x-nds[j].x)*(0.0+nds[i].x-nds[j].x)+(0.0+nds[i].y-nds[j].y)*(0.0+nds[i].y-nds[j].y));
}

void input()
{
    int An,Nn;
    int x;
    scanf("%d%d",&An,&Nn);
    fa[An]=Nn;
    if(An>Nn)
    {
        x=An;
        An=Nn;
        Nn=x;
    }
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&nds[i].x,&nds[i].y);
    }
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        {
            edge[ent].from=i;
            edge[ent].to=j;
            edge[ent].v=getDis(i,j);
            if(i==An&&j==Nn)
                edge[ent].used=1;
            else edge[ent].used=0;
            ent++;
        }
    sort(edge,edge+ent);
}

void work()
{
    int e=1;
    for(int i=0;i<N-2;i++)
    {
        while(find(edge[e].from)==find(edge[e].to))
            e++;
        edge[e].used=1;
        fa[edge[e].from]=edge[e].to;
    }
    double res=0.0;
    for(int i=0;i<ent;i++)
        if(edge[i].used)
            res+=edge[i].v;
    printf("%.2f\n",res);
}

void init()
{
    ent=0;
    for(int i=0;i<maxn;i++)
        fa[i]=i;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        init();
        input();
        work();
    }
    return 0;
}
