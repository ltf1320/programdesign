#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100+10;
const int inf=0x3f3f3f3f;

int n;

int map[maxn][maxn];
int low_dis[maxn];
bool vis[maxn];

int prim()
{
    for(int i=0;i<n;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    int now=0;
    int res=0;
    int l,ndis;
    for(int i=1;i<n;i++)
    {
        ndis=inf;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&map[now][j]&&map[now][j]<low_dis[j])
                low_dis[j]=map[now][j];
            if(!vis[j]&&ndis>low_dis[j])
            {
                l=j;
                ndis=low_dis[j];
            }
        }
        res+=ndis;
        now=l;
        vis[l]=1;
    }
    return res;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        printf("%d\n",prim());
    }
    return 0;
}
