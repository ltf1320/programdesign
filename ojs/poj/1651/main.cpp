#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn];
int kk[maxn];
int N;


int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&kk[i]);
    }
    for(int i=1;i<=N;i++)
        dp[i][1]=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=2;j<=N;j++)
            dp[i][j]=inf;
    }
    for(int j=2;j<N;j++)
        for(int i=1;i<=N-j;i++)
        {
            for(int k=0;k<j-1;k++)
            {
                if(dp[i][j]>dp[i][k+1]+dp[i+k+1][j-k-1]+kk[i-1]*kk[i+k]*kk[i+j-1])
                    dp[i][j]=dp[i][k+1]+dp[i+k+1][j-k-1]+kk[i-1]*kk[i+k]*kk[i+j-1];
            }
        }
    printf("%d\n",dp[1][N-1]);
    return 0;
}
