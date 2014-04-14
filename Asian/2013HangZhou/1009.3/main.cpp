#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=22;
const int inf=0x3f3f3f3f;
int B,G,S;
int dp[1<<21][2];//0 for Alice 1 for Bob
int num[1<<21][10];
bool has[maxn][10];


int dfs(int st,int cc)
{
    if(dp[st][0]!=-1)
        return dp[st][cc];
    dp[st][0]=0;
    dp[st][1]=inf;
    int nst,ms;
    for(int i=0;i<B;i++)
    {
        if(!(st&(1<<i)))
        {
            nst=st|(1<<i);
            ms=0;
            if(num[nst][0]==-1)
            {
                for(int j=0;j<G;j++)
                {
                    num[nst][j]=num[st][j]+has[i][j];
                    if(num[nst][j]/S>num[st][j]/S)
                        ms+=1;
                }
            }
            if(ms)
            {
                dp[st][0]=max(dp[st][0],dfs(nst,0)+ms);
                dp[st][1]=min(dp[st][1],dfs(nst,1));
            }
            else
            {
                dp[st][0]=max(dp[st][0],dfs(nst,1));
                dp[st][1]=min(dp[st][1],dfs(nst,0));
            }
        }
    }
    return dp[st][cc];
}

void work()
{
    dp[(1<<B)-1][0]=dp[(1<<B)-1][1]=0;
    dfs(0,0);
    int res=dp[0][0];
    int sum=0;
    for(int i=0;i<G;i++)
        sum+=num[(1<<B)-1][i]/S;
    printf("%d\n",2*res-sum);
}

void input()
{
    int n,t;
    for(int i=0;i<B;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&t);
            has[i][t-1]=1;
        }
    }
}

void init()
{
    memset(dp,-1,sizeof(dp));
    memset(num,-1,sizeof(num));
    memset(has,0,sizeof(has));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&G,&B,&S))
    {
        if(B==0&&G==0&&S==0)
            break;
        init();
        input();
        work();
    }
    return 0;
}