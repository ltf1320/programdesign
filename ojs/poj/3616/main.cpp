#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=1000000+100;
const int maxm=1000+100;
int N,M,R;
LL dp[maxn];
struct Inter
{
    int start,end,eff;
    bool operator<(const Inter &a)const
    {
        return end<a.end;
    }
};
Inter ins[maxm];

void input()
{
    for(int i=0;i<M;i++)
        scanf("%d%d%d",&ins[i].start,&ins[i].end,&ins[i].eff);
}

void work()
{
    sort(ins,ins+M);
    LL pre;
    int preend=0;
    for(int i=0;i<M;i++)
    {
        for(int j=preend+1;j<=ins[i].end;j++)
            dp[j]=dp[preend];
        if(ins[i].start-R>=0) pre=dp[ins[i].start-R];
        else pre=0;
        dp[ins[i].end]=max(dp[ins[i].end],pre+ins[i].eff);
        preend=ins[i].end;
    }
//    for(int i=0;i<=preend;i++)
//        printf("%I64d ",dp[i]);
//    puts("");
    printf("%I64d\n",dp[preend]);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&N,&M,&R))
    {
        memset(dp,0,sizeof(dp));
        input();
        work();
    }
    return 0;
}
