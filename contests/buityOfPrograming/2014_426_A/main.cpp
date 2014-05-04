//source here
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int mod=1000000007;
long long dp[1111];
int n,t;
int main()
{
    scanf("%d",&t);
    int cas=1;
    dp[1]=0;
    dp[2]=1;
    for (int i=3; i<1000; i++)
    {
        dp[i]=((dp[i-1]+dp[i-2])*(i-1))%mod;
    }
    while (t--)
    {
        scanf("%d",&n);
        long long ans=1;
        int num;
        ans=dp[n];
        for (int i=0; i<n; i++)
        {
            scanf("%d",&num);
            ans*=num;
            ans%=mod;
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}

