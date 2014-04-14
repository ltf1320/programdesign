#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int inf =0x3f3f3f3f;
int map[maxn][maxn];
int low_dis[maxn];
bool vis[maxn];
int cnt[maxn];
int n,p;

int prim()
{
    for(int i=0;i<=n;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    vis[1]=1;  //!!!!!²»ÒªÂ©
    cnt[1]=1;
    int res=1;
    int now=1;
    int l,ndis,ncnt;
    for(int k=2;k<=n;k++)
    {
        ndis=inf;
        ncnt=1;
        for(int i=2;i<=n;i++)
        {
            if(!vis[i]&&map[now][i]&&map[now][i]<low_dis[i])
            {
                low_dis[i]=map[now][i];
                cnt[i]=1;
            }
            if(!vis[i]&&map[now][i]&&map[now][i]==low_dis[i])
                cnt[i]++;
            if(!vis[i]&&ndis>low_dis[i])
            {
                ncnt=1;
                ndis=low_dis[i];
                l=i;
            }
            if(ndis==low_dis[i])
            {
                ncnt++;
            }
        }
        vis[l]=1;
        res=res*ncnt*cnt[now];
        now=l;
    }
    return res/12;
}



int main()
{
    freopen("in.txt","r",stdin);
    int m;
    int f,t,v;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        if(n==0&&m==0&&p==0) break;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&f,&t,&v);
            map[f][t]=map[t][f]=v;
        }
        printf("%d\n",prim());
    }
    return 0;
}
