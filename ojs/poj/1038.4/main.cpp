#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M,K;
const int maxn=150+10;
const int maxm=10+2;

int dp[maxn][1<<maxm];
bool ilg[maxn][1<<maxm];
bool op[maxn][maxm];

void update(int n,int state)
{
    for(int i=0; i<M; i++)
    {
        if(!(state&(1<<i))&&!(state&(1<<(i+1))))
        {
            for(int j=0; j<(1<<M); j++)
            {
                if(j&(1<<i)&&j&(1<<(i+1))&&!ilg[n+1][j]&&!ilg[n+2][j])
                {
                    dp[n+1][j]=max(dp[n+1][j],dp[n][state]+1);
                }
            }
            if(!(state&(1<<(i+2))))
            {
                for(int j=0; j<(1<<M); j++)
                {
                    if(j&(1<<i)&&j&(1<<(i+1))&&j&(1<<(i+2))&&!ilg[n+1][j])
                    {
                        dp[n+1][j]=max(dp[n+1][j],dp[n][state]+1);
                    }
                }
            }
        }
    }
}

int work()
{
    int maxl1=0,maxl2=0;
    for(int i=1; i<N; i++)
    {
        dp[i][0]=maxl1;
        for(int j=0; j<(1<<M); j++)
        {
            if(!ilg[i][j])
            {
                update(i,j);
                maxl2=max(maxl2,dp[i][j]);
            }
        }
        maxl1=maxl2;
        maxl2=0;
    }
    dp[N][0]=maxl1;
    int res=0;
    for(int i=0;i<(1<<M);i++)
        if(dp[N][i]>res)
            res=dp[N][i];

    return res;
}

void input()
{
    scanf("%d%d%d",&N,&M,&K);
    int x,y;
    for(int i=0; i<K; i++)
    {
        scanf("%d%d",&x,&y);
        op[x][y]=1;
        for(int i=0; i<(1<<(M+1)); i++)
            if(i&(1<<(y-1)))
                ilg[x][i]=1;
    }
}

void init()
{
    memset(op,0,sizeof(op));
    memset(dp,0,sizeof(dp));
    memset(ilg,0,sizeof(ilg));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
