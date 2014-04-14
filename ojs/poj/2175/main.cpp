#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int maxm=maxn*maxn*3;
const int inf=0x3f3f3f3f;
int N,M;
int kcost,mcost;
const int S=0,T=1;

int kplan[maxn][maxn];
int mplan[maxn][maxn];

int mabs(int a)
{
    return a>0?a:-a;
}

struct Point
{
    int x,y;
    int v;
};
Point Bs[maxn];
Point Ss[maxn];

int getDis(Point &a,Point &b)
{
    return mabs(a.x-b.x)+mabs(a.y-b.y)+1; //写成mabs(b.x-b.y)再改成mabs(b.y-b.y) 2B
}
int Dis[maxn][maxn];

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


void getkcost()
{
    kcost=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            kcost+=Dis[i][j]*kplan[i][j];
        }
}

void markmplan()
{
    memset(mplan,0,sizeof(mplan));
 //   puts("");
    for(int i=0;i<ent;i++)
    {
        if((edge[i].to>=2&&edge[i].to<N+2)&&(edge[i].from>=2+N&&edge[i].from<2+N+M)) //写成2*N+M
        {
            mplan[edge[i].to-2][edge[i].from-N-2]=edge[i].cap;
 //           printf("%d %d %d\n",edge[i].to-2,edge[i].from-N-2,edge[i].cap);
        }
    }
}

void getmcost()
{
    mcost=0;
    int mincap;
    while(spfa(S,T))
    {
        mincap=inf;
        for(int i=from[T];i!=-1;i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[T];i!=-1;i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        mcost+=dis[T]*mincap;
    }
    markmplan();
}


void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&Bs[i].x,&Bs[i].y,&Bs[i].v);
        add(0,i+2,Bs[i].v,0);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&Ss[i].x,&Ss[i].y,&Ss[i].v);
        add(i+2+N,1,Ss[i].v,0);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%d",&kplan[i][j]);
            Dis[i][j]=getDis(Bs[i],Ss[j]);
            add(i+2,j+N+2,inf,Dis[i][j]);
        }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

void work()
{
    getkcost();
    getmcost();
    if(kcost<=mcost)
        printf("OPTIMAL\n");
    else
    {
        printf("SUBOPTIMAL\n");
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M-1;j++)
                printf("%d ",mplan[i][j]);
            printf("%d\n",mplan[i][M-1]);
        }
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

        /*
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
                printf("%d ",Dis[i][j]);
            puts("");
        }
        */

    }
    return 0;
}
