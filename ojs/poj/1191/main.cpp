#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=20;
const int bn=10;
const double inf=1050960000.0;
int N,sum;
double ave;
int board[bn][bn];
double dp[maxn][bn][bn][bn][bn];
double s[bn][bn][bn][bn];
double ks[bn][bn];

void work()
{
    for(int d=0; d<=N; d++)  //!
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                for(int k=i; k<=8; k++)
                    for(int p=j; p<=8; p++)
                        dp[d][i][j][k][p]=inf;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            for(int k=i; k<=8; k++)
                for(int p=j; p<=8; p++)
                    dp[1][i][j][k][p]=s[i][j][k][p];
    for(int n=2; n<=N; n++)
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                for(int k=i; k<=8; k++)
                    for(int p=j; p<=8; p++)
                        for(int d=1; d<8; d++)
                        {
                            dp[n][i][j][k][p]=min(dp[n-1][i][j][d][p]+s[d+1][j][k][p],dp[n][i][j][k][p]);
                            dp[n][i][j][k][p]=min(s[i][j][d][p]+dp[n-1][d+1][j][k][p],dp[n][i][j][k][p]);
                            dp[n][i][j][k][p]=min(dp[n-1][i][j][k][d]+s[i][d+1][k][p],dp[n][i][j][k][p]);
                            dp[n][i][j][k][p]=min(s[i][j][k][d]+dp[n-1][i][d+1][k][p],dp[n][i][j][k][p]);
                        }
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    sum=0;
}

void input()
{
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
        {
            scanf("%d",&board[i][j]);
            sum+=board[i][j];
        }
    for(int i=1; i<=8; i++) ks[i][0]=0;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            ks[i][j]=ks[i][j-1]+board[i][j];
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            for(int k=i; k<=8; k++)
                for(int p=j; p<=8; p++)
                {
                    for(int q=i; q<=k; q++)
                        s[i][j][k][p]+=ks[q][p]-ks[q][j-1];
                    s[i][j][k][p]*=s[i][j][k][p];
                }
    ave=1.0*sum/N;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    init();
    input();
    work();
    double res=sqrt(dp[N][1][1][8][8]/N-ave*ave);
    printf("%.3f\n",res);
    return 0;
}
