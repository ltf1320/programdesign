#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=12;

LL p10[maxn];

void pre()
{
    p10[0]=1;
    for(int i=1;i<maxn;i++)
        p10[i]=p10[i-1]*10;
}

LL getSum(LL n)
{
    if(n<0) return 0;
    LL now,res=1,left,has;
    for(int i=1;n>p10[i];i++)
    {
        now=(n/p10[i-1])%10;
        left=n%p10[i-1];
        has=n/p10[i];
        if(now==0)
            res+=(has-1)*p10[i-1]+left+1;
        else
            res+=has*p10[i-1];
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    LL a,b;
    pre();
    while(~scanf("%I64d%I64d",&a,&b)&&~a&&~b)
    {
        printf("%I64d\n",getSum(b)-getSum(a-1));
    }
    return 0;
}
