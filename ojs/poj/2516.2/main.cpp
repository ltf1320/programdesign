#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=50+10;
const int maxn=2*MAXN+MAXN;
const int maxm=5000;
const int inf=0x3f3f3f3f;
int N,M,K;

int need[MAXN][MAXN]; //k,n
int has[MAXN][MAXN]; //k,m
int cost[MAXN][MAXN][MAXN]; //k,n,m

struct EDGE
{
    int from,to,next,cap,cost;
};
EDGE edge[maxm];
int box[maxn];
int ent;

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

int dis[maxn];
bool in[maxn];
int from[maxn];
queue<int> que;

bool spfa(int f,int t)
{
    for(int i=0;i<maxn;i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push(f);
    dis[f]=0;
    in[f]=1;
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
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
    if(dis[t]==inf) return false;
    else return true;
}



int getNCode(int n)
{
    return n+2;
}

int getMCode(int m)
{
    return m+N+2;
}

void input()
{
    //need
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            scanf("%d",&need[j][i]);
        }
    }
    //has
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<K;j++)
        {
            scanf("%d",&has[j][i]);
        }
    }
    //cost
    for(int k=0;k<K;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                scanf("%d",&cost[k][i][j]);
            }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

bool isNeedFed()
{
    for(int i=box[0];i!=-1;i=edge[i].next)
        if(edge[i].cap) return false;
    return true;
}

int fyl()
{
    int cost=0;
    int mincap;
    //0:S,1:T
    while(spfa(0,1))
    {
        mincap=inf;
        for(int i=from[1];i!=-1;i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[1];i!=-1;i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[1]*mincap;
    }
    if(isNeedFed())
        return cost;
    return -1;
}

int work()
{
    int res=0,tmp;
    for(int k=0;k<K;k++)
    {
        init();
        for(int i=0;i<N;i++)
            add(0,getNCode(i),need[k][i],0);
        for(int i=0;i<M;i++)
            add(getMCode(i),1,has[k][i],0);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                add(getNCode(i),getMCode(j),inf,cost[k][i][j]);
        tmp=fyl();
        if(tmp==-1) return -1;
        res+=tmp;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        if(N==0&&M==0&&K==0) break;
        input();
        printf("%d\n",work());
    }
    return 0;
}
