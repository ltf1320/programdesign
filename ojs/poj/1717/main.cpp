#include <iostream>
#include <cstdio>
#include <cstring>
#define MID N*6
using namespace std;
const int maxn=1000+10;
const int maxk=1000*6*2+100;
const int inf=0x3f3f3f3f;
int N;
int dp[maxn][maxk];
int a[maxn],b[maxn];


int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=N;i++)
        for(int j=MID-i*6;j<=MID+i*6;j++)
            dp[i][j]=inf;
    dp[0][MID]=0;
    for(int i=0;i<N;i++)
    {
        for(int j=MID-i*6;j<=MID+i*6;j++)
        {
            dp[i+1][j+a[i+1]-b[i+1]]=min(dp[i+1][j+a[i+1]-b[i+1]],dp[i][j]);
            dp[i+1][j+b[i+1]-a[i+1]]=min(dp[i+1][j+b[i+1]-a[i+1]],dp[i][j]+1);
        }
    }
    for(int i=0;i<=MID;i++)
    {
        if(dp[N][MID+i]!=inf||dp[N][MID-i]!=inf)
        {
            printf("%d\n",min(dp[N][MID+i],dp[N][MID-i]));
            break;
        }
    }
    return 0;
}
