#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=200+10;
const int maxm=maxn*maxn*3;
const LL inf=((LL)1)<<62;


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

int Sv[maxn];

int getDis(Point &a,Point &b)
{
    return mabs(a.x-b.x)+mabs(a.y-b.y)+1; //写成mabs(b.x-b.y)再改成mabs(b.y-b.y) 2B
}
int Dis[maxn][maxn];

struct EDGE
{
    int next,to,cost,from;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t,int c)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].cost=c;
    edge[ent].next=box[f];
    box[f]=ent++;
}

LL dis[maxn];
bool in[maxn];
queue<int> que;
int cnt[maxn];
int from[maxn];
int spfa(int s)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<2+N+M;i++)
        dis[i]=inf;
    memset(cnt,0,sizeof(cnt));
    memset(from,-1,sizeof(from));
    que.push(s);
    in[s]=1;
    dis[s]=0;
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                from[edge[i].to]=i;
                dis[edge[i].to]=dis[now]+edge[i].cost;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>N+M+2)
                    {
                        while(!que.empty())que.pop();
                        return edge[i].to;
                    }
                }
            }
        }
        in[now]=0;
    }
    return -1;
}

int vis[maxn];
void findCircle(int now)
{
    int i;
    memset(vis,0,sizeof(vis));
    while(!vis[now])  //遍历两边，确保点都在环中
    {
        vis[now]=1;
        now=edge[from[now]].from;
    }

    while(vis[now]==1)
    {
        vis[now]=2;
        i=from[now];
        if(edge[i].to>=2&&edge[i].to<2+N&&edge[i].from>=2+N)
            kplan[edge[i].to-2][edge[i].from-N-2]--;
        if(edge[i].from>=2&&edge[i].from<2+N&&edge[i].to>=2+N)
            kplan[edge[i].from-2][edge[i].to-N-2]++;
        now=edge[i].from;
    }
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&Bs[i].x,&Bs[i].y,&Bs[i].v);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&Ss[i].x,&Ss[i].y,&Ss[i].v);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%d",&kplan[i][j]);
            Sv[j]+=kplan[i][j];
            Dis[i][j]=getDis(Bs[i],Ss[j]);
            if(kplan[i][j])
                add(j+N+2,i+2,-Dis[i][j]);
            add(i+2,j+N+2,Dis[i][j]);
        }

    for(int i=0;i<M;i++)
    {
        if(Sv[i]>0)
            add(1,i+N+2,0);
        if(Ss[i].v>Sv[i])
            add(i+N+2,1,0);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    memset(Sv,0,sizeof(Sv));
    ent=0;
}

void work()
{
    int kk=spfa(1);
    if(kk!=-1)
    {
        findCircle(kk);
        printf("SUBOPTIMAL\n");
        for(int i=0;i<N;i++)
        {
            printf("%d",kplan[i][0]);
            for(int j=1;j<M;j++)
                printf(" %d",kplan[i][j]);
            puts("");
        }
    }
    else printf("OPTIMAL\n");
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
