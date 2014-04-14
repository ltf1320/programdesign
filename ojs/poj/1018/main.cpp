#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int Inf=0x3f3f3f3f;
const int maxn=110;
struct BP
{
    int maxb,sump;
    double bp;
    bool operator<(const BP a)const
    {
        return maxb<a.maxb;
    }
    BP(int maxb_ ,int sump_):maxb(maxb_),sump(sump_)
    {
        bp=static_cast<double>(maxb)/sump;
    }
    BP() {}
};
BP dp[11][maxn];
int num[11];


int main()
{
    freopen("in.txt","r",stdin);
    int t,n,s,ms;
    double res;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ms=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&s);
            if(ms<s) ms=s;
            num[i]=s;
            for(int j=0; j<s; ++j)
            {
                scanf("%d%d",&dp[i][j].maxb,&dp[i][j].sump);
                dp[i][j].bp=static_cast<double>(dp[i][j].maxb)/dp[i][j].sump;
            }
            sort(dp[i],dp[i]+s);
            for(int j=s;j<100;++j)
                dp[i][j].bp=dp[i][j].maxb=dp[i][j].sump=0;
        }
        res=0;
        for(int j=0;j<ms;++j)
            for()
    }
    return 0;
}
