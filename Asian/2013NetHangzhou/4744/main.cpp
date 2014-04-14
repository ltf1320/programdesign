#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=300;
const int maxm=maxn*maxn;
const int inf=0x3f3f3f3f;
int N;

struct EDGE
{
    int from,to,cap,cost,next;
};
EDGE edge[maxm];
int box[maxn];
int ent;

int flow[maxn];

struct Node
{
    int x,y,z,w;
};
Node nds[maxn];
int getDis(Node &a,Node &b)
{
    return (int)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

void _add(int f,int t,int cap,int cost)
{
    edge[ent].from=f;
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

void Add(int f,int t,int l,int r,int cost)
{
    add(f,t,r-l,cost);
    flow[f]-=l;
    flow[t]+=l;
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

void work()
{
    for(int i=0;i<N;i++)
    {
        Add(2+2*i,2+2*i+1,nds[i].w,nds[i].w,0);
        for(int j=0;j<N;j++)
        {
            if(i==j) continue;
            Add(2+2*i+1,2+2*j,0,inf,getDis(nds[i],nds[j]));
        }
    }
    for(int i=2;i<2+2*N;i++)
    {
        if(flow[i]>0)
            add(0,i,flow[i],0);
        else if(flow[i]<0)
            add(i,1,-flow[i],0);
    }
    int res=fyl(0,1);
    for(int i=box[0];i!=-1;i=edge[i].next)
    {
        if(edge[i].cap)
        {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&nds[i].x,&nds[i].y,&nds[i].z,&nds[i].w);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(flow,0,sizeof(flow));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        init();
        input();
        work();
    }
    return 0;
}
