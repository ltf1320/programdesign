#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn= 1000000+1000;
const int inf=0x3f3f3f3f;
int N;
int dp[maxn];
LL bx[5000+10];
LL by[5000+10];

int res,now;

int main()
{
    int T;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%lld%lld",&bx[i],&by[i]);
        }
        for(int i=0;i<=bx[N-1];i++)
            dp[i]=inf;
        res=inf;
        dp[0]=0;
        for(int i=1; i<N; i++)
        {
            for(int now=bx[i];now>=bx[0];now--)
            {
                if((bx[i]-now)*(bx[i]-now)+(by[i]-by[0])*(by[i]-by[0])>by[i]*by[i])
                    break;
                if(2*bx[i]-now>=bx[N-1])
                {
    //                if((by[i]-by[N-1])*(bx[N-1]-(2*bx[i]-now))>=(by[N-1]-by[0])*(bx[i]-bx[N-1]))
                       res=min(res,dp[now]+1);
                }
                else dp[2*bx[i]-now]=min(dp[now]+1,dp[2*bx[i]-now]);
            }
        }
        printf("%d\n",res==inf?-1:res);
    }
    return 0;
}

