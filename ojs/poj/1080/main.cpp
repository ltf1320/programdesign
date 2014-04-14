#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=200;
int g1[maxn];
int g2[maxn];
int n1,n2;
const int inf=0x3f3f3f3f;
int score[10][10]={{0},{0,5,-1,-2,-1,-3},{0,-1,5,-3,-2,-4},{0,-2,-3,5,-2,-2},{0,-1,-2,-2,5,-1},{0,-3,-4,-2,-1,inf}};
//A for 1,C for 2,G for 3,T for 4,- for 5

int dp[maxn][maxn];

void input(int n,int *g)
{
    char ch=getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case 'A':g[i]=1;break;
            case 'C':g[i]=2;break;
            case 'G':g[i]=3;break;
            case 'T':g[i]=4;break;
        }
    }
    ch=getchar();
    g[n]=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int ns;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n1);
        input(n1,g1);
        scanf("%d",&n2);
        input(n2,g2);
        memset(dp,0,sizeof(dp));
        for(int i=n1-1;i>=0;i--)
            dp[i][n2]=dp[i+1][n2]+score[g1[i]][5];
        for(int i=n2-1;i>=0;i--)
            dp[n1][i]=dp[n1][i+1]+score[5][g2[i]];
        for(int i=n1-1;i>=0;i--)
            for(int j=n2-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j+1]+score[g1[i]][g2[j]];//直接匹配
                ns=dp[i][j+1]+score[5][g2[j]]; //g1插入-
                if(ns>dp[i][j]) dp[i][j]=ns;
                ns=dp[i+1][j]+score[g1[i]][5]; //g2插入-
                if(ns>dp[i][j]) dp[i][j]=ns;
            }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
