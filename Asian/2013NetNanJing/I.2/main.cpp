#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1000+10;
const double inf= 1000000000;
int N,K;
double map[maxn][maxn];
double dp[maxn][maxn];
bool used[maxn][maxn];
int pp[maxn][maxn];

struct Point
{
    int x,y;
}pts[maxn];
double getDis(const Point &a,const Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

struct EDGE
{
    int next,to;
};
EDGE edge[maxn*2];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

double low_dis[maxn];
int from[maxn];
bool vis[maxn];

double prim()
{
    for(int i=0;i<N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //!!!!!²»ÒªÂ©
    double ndis, res=0;
    int now=1;
    int l,nfrom;
    for(int k=1;k<N;k++)
    {
        ndis=inf;
        for(int i=0;i<N;i++)
        {
            if(!vis[i]&&map[now][i]<low_dis[i])
            {
                low_dis[i]=map[now][i];
                from[i]=now;
            }
            if(!vis[i]&&ndis>low_dis[i])
            {
                ndis=low_dis[i];
                nfrom=from[i];
                l=i;
            }
        }
        used[nfrom][l]=used[l][nfrom]=1;
        add(nfrom,l);
        add(l,nfrom);
        vis[l]=1;
        now=l;
        res+=ndis;
    }
    return res;
}

double dfs(int s,int now,int from)
{
    double res=inf;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        double tmp=dfs(s,edge[i].to,now);
        dp[now][edge[i].to]=dp[edge[i].to][now]=min(dp[now][edge[i].to],tmp);
        res=min(res,tmp);
    }
    if(from!=s)
        res=min(res,map[s][now]);
    return res;
}

void work()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            map[i][j]=getDis(pts[i],pts[j]);
        }
    double res=prim();
    double md=0;
    for(int i=0;i<N;i++)
        dfs(i,i,-1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(used[i][j]&&i&&j)
                md=max(md,dp[i][j]-map[i][j]);
        }
    printf("%.2f\n",K*(res+md));
}



void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&pts[i].x,&pts[i].y);
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(used,0,sizeof(used));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=inf;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        init();
        input();
        work();
    }
    return 0;
}
