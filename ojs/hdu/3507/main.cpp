#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500000+100;
int N,M;
int num[maxn];
int sum[maxn];

int que[2*maxn];
int head,tail;

int dp[maxn];

int getUp(int i,int j)
{
    return dp[i]+sum[i]*sum[i]-(dp[j]+sum[j]*sum[j]);
}

int getdown(int i,int j)
{
    return 2*(sum[i]-sum[j]);
}

void input()
{
    num[0]=sum[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
}

void work()
{
    head=tail=0;
    que[tail]=0;
    dp[0]=0;
    for(int i=1;i<=N;i++)
    {
        while(tail>head&&getUp(que[head+1],que[head])<=sum[i]*getdown(que[head+1],que[head]))
            head++;
        dp[i]=dp[que[head]]+(sum[i]-sum[que[head]])*(sum[i]-sum[que[head]])+M;
        while(tail>head&&getUp(i,que[tail])*getdown(que[tail],que[tail-1])<=getUp(que[tail],que[tail-1])*getdown(i,que[tail]))
            tail--;
        que[++tail]=i;
    }
    printf("%d\n",dp[N]);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        work();
    }
    return 0;
}
