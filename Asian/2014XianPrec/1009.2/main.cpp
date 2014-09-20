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

int used[MOD+10];

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
  //  while(~scanf("%d%d",&N,&M))
    N=1;
    for(int M=1;M<10000000;M++)    {


        res=0;
        LL n233=23;
        LL nc=choose(M+N-2,M-1);
        for(int i=1;i<=M;i++)
        {
            n233=n233*10+3;
            n233%=MOD;
            res+=n233*nc;
            res%=MOD;
            if(M!=i)
                nc=nc*(M-i)/(M-i+N-1);
        }
        //printf("%lld\n",res);
        if(used[res])
        {
            printf("%d %d %d\n",M,used[res],res);
       //     break;
        }
        used[res]=M;
    }
    puts("");

    return 0;
}
