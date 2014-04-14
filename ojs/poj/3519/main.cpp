#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
int N,T,L,B;

int flag[maxn];//1 for tostart,2 for stay
double dp[maxn][maxn][2];

void work()
{
    dp[0][0][0]=1;
    int nxt;
    for(int t=0;t<T;t++)
    {
        for(int i=0;i<N;i++)
        {
            if(flag[i]==2)
                dp[t+1][i][0]+=dp[t][i][1];
            for(int k=1;k<=6;k++)
            {
                nxt=i+k;
                if(nxt>N)
                    nxt=N-(nxt-N);
                if(flag[nxt]==1)
                    dp[t+1][0][0]+=dp[t][i][0]/6;
                else if(flag[nxt]==2)
                    dp[t+1][nxt][1]+=dp[t][i][0]/6;
                else
                    dp[t+1][nxt][0]+=dp[t][i][0]/6;
            }
        }
    }
    double res=0;
    for(int i=1;i<=T;i++)
        res+=dp[i][N][0]+dp[i][N][1];
    printf("%.7f\n",res);
}

void input()
{
    int t;
    for(int i=0;i<L;i++)
    {
        scanf("%d",&t);
        flag[t]=2;
    }
    for(int i=0;i<B;i++)
    {
        scanf("%d",&t);
        flag[t]=1;
    }
}

void init()
{
    memset(flag,0,sizeof(flag));
    memset(dp,0,sizeof(dp));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&N,&T,&L,&B))
    {
        if(!(N|T|L|B))
            break;
        init();
        input();
        work();
    }
    return 0;
}
