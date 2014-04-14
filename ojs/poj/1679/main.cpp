#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int inf= 0x3f3f3f3f;
int N,M;
int map[maxn][maxn];
int rep[maxn][maxn];

int low_dis[maxn];
int from[maxn];
bool vis[maxn];
int prim()
{
    for(int i=1;i<=N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //!!!!!²»ÒªÂ©
    int res=0;
    int now=1;
    int l,ndis,nfrom;
    for(int k=1;k<N;k++)
    {
        ndis=inf;
        for(int i=1;i<=N;i++)
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
        for(int i=1;i<=N;i++)
        {
            if(vis[i])
            {
                rep[l][i]=max(rep[nfrom][i],ndis);
                rep[i][l]=rep[l][i];
            }
        }
        map[nfrom][l]=map[l][nfrom]=inf;
        vis[l]=1;
        now=l;
        res+=ndis;
    }
    return res;
}

void work()
{
    int res=prim();
    int md=inf;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            md=min(md,map[i][j]-rep[i][j]);
        }
    if(md==0)
        printf("Not Unique!\n");
    else
        printf("%d\n",res);
}

void input()
{
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        map[f][t]=map[t][f]=v;
    }
}

void init()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            map[i][j]=inf;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        init();
        input();
        work();
    }
    return 0;
}
