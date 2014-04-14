#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20+10;
const int maxh=1000000+10;
int N,B;
bool dp[maxn*maxh];
int sum;
int main()
{
    freopen("in.txt","r",stdin);
    int tmp;
    while(~scanf("%d%d",&N,&B))
    {
        memset(dp,0,sizeof(dp));
        sum=0;
        dp[0]=1;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            for(int j=sum;j>=0;j--)
            {
                if(dp[j])
                {
                    dp[j+tmp]=1;
                }
            }
            sum+=tmp;
        }
        for(int i=B;i<=sum;i++)
        {
            if(dp[i])
            {
                printf("%d\n",i-B);
                break;
            }
        }
    }
    return 0;
}
