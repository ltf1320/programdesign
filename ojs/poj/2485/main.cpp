#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=500+10;
const int inf=0x3f3f3f3f;

int map[maxn][maxn];

int low_dis[maxn];
bool vis[maxn];

int n;

int prim()
{
    for(int i=0;i<n;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;   //这句漏第二次了
    int now=0;
    int res=0;
    int l,ndis;
    for(int i=1;i<n;i++)
    {
        ndis=inf;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&map[now][j]&&low_dis[j]>map[now][j])
                low_dis[j]=map[now][j];
            if(!vis[j]&&ndis>low_dis[j])
            {
                ndis=low_dis[j];
                l=j;
            }
        }
        if(ndis>res) res=ndis;
        vis[l]=1;
        now=l;
    }
    return res;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        printf("%d\n",prim());
    }
    return 0;
}
