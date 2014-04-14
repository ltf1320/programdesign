#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxs=40+10;
const double inf=100*101*200*sqrt(2.0)+10000;
int N;
struct Point
{
    int x,y;
};
Point lks[maxn][maxs];
int lksn[maxn];
int sum[maxn];

double getDis(const Point &a,const Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

struct EDGE
{
    int next,to;
    double v;
};
EDGE edge[maxs*maxs*maxn+1000];
int box[maxn*maxs];
int ent;

void add(int f,int t,double v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}
double dis[maxn*maxs];
bool in[maxn*maxs];
queue<int> que;
int spfa(int s,int t)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<maxn*maxs;i++)
        dis[i]=inf;
    que.push(s);
    dis[s]=0.0;
    in[s]=1;
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
        }
        in[now]=0;
    }
    return (int)(100*dis[t]);
}

void work()
{
    int res=inf;
    edge[ent].to=1;
    edge[ent].v=0;
    for(int i=0; i<lksn[0]; i++)
    {
        edge[0].to=sum[0]+i;
        edge[ent].next=box[sum[N]+i];
        box[sum[N]+i]=ent;
        res=min(res,spfa(0,1));
        box[sum[N]+i]=edge[ent].next;
    }
    printf("%d\n",res);
}


void input()
{
    for(int i=0; i<N; i++)
    {
        scanf("%d",&lksn[i]);
        for(int j=0; j<lksn[i]; j++)
            scanf("%d%d",&lks[i][j].x,&lks[i][j].y);
    }
    sum[0]=2;
    for(int i=1; i<=N; i++)
        sum[i]=lksn[i-1]+sum[i-1];
    add(0,sum[0],0);
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<lksn[i]; j++)
            for(int k=0; k<lksn[i+1]; k++)
                add(sum[i]+j,sum[i+1]+k,getDis(lks[i][j],lks[i+1][k]));
    }
    for(int j=0; j<lksn[N-1]; j++)
        for(int k=0; k<lksn[0]; k++)
            add(sum[N-1]+j,sum[N]+k,getDis(lks[N-1][j],lks[0][k]));
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;

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
