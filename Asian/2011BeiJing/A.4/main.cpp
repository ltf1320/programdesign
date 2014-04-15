#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=1000+100;
const int inf=0x3f3f3f3f;
double Max[maxn][maxn];
int N;

struct City
{
    int x,y,p;
};
City cities[maxn];
double map[maxn][maxn];

struct EDGE
{
    int to,next;
    double v;
};
EDGE edge[4*maxn];
int box[maxn];
int ent;

void add(int from,int to,double v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}


double low_dis[maxn];
bool vis[maxn];

double prim()
{
    for(int i=1;i<=N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //!!!!!不要漏
    double res=0;
    int now=1;
    int l;
    double ndis;
    for(int k=2;k<=N;k++)
    {
        ndis=inf;
        for(int i=2;i<=N;i++)
        {
            if(!vis[i]&&map[now][i]!=-1&&map[now][i]<low_dis[i])
                low_dis[i]=map[now][i];
            if(!vis[i]&&ndis>low_dis[i])
            {
                ndis=low_dis[i];
                l=i;
            }
        }
        add(now,l,map[now][l]);
        add(l,now,map[l][now]);
        vis[l]=1;
        now=l;
        res+=ndis;
    }
    return res;
}

void input()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d%d%d",&cities[i].x,&cities[i].y,&cities[i].p);
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
            map[i][j]=map[j][i]=sqrt(1.0*(cities[i].x-cities[j].x)*(cities[i].x-cities[j].x)+1.0*(cities[i].y-cities[j].y)*(cities[i].y-cities[j].y));
}

struct FBS
{
    int i;
    double maxf;
    FBS(int ii,double m):i(ii),maxf(m){}
    FBS(){}
};

void bfs(int n)
{
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    queue<FBS> que;
    que.push(FBS(n,0));
    vis[n]=1;
    FBS now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        Max[n][now.i]=now.maxf;
        vis[now.i]=1;
        for(int i=box[now.i];i!=-1;i=edge[i].next)
        {
            if(!vis[edge[i].to])
                que.push(FBS(edge[i].to,max(edge[i].v,now.maxf)));
        }
    }
}

double work()
{
    double mB;
    double res;
    res=0;
    mB=prim();
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            Max[i][j]=0;
    for(int i=1;i<=N;i++)
        bfs(i);
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        {
            if((0.0+cities[i].p+cities[j].p)/(mB-Max[i][j])>res)
                res=(0.0+cities[i].p+cities[j].p)/(mB-Max[i][j]);
        }
    return res;
}

void init()
{
    memset(map,-1,sizeof(map));
    memset(box,-1,sizeof(box));
    ent=0;
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
        printf("%.2f\n",work());
    }
    return 0;
}
