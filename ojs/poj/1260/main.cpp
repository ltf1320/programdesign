#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N;
struct Peals
{
    int num,price;
};
Peals pls[maxn];
int dp[maxn];
int pnum[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int a,p;
    int t1,t2;
//    int res;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&a,&p);
            pls[i].num=a;
            pls[i].price=p;
        }
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            /*
            t1=dp[i-1]-(10+pnum[i-1])*pls[i-1].price+(10+pls[i].num+pnum[i-1])*pls[i].price;
            t2=dp[i-1]+(10+pls[i].num)*pls[i].price;
            if(t1<t2)  //²¢
            {
                dp[i]=t1;
                pnum[i]=pnum[i-1]+pls[i].num;
            }
            else
            {
 //               printf("%d\n",i);
                dp[i]=t2;
                pnum[i]=pls[i].num;
            }
            */
            dp[i]=dp[i-1]+(10+pls[i].num)*pls[i].price;
            t1=pls[i].num;
            for(int j=i-1;j>0;j--)
            {
                t1+=pls[j].num;
                if(dp[i]>dp[j-1]+(10+t1)*pls[i].price)
                    dp[i]=dp[j-1]+(10+t1)*pls[i].price;
            }
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}
