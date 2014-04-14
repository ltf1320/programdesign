#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=100000+100;
const int maxh=100+10;
const int inf=0x3f3f3f3f;
int N,C;
int height[maxn];

int dp[2][maxh];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++)
        scanf("%d",&height[i]);
    for(int i=0;i<height[0];i++)
        dp[0][i]=inf;
    for(int i=height[0];i<=100;i++)
        dp[0][i]=(i-height[0])*(i-height[0]);
    int now;
    for(int i=1;i<N;i++)
    {
        now=inf;
        for(int j=100;j>=height[i];j--)
        {
            now=min(now,dp[(i&1)^1][j]+C*j);
            dp[i&1][j]=now-C*j+(j-height[i])*(j-height[i]);
        }
        for(int j=0;j<height[i];j++)
            dp[i&1][j]=inf;
        now=inf;
        for(int j=0;j<=100;j++)
        {
            now=min(now,dp[(i&1)^1][j]-C*j);
            if(j>=height[i])
                dp[i&1][j]=min(dp[i&1][j],now+C*j+(j-height[i])*(j-height[i]));
        }
//        for(int j=0;j<=100;j++)
//            printf("%d ",dp[i&1][j]);
//        puts("");
    }
    now=inf;
    for(int i=0;i<=100;i++)
        now=min(now,dp[(N-1)&1][i]);
    printf("%d\n",now);
}
