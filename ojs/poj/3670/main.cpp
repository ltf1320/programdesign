#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30000+100;
const int inf=0x3f3f3f3f;
int num[maxn];
int dp[maxn][5];
int N,res;

void rev()
{
    int t;
    for(int i=0;i<N/2;i++)
    {
        t=num[i];
        num[i]=num[N-i-1];
        num[N-i-1]=t;
    }
}

void work()
{
    dp[0][1]=dp[0][2]=dp[0][3]=1;
    dp[0][num[0]]=0;
    for(int i=1;i<N;i++)
    {
        if(num[i]==1)
            dp[i][1]=dp[i-1][1];
        else dp[i][1]=dp[i-1][1]+1;
        if(num[i]==2)
            dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
        else dp[i][2]=min(dp[i-1][1],dp[i-1][2])+1;
        dp[i][3]=min(dp[i-1][1],dp[i-1][2]);
        dp[i][3]=min(dp[i-1][3],dp[i][3]);
        if(num[i]!=3) dp[i][3]++;
    }
    if(dp[N-1][1]<res) res=dp[N-1][1];
    if(dp[N-1][2]<res) res=dp[N-1][2];
    if(dp[N-1][3]<res) res=dp[N-1][3];
}

int main()
{
    freopen("in.txt","r",stdin);
    res=inf;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    work();
    rev();
    work();
    printf("%d\n",res);
    return 0;
}
