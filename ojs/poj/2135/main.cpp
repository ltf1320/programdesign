#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=2000+100;
const int maxm=10000+100;
const int inf=0x3f3f3f3f;

int N,M;

struct EDGE
{
    int from,to,next,cap,cost;
};
EDGE edge[4*maxm];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].to=t;
    edge[ent].from=f;
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

int in[maxn];
int dis[maxn];
int from[maxn];
queue<int> que;

bool spfa(int f,int t)
{
    int now;
    for(int i=0; i<2*N+2; i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push(f);
    in[f]=1;
    dis[f]=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(edge[i].cap&&dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                dis[edge[i].to]=dis[now]+edge[i].cost;
                from[edge[i].to]=i;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return 0;
    return dis[t];
}

int fyl(int f,int t)
{
    int cost=0;
    int mincap;
    while(spfa(f,t))
    {
        mincap=inf;
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[t]*mincap;
    }
    return cost;
}

void input()
{
    add(0,2,2,0);
    add(2*N+1,1,2,0);
    for(int i=1; i<=N; i++)
        add(2*i,2*i+1,inf,0);
    int f,t,c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d",&f,&t,&c);
        add(2*f+1,2*t,1,c);
        add(2*t+1,2*f,1,c);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        printf("%d\n",fyl(0,1));
    }
    return 0;
}
