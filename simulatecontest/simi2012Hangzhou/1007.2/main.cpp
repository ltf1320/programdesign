#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2000+10;
const int maxm=20000+100;
int N,M;
int level[maxn];
int fa[maxn];
int faedge[maxn];
int dfn[maxn];
int kk,ti;
bool chose[maxn];

int mabs(int a)
{
    return a>0?a:-a;
}

struct Query
{
    int a,b;
    int dl,last;
    bool operator<(const Query &q)const
    {
        if(dl==q.dl)
            return last<q.last;
        return dl<q.dl;
    }
};
Query qur[maxm];

struct EDGE
{
    int next,to;
};
EDGE edge[maxn*3];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void dfs(int now)
{
    dfn[now]=kk++;
    level[now]=ti++;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(!level[edge[i].to])
        {
            fa[edge[i].to]=now;
            faedge[edge[i].to]=i;
            dfs(edge[i].to);
        }
    }
    ti--;
}

void op(int a,int b)
{
    int xa=a,xb=b;
    while(level[xa]>level[xb])
    {
        if(fa[xa]==xb)
        {
            chose[faedge[xa]/2]=1;
            return;
        }
        if(chose[faedge[xa]/2]) return;
        xa=fa[xa];
    }
    while(level[xb]>level[xa])
    {
        if(fa[xb]==xa)
        {
            chose[faedge[xb]/2]=1;
            return;
        }
        if(chose[faedge[xb]/2]) return;
        xb=fa[xb];
    }

    while(fa[xa]!=fa[xb])
    {
        if(chose[faedge[xa]/2]) return;
        xa=fa[xa];
        if(chose[faedge[xb]/2]) return;
        xb=fa[xb];
    }
    if(dfn[b]<dfn[a])
        chose[faedge[xa]/2]=1;
    else chose[faedge[xb]/2]=1;
}

void work()
{
    fa[1]=1;
    dfs(1);
    for(int i=0; i<M; i++)
    {
        qur[i].dl=mabs(level[qur[i].a]-level[qur[i].b]);
        qur[i].last=max(dfn[qur[i].a],dfn[qur[i].b]);
    }
    sort(qur,qur+M);

    for(int i=0; i<M; i++)
    {
        op(qur[i].a,qur[i].b);
    }
    int res=0;
    for(int i=0; i<N-1; i++)
        if(chose[i])
            res++;
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
    M-=N-1;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&qur[i].a,&qur[i].b);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(level,0,sizeof(level));
    memset(chose,0,sizeof(chose));
    ti=1;
    kk=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        init();
        input();
        work();
    }
    return 0;
}
