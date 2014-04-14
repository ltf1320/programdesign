#include <iostream>
#include <cstdio>
using namespace std;
long long n,m;

long long gcd(long long a,long long b)
{
    long long t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}


long long phi(long long n)
{
    int rea=n;
    for(int i=2;i<=n;++i)
    {
        if(n%i==0)
        {
            rea=rea-rea/i;
            do n/=i;
            while(n%i==0);
        }
    }
    return rea;
}



int main()
{
    freopen("in.txt","r",stdin);
    long long s;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        s=gcd(m,n);
        printf("%I64d\n",phi(n)+phi(m)-phi(n/s*m));
    }
    return 0;
}
