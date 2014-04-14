#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100000+10;
const int maxh=100;
int dp[maxn][maxh];
int h[maxn];

int abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    freopen("in.txt","r",stdin);
    int N,C;
    int maxh(0);
    int res=inf;
    scanf("%d%d",&N,&C);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
    {
        scanf("%d",&h[i]);
        if(h[i]>maxh) maxh=h[i];
    }
    for(int j=h[0];j<=maxh;j++)
        dp[0][j]=(j-h[0])*(j-h[0]);
    for(int i=1;i<N;i++)
    {
        for(int j=h[i];j<=maxh;j++)
        {
            for(int k=h[i-1];k<=maxh;k++)
            {
                if(dp[i-1][k]+(j-h[i])*(j-h[i])+abs(j-k)*C<dp[i][j]||dp[i][j]==-1)
                    dp[i][j]=dp[i-1][k]+(j-h[i])*(j-h[i])+abs(j-k)*C;
            }
        }
    }
/*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<maxh;j++)
            printf("%d ",dp[i][j]);
        putchar('\n');
    }
*/
    for(int j=h[N-1];j<=maxh;j++)
        if(dp[N-1][j]<res)
            res=dp[N-1][j];
    printf("%d\n",res);
    return 0;
}
