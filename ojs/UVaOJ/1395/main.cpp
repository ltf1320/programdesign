#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
const int maxm=maxn*maxn;
int N,M;
struct EDGE
{
    int from,to,v;
    bool operator<(const EDGE &e)const
    {
        return v<e.v;
    }
};
EDGE edge[maxm];

int fa[maxn];

int find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

void work()
{
    int a,b,mx;
    int res=inf;
    int ent;
    if(M<N-1)
    {
        printf("-1\n");
        return;
    }
    sort(edge,edge+M);
    for(int e=0;e<M;e++)
    {
        for(int i=1;i<=N;i++)
            fa[i]=i;
        ent=0;mx=0;
        for(int i=e;i<M;i++)
        {
            a=find(edge[i].from);
            b=find(edge[i].to);
            if(a!=b)
            {
                fa[a]=b;
                mx=max(mx,edge[i].v);
                ent++;
            }
            if(ent==N-1)
                break;
        }
        if(ent==N-1)
            res=min(res,mx-edge[e].v);
    }
    if(res==inf)
        puts("-1");
    else
       printf("%d\n",res);
}

void input()
{
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].v);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==M&&N==0) break;
        input();
        work();
    }
    return 0;
}
