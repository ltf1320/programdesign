#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N;

struct Book
{
    int t,w;
    bool operator<(const Book &a)const
    {
        if(w==a.w) return t<a.t;
        return w>a.w;
    }
};
Book bks[maxn];
int dp[maxn*2];
int sumw,sumt;
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&bks[i].t,&bks[i].w);
        sumw+=bks[i].w;
        sumt+=bks[i].t;
    }
    for(int i=0;i<=sumt;i++)
        dp[i]=inf;
    dp[0]=sumw;
    for(int i=1;i<=N;i++)
    {
        for(int j=sumt-bks[i].t;j>=0;j--)
        {
            dp[j+bks[i].t]=min(dp[j]-bks[i].w,dp[j+bks[i].t]);
        }
    }
    for(int i=0;i<=sumt;i++)
        if(dp[i]<=i)
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}
