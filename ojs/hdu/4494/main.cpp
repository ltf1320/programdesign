#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define p2(x) ((x)*(x))
using namespace std;
const int maxn=1000+10;
const int maxm=maxn*100;
const int inf=0x3f3f3f3f;
int N,M;
int NN;
int need[maxn][10];
int begtime[maxn],endtime[maxn];
struct Point
{
    int x,y;
};
Point pts[maxn];
Point depot;
int getDis(Point &a,Point &b)
{
    return ceil(sqrt(p2(a.x-b.x)+p2(a.y-b.y)));
}

struct EDGE
{
    int next,to,cap,cost;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].to=t;
    edge[ent].cap=cap;
    edge[ent].cost=cost;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap,int cost)
{
    _add(f,t,cap,cost);
    _add(t,f,0,-cost);
}

bool vis[maxn];
int cost,ans;
int T=1;
int aug(int u, int f)//dinic
{
    if(u == T)
    {
        ans += cost * f;
        return f;
    }
    vis[u] = 1;
    int tmp = f;
    for(int i = box[u]; i != -1; i = edge[i].next)
        if(edge[i].cap &&!edge[i].cost && !vis[edge[i].to])//当前cost为0 才可以走
        {
            int delta = aug(edge[i].to, tmp < edge[i].cap ? tmp : edge[i].cap);
            edge[i].cap -= delta;
            edge[i^1].cap += delta;
            tmp -= delta;
            if(!tmp) return f;
        }
    return f - tmp;
}
bool modlabel()
{
    int delta = inf;
    for(int u = 0; u < NN; u++)//找最小可增广费用
        if(vis[u])
            for(int i = box[u]; i != -1; i = edge[i].next)
                if(edge[i].cap && !vis[edge[i].to] && edge[i].cost < delta)
                    delta = edge[i].cost;
    if(delta == inf) return false;
    for(int u = 0; u < NN; u++)
        if(vis[u])
            for(int i = box[u]; i != -1; i = edge[i].next)//对于两个点都在里面的，正向修改一次，反向修改一次，即没修改
                edge[i].cost -= delta, edge[i^1].cost += delta;
    cost += delta;
    return true;
}
void costflow(int s,int t)
{
    T=t;
    cost=0;
    do
    {
        do
        {
            memset(vis, 0, sizeof(vis));
        }
        while(aug(s, inf));
    }
    while(modlabel());
}

void work()
{
    for(int i=0;i<M;i++)
    {
        add(0,i+2,inf,1);
    }
    for(int i=0; i<N; i++)
    {
        for(int j=1;j<N;j++)
        {
            if(i==j) continue;
            if(endtime[i]+getDis(pts[i],pts[j])<=begtime[j])
            {
                for(int k=0;k<M;k++)
                    add(i*M+k+2,j*M+k+2,inf,0);
            }
        }
    }
    for(int i=1;i<N;i++)
        for(int j=0;j<M;j++)
            add(i*M+j+2,1,need[i][j],0);
    costflow(0,1);
    printf("%d\n",ans);
}

void input()
{
    scanf("%d%d",&N,&M);
    NN=N*M+2;
    scanf("%d%d",&depot.x,&depot.y);
    begtime[0]=inf;
    endtime[0]=0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d",&pts[i].x,&pts[i].y);
        scanf("%d%d",&begtime[i],&endtime[i]);
        for(int j=0;j<M;j++)
            scanf("%d",&need[i][j]);
        endtime[i]+=begtime[i];
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    cost=0;
    ans=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        work();
    }
    return 0;
}
