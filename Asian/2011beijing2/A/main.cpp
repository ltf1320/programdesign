#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1000+100;
const int inf=0x3f3f3f3f;
int N;

struct City
{
    int x,y,p;
};
City cities[maxn];
float map[maxn][maxn];

float low_dis[maxn];
bool vis[maxn];
int maxl;
int prim()
{
    for(int i=1;i<=N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //!!!!!不要漏
    int res=0;
    int now=1;
    int l,ndis;
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
        vis[l]=1;
        if(map[now][l]>maxl) maxl=map[now][l];
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

float work()
{
    float A,B,mB;
    float res;
    float tmp;
    maxl=0;
    res=0;
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        {
            tmp=map[i][j];
            map[i][j]=map[j][i]=0;
            A=cities[i].p+cities[j].p;
            B=prim();
            map[i][j]=map[j][i]=tmp;
            if(A/B>res)
                res=A/B;
        }
    return res;
}

void init()
{
    memset(map,-1,sizeof(map));
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
