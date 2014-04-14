#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1000+10;
int N,M;

struct Point
{
    int x,y;
};
Point pnt[maxn];

double getDis(const Point &a,const Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

struct EDGE
{
    int from,to;
    double dis;
    bool operator<(const EDGE &a)const
    {
        return dis<a.dis;
    }
};
EDGE edge[maxn*maxn];
int ent;

int fa[maxn];

int find(int a)
{
    if(fa[a]==a) return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

double res;
void kruscal()
{
    sort(edge,edge+ent);
    for(int i=0;i<ent;i++)
    {
        if(find(edge[i].from)!=find(edge[i].to))
        {
            res+=edge[i].dis;
            fa[find(edge[i].from)]=find(edge[i].to);
        }
    }
}

void work()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            edge[ent].from=i;
            edge[ent].to=j;
            edge[ent].dis=getDis(pnt[i],pnt[j]);
            ent++;
        }
    res=0;
    kruscal();
    printf("%.2f\n",res);
}

void input()
{
    for(int i=1;i<=N;i++)
        scanf("%d%d",&pnt[i].x,&pnt[i].y);
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        f=find(f);
        t=find(t);
        if(f!=t)
        {
            fa[f]=t;
        }
    }
}

void init()
{
    ent=0;
    for(int i=0;i<=N;i++)
        fa[i]=i;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
