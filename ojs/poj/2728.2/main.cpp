#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1000+10;
const double inf=10000*100000;
const double err=1E-7;
const double resErr=0.0001;
int N;
struct Node
{
    int x,y,h;
};
Node nds[maxn];

double cost[maxn][maxn];
double kdis[maxn][maxn];
double dis[maxn][maxn];
double dp[maxn];

double low_dis[maxn];
bool vis[maxn];
double prim()
{
    for(int i=0;i<N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;  //!!!!!²»ÒªÂ©
    double res=0;
    int now=0;
    int l;
    double ndis;
    for(int k=1;k<N;k++)
    {
        ndis=inf;
        for(int i=1;i<N;i++)
        {
            if(!vis[i]&&dis[now][i]&&dis[now][i]<low_dis[i])
                low_dis[i]=dis[now][i];
            if(!vis[i]&&ndis>low_dis[i])
            {
                ndis=low_dis[i];
                l=i;
            }
        }
        vis[l]=1;
        now=l;
        res+=ndis;
    }
    return res;
}



double work()
{
    double l=0,r=inf,m;
    double res;
    while(r-l>resErr)
    {
        m=(l+r)/2;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                dis[i][j]=dis[j][i]=cost[i][j]-m*kdis[i][j];
        res=prim();
        if(res<0)
            r=m;
        else l=m;
    }
    return l;
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&nds[i].x,&nds[i].y,&nds[i].h);
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            kdis[i][j]=kdis[j][i]=sqrt((nds[i].x-nds[j].x)*(nds[i].x-nds[j].x)+(nds[i].y-nds[j].y)*(nds[i].y-nds[j].y));
            cost[i][j]=cost[j][i]=abs(1.0*nds[i].h-nds[j].h);
        }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        input();
        printf("%.3f\n",work());
    }
    return 0;
}
