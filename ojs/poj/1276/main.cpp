#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=10+2;
const int maxc=100000+100;

struct DE
{
    int k,n;
    bool operator<(const DE &a) const
    {
        return k>a.k;
    }
};
//DE des[maxn];
int des[maxn*1000];
int N,res;
int cash;

//记录可行解的方法
/*
bool ss[maxc];
void work()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&des[i].n,&des[i].k);
    memset(ss,0,sizeof(ss));
    ss[0]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=cash;j>=0;j--)
        {
            if(ss[j])
            {
                for(int k=1;k<=des[i].n;k++)
                {
                    if(j+des[i].k*k<=cash)
                        ss[j+des[i].k*k]=1;
                }
            }
        }
    }
    for(int i=cash;i>=0;i--)
        if(ss[i])
        {
            res=i;
            break;
        }
}
*/
//dp倍增优化
int an;
int dp[maxn*1000];
int work2()
{
    int tn,tk;
    int tt;
    an=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&tn,&tk);
        tt=1;
        while(tt<tn)
        {
            tn-=tt;
            des[an++]=tt*tk;
            tt*=2;
        }
        if(tn>0)
        {
            des[an++]=tk*tn;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<an;i++)
        for(int j=cash;j>=des[i];j--)
            dp[j]=max(dp[j],dp[j-des[i]]+des[i]);
    return dp[cash];
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&cash))
    {
        scanf("%d",&N);

//        work();
//        printf("%d\n",res);
        printf("%d\n",work2());
    }
    return 0;
}
