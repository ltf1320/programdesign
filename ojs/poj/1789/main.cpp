#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=2000+10;
const int inf=0x3f3f3f3f;

int map[maxn][maxn];
char ss[maxn][8];
int n;

void wdiff(int a,int b)
{
    int res=0;
    if(map[a][b]) return;
    for(int i=0;i<7;i++)
        if(ss[a][i]!=ss[b][i])
            res++;
    map[a][b]=map[b][a]=res;
}


int low_dis[maxn];
bool vis[maxn];

int prim()
{
    for(int i=0;i<n;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;  //²»ÒªÂ©Õâ¾ä
    int res=0;
    int now=0;
    int l,ndis;
    for(int k=1;k<n;k++)
    {
        ndis=inf;
        for(int i=1;i<n;i++)
        {
            if(!vis[i]&&map[now][i]&&map[now][i]<low_dis[i])
                low_dis[i]=map[now][i];
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

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
            scanf("%s",ss[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                wdiff(i,j);
        printf("The highest possible quality is 1/%d.\n",prim());
    }
    return 0;
}
