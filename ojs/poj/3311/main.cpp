#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn=10+2;
const int inf=0x3f3f3f3f;
int N;

int dis[maxn][maxn];

int dp[1<<12][maxn];

void floyd()
{
    for(int k=0;k<=N;k++)
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

void work()
{
    floyd();
    dp[0][0]=0;
    int nst;
    for(int st=1;st<(1<<N);st++)
    {
        for(int i=1;i<=N;i++)
        {
            if(st&(1<<(i-1)))
            {
                if(st==(1<<(i-1)))
                    dp[st][i]=dis[0][i];
                else
                {
                    nst=st^(1<<(i-1));
                    dp[st][i]=inf;
                    for(int j=1;j<=N;j++)
                    {
                        if(nst&(1<<(j-1)))
                        {
                            dp[st][i]=min(dp[st][i],dp[nst][j]+dis[j][i]);
                        }
                    }
                }
            }
        }
    }
    int res=inf;
    for(int i=1;i<=N;i++)
    {
        res=min(res,dp[(1<<N)-1][i]+dis[i][0]);
    }
    printf("%d\n",res);
}

void input()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
        {
            scanf("%d",&dis[i][j]);
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        input();
        work();
    }
    return 0;
}
