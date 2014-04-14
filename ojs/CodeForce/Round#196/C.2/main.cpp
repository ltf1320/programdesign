#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL MOD=1000000009;
int N,M,K;

LL Mpow(int n,int p) ///LL
{
    LL now=n;
    LL res=1;
    while(p)
    {
        if(p&1)
        {
            res*=now;
            if(res>=MOD)
                res=res%MOD;
        }
        p>>=1;
        now*=now; ///
        if(now>=MOD)
            now%=MOD;
    }
    res%=MOD;
    return res;
}

int getRes(int q)
{
    LL res=K*Mpow(2,q+1);
    res+=-2*K-q*K+M;
    res=(res+MOD)%MOD; ///
    return (int)res;
}

int getStart()
{
    for(int i=0;i<=N/K;i++)
    {
        if((M-i*K)*(LL)K<=(N-i*K+1)*(LL)(K-1)) ///LL
            return i;
    }
    return 0;
}

int getStart2()
{
    int i=((LL)M*K-(LL)N*K-K+N+1)/K;
    if((LL)i*K<((LL)M*K-(LL)N*K-K+N+1))
        i++;
    return max(i,0); ///
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    int q=getStart2();
    printf("%d\n",getRes(q));
    return 0;
}
