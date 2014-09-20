#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <pthread>
using namespace std;
const int maxn=50000+100;
const int maxm=250;

int ng[2][maxm];
int dp[maxn];

int N,M;
int a[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        M=sqrt(N)+1;
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);
        memset(ng,-1,sizeof(ng));
        ng[0][0]=0;
        dp[0]=1;
        for(int i=1;i<N;i++)
        {
            bool flag=0;
            ng[i&1][0]=i;
            dp[i]=i+1;
            for(int j=1;j<=M;j++)
            {
                if(flag)
                    ng[i&1][j]=ng[!(i&1)][j];
                else
                {
                    if(a[i]==a[ng[!(i&1)][j-1]])
                    {
                        flag=1;
                        ng[i&1][j]=ng[!(i&1)][j];
                    }
                    else
                    {
                        ng[i&1][j]=ng[!(i&1)][j-1];
                    }
                }
                if(ng[i&1][j]==-1){
                    dp[i]=min(dp[i],j*j);
                    break;
                }
                dp[i]=min(dp[i],dp[ng[i&1][j]]+j*j);
            }
        }
        printf("%d\n",dp[N-1]);
    }
    return 0;
}
