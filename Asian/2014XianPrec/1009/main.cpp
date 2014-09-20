#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const LL MOD=10000007;
int N,M;
LL res;
double lnchoose(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    if (m < n/2.0)
    {
        m = n-m;
    }
    double s1 = 0;
    for (int i=m+1; i<=n; i++)
    {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n-m;
    for (int i=2; i<=ub; i++)
    {
        s2 += log((double)i);
    }
    return s1-s2;
}

LL choose(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    double res=exp(lnchoose(n, m));
    while(res>=MOD)
        res-=MOD;
    LL lres=(LL)(res+0.5);
    return lres;
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        res=0;
        LL n233=23;
        LL nc=choose(M+N-2,M-1);
        for(int i=1;i<=M;i++)
        {
            n233=n233*10+3;
            n233%=MOD;
            res+=n233*nc;//choose(M-i+N-1,M-i)
            res%=MOD;
            if(M!=i)
                nc=nc*(M-i)/(M-i+N-1);
        }
        nc=choose(M+N-2,N-1);
        for(int i=1;i<=N;i++)
        {
            int t;
            scanf("%d",&t);
            t%=MOD;
            res+=t*nc;
            //choose(M-i+N-1,N-i)
            res%=MOD;
            if(N!=i)
            nc=nc*(N-i)/(M-i+N-1);
        }
        printf("%lld\n",res);
    }
    return 0;
}
