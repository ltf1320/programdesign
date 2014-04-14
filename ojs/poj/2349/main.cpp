#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=500+10;
const int Inf=0x3f3f3f3f;


int s,p,ub;
int used[maxn*maxn];  //记录用了的边的编号（排序后的）
int father[maxn];//并查集找是否存在环路


struct Point
{
    int x,y;
};
Point pnt[maxn];

struct EDGE
{
    int u,v;
    double dis;
    void getdis()
    {
        dis=sqrt(0.0+(pnt[u].x-pnt[v].x)*(pnt[u].x-pnt[v].x)+(pnt[v].y-pnt[u].y)*(pnt[v].y-pnt[u].y));
    }
    bool operator<(const EDGE &a)const
    {
        return dis<a.dis;
    }
};
EDGE edge[maxn*maxn];


int ent;
void add(int a,int b)
{
    edge[ent].u=a;
    edge[ent].v=b;
    edge[ent++].getdis();
}

int find(int a)
{
    while(father[a]!=a)
        a=father[a];
    return a;
}

void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    father[a]=b;
}

void init()
{
    for(int i=0; i<p; ++i)
        father[i]=i;
    ent=0;
}

void kruskal()
{
    sort(edge,edge+ent);
    ub=0;
    for(int i=0; i<ent; ++i)
    {
        if(find(edge[i].u)==find(edge[i].v))
            continue;
        Uni(edge[i].u,edge[i].v);
        used[ub++]=i;
        if(ub==p-1) break;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&s,&p);
        init();
        for(int i=0; i<p; ++i)
        {
            scanf("%d%d",&x,&y);
            pnt[i].x=x;
            pnt[i].y=y;
            for(int j=0; j<i; ++j)
                add(i,j);
        }
        kruskal();
        printf("%.2f\n",edge[used[p-s-1]].dis);
    }
    return 0;
}
