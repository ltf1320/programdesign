#include <iostream>
#include <cstdio>
using namespace std;
long long d,l,r;
void exgcd(long long a,long long b)
{
    if(b==0)
    {
        l=1;
        r=0;
        d=a;
    }
    else
    {
        exgcd(b,a%b);
        long long tem=l;
        l=r;
        r=tem-a/b*r;
    }
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    long long x,y,m,n,L;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L))
    {
        exgcd(m-n,L);
        if((y-x)%d)
        {
            printf("Impossible\n");
            continue;
        }
        else
        {
            l*=(y-x)/d;
            l=l%L;
            if(l<0)
                l+=L;
            printf("%I64d\n",l);
        }
    }
    return 0;
}
