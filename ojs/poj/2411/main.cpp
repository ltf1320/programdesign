#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=12;
const int maxm=(1<<12);
int W,H;
LL dp[maxn][maxm];
LL ans[maxn][maxn];
int pp;

bool check(int st)
{
    for(int i=0;i<W;i++)
    {
        if((st&(1<<i)))
        {
            if(!(st&(1<<(i+1))))
            return false;
            i++;
        }
    }
    return true;
}

bool check(int si,int sj)
{
    for(int i=0;i<W;i++)
    {
        if(si&(1<<i))
        {
            if(sj&(1<<i))
            {
                if(i==W-1||!((si&(1<<(i+1)))&&(sj&(1<<(i+1)))))
                    return false;
                i++;
            }
        }
        else
        {
            if(!(sj&(1<<i)))
                return false;
        }
    }
    return true;
}

int main()
{
    memset(ans,-1,sizeof(ans));
    while(~scanf("%d%d",&H,&W)&&H&&W)
    {
        if(H*W%2)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        if(H<W)
        {
            int t=H;
            H=W;
            W=t;
        }
        if(~ans[H][W])
        {
            printf("%I64d\n",ans[H][W]);
            continue;
        }
        pp=1<<W;
        for(int i=0;i<pp;i++)
            if(check(i))
                dp[H][i]=1;
        for(int h=H-1;h>0;h--)
        {
            for(int i=0;i<pp;i++)
                for(int j=0;j<pp;j++)
                {
                    if(check(i,j))
                        dp[h][i]+=dp[h+1][j];
                }
        }
        ans[H][W]=dp[1][pp-1];
        printf("%I64d\n",dp[1][pp-1]);
    }
    return 0;
}
