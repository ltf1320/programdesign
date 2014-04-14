#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200000+100;
typedef long long LL;
int N,K;
int num[maxn];
LL sum[maxn];
LL dp[maxn][2];
int chose[maxn][2];



int main()
{
  //  freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    sum[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    dp[0][0]=0;
    for(int i=1;i<=N-K+1;i++)
    {
        if(sum[i+K-1]-sum[i-1]>dp[i-1][0])
        {
            dp[i][0]=sum[i+K-1]-sum[i-1];
            chose[i][0]=i;
        }
        else
        {
            dp[i][0]=dp[i-1][0];
            chose[i][0]=chose[i-1][0];
        }
    }
    dp[N-K+1][1]=0;
    for(int i=N-K+1;i>=0;i--)
    {
        if(sum[i+K-1]-sum[i-1]>=dp[i+1][1])
        {
            dp[i][1]=sum[i+K-1]-sum[i-1];
            chose[i][1]=i;
        }
        else
        {
            dp[i][1]=dp[i+1][1];
            chose[i][1]=chose[i+1][1];
        }
    }
    LL res=0;
    int c1,c2;
    for(int i=0;i<=N-2*K+1;i++)
    {
        if(dp[i][0]+dp[i+K][1]>res)
        {
            res=dp[i][0]+dp[i+K][1];
            c1=chose[i][0];
            c2=chose[i+K][1];
        }
    }
    printf("%d %d\n",c1,c2);
    return 0;
}
