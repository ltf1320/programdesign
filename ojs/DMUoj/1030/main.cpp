#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e3+9;
int a[maxn],dp[maxn],now[maxn];

inline int cc(int a)
{
    return a*a;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,50,sizeof(dp));
        memset(now,0,sizeof(now));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            now[j]=max(now[j],a[i]+i);
            for(int j=1;j<=i;j++)
            dp[i]=min(dp[i],cc(now[j]-j)+dp[j-1]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
