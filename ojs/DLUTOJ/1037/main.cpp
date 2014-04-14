#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1000+10;
const int MOD=1000000007;
int N,M,K;
LL dp[maxn][maxn];
LL sum[maxn][maxn];
void pre()
{
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<maxn;i++)
        for(int j=1;j<maxn;j++)
        {
            dp[i][j]=i+j-1+dp[i-1][j-1];
   //         dp[i][j]%=MOD;
        }
    for(int i=1;i<maxn;i++)
        for(int j=1;j<maxn;j++)
        {
            sum[i][j]=sum[i][j-1]-sum[i-1][j-1]+sum[i-1][j]+dp[i][j];
            sum[i][j]%=MOD;
        }
}

LL get(int n,int m)
{
    if(n<=0||m<=0) return 0;
    return sum[n][m];
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        cout<<get(N-2*K,M-2*K)<<endl;
    }
    return 0;
}
