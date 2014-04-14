#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxh=100+10;
const int inf=0x3f3f3f3f;
int N,C;
int nh;
int dp[2][maxh];
int now;
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d%d",&N,&C);
    scanf("%d",&nh);
    for(int i=0;i<nh;i++)
        dp[0][i]=inf;
    for(int i=nh;i<=100;i++)
        dp[0][i]=(i-nh)*(i-nh);
    for(int i=1;i<N;i++)
    {
        now=inf;
        scanf("%d",&nh);
        for(int j=100;j>=nh;j--)
        {
            now=min(now,dp[(i&1)^1][j]+C*j);
            dp[i&1][j]=now-C*j+(j-nh)*(j-nh);
        }
        for(int j=0;j<nh;j++)
            dp[i&1][j]=inf;
        now=inf;
        for(int j=0;j<=100;j++)
        {
            now=min(now,dp[(i&1)^1][j]-C*j);
            if(j>=nh)
                dp[i&1][j]=min(dp[i&1][j],now+C*j+(j-nh)*(j-nh));
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
