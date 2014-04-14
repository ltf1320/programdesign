#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=100+10;
const int maxk=100+10;
const int inf=0x3f3f3f3f;
int N,K,T;
int dp[maxn][maxk];

struct GT
{
    int t,p,s;
    bool operator<(const GT &a)const
    {
        return t<a.t;
    }
};
GT gt[maxn];

void input()
{
    for(int i=1; i<=N; i++)
        scanf("%d",&gt[i].t);
    for(int i=1; i<=N; i++)
        scanf("%d",&gt[i].p);
    for(int i=1; i<=N; i++)
        scanf("%d",&gt[i].s);
    sort(gt+1,gt+N+1);
    gt[0].s=0;
    gt[0].p=0;
    gt[0].t=0;
}

int work()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=K;j++)
            dp[i][j]=-inf;
    dp[0][0]=0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<=N; j++)
        {
            for(int s=0; s<=K; s++)
            {
                for(int k=max(0,s-abs(gt[i].t-gt[j].t)); k<=min(K,s+abs(gt[i].t-gt[j].t)); k++)
                {
                    if(k==gt[j].s)
                        dp[j][k]=max(dp[j][k],dp[i][s]+gt[j].p);
                    else dp[j][k]=max(dp[j][k],dp[i][s]);
                }
            }
        }
    int res=0;
    for(int i=0;i<=K;i++)
        if(dp[N][i]>res)
            res=dp[N][i];
    res=max(0,res);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&K,&T))
    {
        input();
        printf("%d\n",work());
    }
    return 0;
}
