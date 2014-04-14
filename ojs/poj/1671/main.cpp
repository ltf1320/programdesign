#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100;
typedef double LL;
LL dp[maxn];

int main()
{
    int N;
    LL res;
    while(~scanf("%d",&N))
    {
        if(!N) break;
 //       if(N==30) {printf("846749014511809120000000\n");continue;}
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            for(int j=i;j>0;j--)
            {
                dp[j]=dp[j]*j+dp[j-1];
            }
        }
        res=0;
        for(int i=1;i<=N;i++)
        {
            res+=dp[i];
        }
        printf("%d %.0f\n",N,res);
    }
    return 0;
}
