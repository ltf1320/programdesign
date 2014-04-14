#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=10000+10;
const int inf=1E9+1;
int N,K;
LL num[maxn];
LL dp[2][maxn];

LL abs(LL a)
{
    return a>0?a:-a;
}

bool judge(LL m)
{
    for(int i=0;i<N;i++)
    {
        dp[0][i]=i;
        for(int j=0;j<i;j++)
            if(abs(num[i]-num[j])<=m*(i-j))
                dp[0][i]=min(dp[0][i],dp[0][j]+i-j-1);
    }
    for(int i=N-1;i>=0;i--)
    {
        dp[1][i]=N-1-i;
        for(int j=N-1;j>i;j--)
            if(abs(num[i]-num[j])<=m*(j-i))
                dp[1][i]=min(dp[1][i],dp[1][j]+j-i-1);
    }
    for(int i=0;i<N;i++)
    if(dp[0][i]+dp[1][i]<=K)
        return true;
    return false;
}


int main()
{
    LL l=0,r=0;
    LL m;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%I64d",&num[i]);
        if(i)
            r=max(r,abs(num[i]-num[i-1]));
    }
    while(r>=l)
    {
        m=(l+r)>>1;
        if(judge(m))
            r=m-1;
        else
            l=m+1;
    }
    printf("%I64d\n",l);
    return 0;
}
