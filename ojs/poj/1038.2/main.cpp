#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=150+10;
const int maxm=15;
int N,M,K;
int dp[maxn];
int min[maxm];

bool hei[maxn][maxm];

bool judgeh(int x,int y)
{
    if(x<2) return false;
    if(y+2>M) return false;
    for(int i=x;i>x-2;i--)
        for(int j=y;j<y+3;j++)
            if(hei[i][j]) return false;
    return true;
}

bool judges(int x,int y)
{
    if(x<3) return false;
    if(y+1>M) return false;
    for(int i=x;i>x-3;i--)
        for(int j=y;j<y+2;j++)
            if(hei[i][j]) return false;
    return true;
}


void dfs(int x,int y,int v,int kk)
{
 //   dp[x][y]=max(dp[x][y],v);
    if(y>=M)
    {
        dp[x][M]=max(dp[x][M],v+dp[x-kk][M]);
        return;
    }
    if(judgeh(x,y))
    {
        dp[x][y]=max(dp[x][y],dp[x-2][y]+v+1);
        dfs(x,y+3,v+1,max(kk,2));
    }
    if(judges(x,y))
    {
        dp[x][y]=max(dp[x][y],dp[x-3][y]+v+1);
        dfs(x,y+2,v+1,max(kk,3));
    }
    dp[x][y]=max(dp[x-1][y]+v,dp[x][y]);
    dfs(x,y+1,v,max(kk,1));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int x,y;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(hei,0,sizeof(hei));
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<K;i++)
        {
            scanf("%d%d",&x,&y);
            hei[x][y]=1;
        }
        for(int i=2;i<=N;i++)
            dfs(i,1,0,1);
        printf("%d\n",dp[N]);
    }
    return 0;
}
