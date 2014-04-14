#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;

const int MAX=1100;
const int INF=1000000000;
const double EPS=1.0e-8;
struct DATA
{
    int s,t,e;
}d[MAX];
bool cmp(DATA a,DATA b)
{
    return a.s<b.s;
}
int dp[MAX];
int main()
{
    freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
    int n=8;
    int m,r;
    int i,j;
    while(scanf("%d%d%d",&n,&m,&r)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&d[i].s,&d[i].t,&d[i].e);
        }
        sort(d,d+m,cmp);
        int ans=0;
        for(i=0;i<m;i++)
        {
            dp[i]=d[i].e;
            for(j=0;j<i;j++)
            {
                if(d[j].t+r<=d[i].s&&dp[j]+d[i].e>dp[i])
                {
                    dp[i]=dp[j]+d[i].e;
                }
            }
            if(dp[i]>ans)ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
