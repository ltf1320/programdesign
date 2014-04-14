#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=15;
const int MOD=1E8;
int N,M;
int dp[2][1<<12];
int map[maxn][maxn];

void work()
{
    dp[0][0]=1;
    int kk=0,nst;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            for(int st=0;st<(1<<M);st++)
            {
                if(dp[kk][st])
                {
                    nst=st;
                    if(nst&(1<<j))
                        nst^=(1<<j);
                    dp[kk^1][nst]+=dp[kk][st];
                    if(dp[kk^1][nst]>=MOD)
                        dp[kk^1][nst]-=MOD;
                    if(map[i][j]&&!(st&(1<<j))&&(j==0||!(st&(1<<(j-1)))))
                    {
                        dp[kk^1][nst|(1<<j)]+=dp[kk][st];
                        if(dp[kk^1][nst|(1<<j)]>=MOD)
                            dp[kk^1][nst|(1<<j)]-=MOD;
                    }
                }
            }
            memset(dp[kk],0,sizeof(dp[kk]));
            kk^=1;
        }
    int res=0;
    for(int st=0;st<(1<<M);st++)
    {
        res+=dp[kk][st];
        if(res>=MOD)
            res-=MOD;
    }
    memset(dp[kk],0,sizeof(dp[kk]));
    printf("%d\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
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
