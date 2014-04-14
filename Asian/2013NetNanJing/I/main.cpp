#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1000+100;
const int maxm=maxn*maxn;
int N,K;

struct Point
{
    int x,y;
};
Point pts[maxn];

double getDis(const Point &a,const Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct EDGE
{
    int from,to;
    double v;
    bool operator<(const EDGE &a)const
    {
        return v<a.v;
    }
};
EDGE edge[maxm];
int ent;

int fa[maxn];

int find(int a)
{
    if(a==fa[a])
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        fa[a]=b;
    }
}

void work()
{
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            edge[ent].from=i;
            edge[ent].to=j;
            edge[ent].v=getDis(pts[i],pts[j]);
            ent++;
        }
    sort(edge,edge+ent);
    double res=0;
    for(int i=1;i<ent;i++)
    {
        if(find(edge[i].from)!=find(edge[i].to))
        {
            Uni(edge[i].from,edge[i].to);
            res+=edge[i].v;
        }
    }
    printf("%.2f\n",res*K);
}

void init()
{
    ent=0;
    for(int i=0;i<N;i++)
        fa[i]=i;
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&pts[i].x,&pts[i].y);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        init();
        input();
        work();
    }
    return 0;
}
