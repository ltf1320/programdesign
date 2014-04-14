//一开始dp定义反了..
//找答案的地方不对..
//各种错
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000+100;
const int inf=0x3f3f3f3f;
int N,a,b;
int num[maxn];
int dp[maxn][2];

int work()
{
    int j;
    dp[0][0]=0;
    for(int i=N-1;i>=0;i--)
    {
        if(num[i]+b<num[i+1]||i+1>=N)
        {
            dp[i][0]=num[i];
            dp[i][1]=-num[i];
            continue;
        }
        dp[i][0]=inf;
        dp[i][1]=-inf;
        j=i+1;
        while(num[j]<num[i]+a&&j<N)
            j++;
        if(j>=N)
        {
            dp[i][0]=num[i];
            dp[i][1]=-num[i];
            continue;
        }
        for(;num[j]<=num[i]+b;j++)
        {
            if(j>=N) break;
            dp[i][0]=min(dp[i][0],dp[j][1]+num[i]);
            dp[i][1]=max(dp[i][1],dp[j][0]-num[i]);
        }
    }
    int res=-inf;
    for(int i=0;i<N;i++)
    {
        if(num[i]>b) break;
        if(num[i]>=a)
            res=max(res,dp[i][0]);
    }
    if(res==-inf) res=0;
    return res;
}

void input()
{
    int M,tmp;
    scanf("%d%d%d",&M,&a,&b);
    N=0;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&tmp);
        if(tmp>0)
            num[N++]=tmp;
    }
    sort(num,num+N);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        printf("%d\n",work());
    }
    return 0;
}
