#include <iostream>
#include <cstdio>
#include <cstring>

#define p2(x) ((x)*(x))
using namespace std;
typedef long long LL;
const int maxn=2000+10;
const int inf=0x3f3f3f3f;
int N;

int num[maxn];
int dp[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int pnow;
    while(~scanf("%d",&N))
    {
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);
        dp[1]=p2(num[1]);
        for(int i=2;i<=N;i++)
        {
            dp[i]=dp[i-1]+p2(num[i]);
            pnow=num[i];
            for(int j=i-1;j>0;j--)
            {
                pnow=max(pnow+1,num[j]);
                dp[i]=min(dp[i],dp[j-1]+p2(pnow));
            }
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}
