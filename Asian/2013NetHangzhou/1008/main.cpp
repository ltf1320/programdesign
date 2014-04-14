#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3000+10;
int N;
int str1[maxn],str2[maxn];
int len;
int dp[maxn][maxn];

void lcs()
{
    for(int i=1;i<=len;i++)
        for(int j=1;j<=len;j++)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
}

void printdp()
{
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
}

void work()
{
    lcs();
    int res=1;
    for(int k=0;k<N;k++)
        if(dp[2*N+1-k][2*N+1-k]-dp[N+1-k][N+1-k]>res)
            res=dp[2*N+1-k][2*N+1-k]-dp[N+1-k][N+1-k];
    printf("%d\n",res);
//    printdp();
}
void input()
{
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&str1[i]);
        str2[N-i+1]=str1[i];
    }
    for(int i=1;i<=N;i++)
    {
        str1[i+N]=str1[i+2*N]=str1[i];
        str2[i+N]=str2[i+2*N]=str2[i];
    }
    len=3*N;
}

void init()
{
    memset(dp,0,sizeof(dp));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        init();
        input();
        work();
    }
    return 0;
}
