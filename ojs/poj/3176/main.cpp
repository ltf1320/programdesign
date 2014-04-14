#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=400;
int dp[maxn][maxn];
int N;


int main()
{
 //   freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
            scanf("%d",&dp[i][j]);
    }
    for(int i=N-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            if(dp[i+1][j]>dp[i+1][j+1])
                dp[i][j]+=dp[i+1][j];
            else dp[i][j]+=dp[i+1][j+1];
    printf("%d\n",dp[1][1]);
    return 0;
}
