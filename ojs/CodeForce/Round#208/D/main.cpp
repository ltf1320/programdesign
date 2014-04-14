#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3000+100;
const int inf=0x3f3f3f3f;
int N;
int dp[maxn][2];
int a[maxn],b[maxn],c[maxn];


int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&c[i]);

    dp[0][0]=a[0];
    dp[0][1]=-inf;
    int bsum,ci;
    for(int i=1;i<N;i++)
    {
        dp[i][0]=dp[i][1]=-inf;
        bsum=0;
        ci=i-1;
        for(int j=i-1;j>=0;j--)
        {
            dp[i][0]=max(dp[i][0],a[i]+dp[j][0]-a[j]+b[j]+bsum);
            if(j<i-1)
            {
                dp[i][0]=max(dp[i][0],a[i]+dp[j][0]+bsum-b[ci]+c[ci]);
                if(c[j]-b[j]>c[ci]-b[ci])
                    ci=j;
            }
            dp[i][1]=max(dp[i][1],b[i]+dp[j][0]+bsum);
            dp[i][1]=max(dp[i][1],b[i]+dp[j][1]+bsum);
            bsum+=b[j];
        }
    }
    printf("%d\n",max(dp[N-1][0],dp[N-1][1]));
    return 0;
}
