#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=200000+100;
int N;
int fa[maxn];
int num[maxn];
LL sum[maxn];

int find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

struct EDGE
{
    int f,t,c;
    bool operator<(const EDGE &e)const
    {
        return c>e.c;
    }
};
EDGE edge[maxn];

void work()
{
    sort(edge,edge+N-1);
    int a,b;
    for(int i=0;i<N-1;i++)
    {
        a=find(edge[i].f);
        b=find(edge[i].t);
        fa[b]=a;
        sum[a]=max(sum[a]+(LL)edge[i].c*num[b],sum[b]+(LL)edge[i].c*num[a]);
        num[a]=num[a]+num[b];
    }
    printf("%I64d\n",sum[find(1)]);
}

void input()
{
    for(int i=0;i<N-1;i++)
        scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].c);
}

void init()
{
    for(int i=1;i<=N;i++)
    {
        fa[i]=i;
        num[i]=1;
        sum[i]=0;
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
