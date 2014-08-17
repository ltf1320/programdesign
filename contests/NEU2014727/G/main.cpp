#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const LL MOD=1E9+7;
const int maxn=100+10;

LL dp[maxn][maxn];

LL jc[maxn];

int N,M;

void printdp()
{
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=M; j++)
            printf("%I64d ",dp[i][j]);
        puts("");
    }
}

LL dfs(int n,int m)
{
    if(n==3&&m==3)
    {
        n++;
        n--;
    }
    if(n==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    LL res=0;
    if(m==n)
        res=jc[n]%MOD;
    else
    {
        res=(m*dfs(n-1,m-1))%MOD;
        if(n>m&&(M-m)>0)
            res=(res+(M-m)*dfs(n-1,m))%MOD;
    }
    dp[n][m]=res;
    return res;
}

int main()
{
  //  freopen("out.txt","w",stdout);
    jc[0]=1;
    for(int i=1; i<maxn; i++)
        jc[i]=jc[i-1]*i%MOD;
    while(~scanf("%d%d",&N,&M))
    {
        memset(dp,-1,sizeof(dp));
        dp[1][0]=M;
        for(int i=2; i<=N; i++)
            dp[i][0]=dp[i-1][0]*M%MOD;
        cout<<dfs(N,M)<<endl;
   //     printdp();
    }
    return 0;
}
