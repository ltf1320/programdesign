#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1000;

int dp[maxn];
int len;

int find(int a)
{
    int l=0,r=len;
    int m;
    while(r-l>1)
    {
        m=(l+r)>>1;
        if(dp[m]>a) l=m;
        else r=m;
    }
    return l;
}

int main()
{
    freopen("in.txt","r",stdin);
    int now,k;
    int cas=1;
    bool ed=0;
    while(~scanf("%d",&now))
    {
        memset(dp,0,sizeof(dp));
        len=0;
        dp[0]=maxn;
        if(now==-1) break;
        if(ed) putchar('\n');
        ed=1;
        while(now!=-1)
        {
            if(now<=dp[len])
            {
                len++;
                dp[len]=now;
            }
            else
            {
                k=find(now);
                if(dp[k]>=now) k++;
                if(dp[k]<now) dp[k]=now;
            }
            scanf("%d",&now);
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cas++,len);
    }
    return 0;
}
