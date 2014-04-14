#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10000+100;
const int maxm=500000+100;
const int maxp=100000+100;
int N,M,P;
int fa[maxn];
int num[maxn];

int find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}
int nres;
void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        fa[a]=b;
        nres-=num[a]*num[b]*2;
        num[b]+=num[a];
    }
}


struct EDGE
{
    int a,b,c;
    bool operator<(const EDGE &p)const
    {
        return c<p.c;
    }
};
EDGE edge[maxm];

int res[maxp];

struct GUE
{
    int id;
    int t;
    GUE(int i,int nn):id(i),t(nn){}
    GUE(){}
    bool operator<(const GUE &a)const
    {
        return t<a.t;
    }
};
GUE gues[maxp];

void work()
{
    sort(edge,edge+M);
    sort(gues,gues+P);
    int p=0;
    nres=N*(N-1);
    for(int i=0;i<P;i++)
    {
        while(edge[p].c<gues[i].t&&p<M)
        {
            Uni(edge[p].a,edge[p].b);
            p++;
        }
        res[gues[i].id]=nres;
    }
    for(int i=0;i<P;i++)
        printf("%d\n",res[i]);
}

void input()
{
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    }
    scanf("%d",&P);
    for(int i=0;i<P;i++)
    {
        gues[i].id=i;
        scanf("%d",&gues[i].t);
    }
}

void init()
{
    for(int i=0;i<N;i++)
    {
        fa[i]=i;
        num[i]=1;
    }
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
