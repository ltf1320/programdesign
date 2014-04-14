#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=50+10;
const int maxn=2*MAXN*MAXN+MAXN;
const int maxm=270000+100;
const int inf=0x3f3f3f3f;
int N,M,K;


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
deque<int> que;

bool spfa(int f,int t)
{
    for(int i=0;i<maxn;i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push_front(f);
    dis[f]=0;
    in[f]=1;
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop_front();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(edge[i].cap&&dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                dis[edge[i].to]=dis[now]+edge[i].cost;
                from[edge[i].to]=i;
                if(!in[edge[i].to])
                {
                    if(que.empty()||dis[edge[i].to]<dis[que.front()])
                        que.push_front(edge[i].to);
                    else que.push_back(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return false;
    else return true;
}



int getNCode(int n,int k)
{
    return n*K+k+2;
}

int getMCode(int m,int k)
{
    return m*K+k+N*K+2;
}

void input()
{
    int tmp;
    //need
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp);
            add(0,getNCode(i,j),tmp,0);
        }
    }
    //has
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp);
            add(getMCode(i,j),1,tmp,0);
        }
    }
    //cost
    for(int k=0;k<K;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                scanf("%d",&tmp);
                add(getNCode(i,k),getMCode(j,k),inf,tmp);
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


void work()
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
        printf("%d\n",cost);
    else printf("-1\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        if(N==0&&M==0&&K==0) break;
        init();
        input();
        work();
    }
    return 0;
}
