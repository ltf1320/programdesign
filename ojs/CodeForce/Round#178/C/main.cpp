#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int maxn=1000+10;

int N,M;
LL dp[maxn];
int led[maxn];

void pre()
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j];
        }
        if(i%2==0)
            dp[i]+=dp[i/2]*dp[i/2];
    }
}

int main()
{
    LL res=1;
    scanf("%d%d",&N,&M);
    pre();
    for(int i=0;i<M;i++)
        scanf("%d",&led[i]);
    sort(led,led+M);
    for(int i=1;i<M;i++)
    {
        res=res*dp[led[i]-led[i-1]-1]%MOD;
    }
    if(res!=1)
    {
        if(led[0]-1)
            res=res*(led[0]-1)%MOD;
        if(N-led[M-1])
            res=res*(N-led[M-1])%MOD;
    }
    else if((led[0]-1)&&(N-led[M-1]))
    {
        res=(led[0]-1)*(N-led[M-1])%MOD;
    }
    else res=1;
    cout<<res<<endl;
    return 0;
}
