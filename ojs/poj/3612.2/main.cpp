#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxh=100+10;
const int inf=0x3f3f3f3f;

int N,C;
int height[maxn];
int dp[maxn][maxh];

int hmax;

inline int mabs(int a)
{
    return a>0?a:-a;
}

void printdp()
{
    for(int i=0;i<N;i++)
    {
        for(int j=height[i];j<=hmax;j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&height[i]);
        hmax=max(hmax,height[i]);
    }
    int res=0;
    memset(dp,-1,sizeof(dp));
    for(int i=height[0];i<=hmax;i++)
        dp[0][i]=(i-height[0])*(i-height[0]);
    for(int i=1;i<N;i++)
    {
        for(int j=height[i];j<=hmax;j++)
        {
            dp[i][j]=min(dp[i-1][height[i-1]]+C*mabs(height[i]-height[i-1]),dp[i-1][j]+C*mabs(j-height[i]));
            if(height[i-1]+C/2<=hmax)
                dp[i][j]=min(dp[i][j],dp[i-1][height[i-1]+C/2]+C*mabs(height[i-1]+C/2-height[i]));
            if(height[i-1]+C<=hmax)
                dp[i][j]=min(dp[i][j],dp[i-1][height[i-1]+C]+C*mabs(height[i-1]+C-height[i]));
            dp[i][j]+=(j-height[i])*(j-height[i]);
        }
    }
    printdp();
    res=inf;
    for(int i=height[N-1];i<=hmax;i++)
    {
        res=min(res,dp[N-1][i]);
    }
    printf("%d\n",res);
    return 0;
}

