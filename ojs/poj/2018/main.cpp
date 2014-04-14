#include <cstdio>
using namespace std;
typedef long long LL;
const int maxn=100000+100;
const int inf=0x3f3f3f3f;
int N,F;
LL num[maxn],sum[maxn];

bool check(LL v)
{
    LL now,pre;
    pre=sum[F]-sum[0]-v*F;
    if(pre>=0) return true;
    for(int i=F+1;i<=N;i++)
    {
        now=sum[i]-sum[i-F]-v*F;
        pre=pre+num[i]-v;
        if(now>pre)
            pre=now;
        if(pre>=0)
            return true;
    }
    return false;
}

int main()
{
  // freopen("in.txt","r",stdin);
    int l,r,m;
    while(~scanf("%d%d",&N,&F))
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%I64d",&num[i]);
            num[i]*=1000;
            sum[i]=sum[i-1]+num[i];
        }
        l=0,r=inf;
        while(r>=l)
        {
            m=(r+l)>>1;
            if(check(m))
                l=m+1;
            else r=m-1;
        }
        printf("%d\n",r);
    }
    return 0;
}
