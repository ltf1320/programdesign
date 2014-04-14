#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=100000;
const int CC=1000000007;
int dp[maxn+100][2];  //dp[i][0]:no 2*k last one

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n=0;
    while(n++<maxn)
    {
        dp[1][0]=1;
        dp[1][1]=0;
        dp[2][0]=1;
        dp[2][1]=1;
        dp[3][0]=3;
        dp[3][1]=1;
        for(int i=4;i<=n;++i)
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-3][0]+dp[i-3][1];
            dp[i][0]%=CC;
            dp[i][1]=0;
            for(int j=2;j<i;j+=2)
            {
                dp[i][1]+=dp[i-j][0];
                dp[i][1]%=CC;
            }
            if(i%2==0) dp[i][1]++;
//            printf("dp[%d][0]=%d\ndp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
        }
        printf("%d,",dp[n][0]+dp[n][1]);
    }
    return 0;
}
