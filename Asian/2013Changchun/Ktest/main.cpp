#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
void find(LL n)
{
    LL now;
    for(LL i=2;i<=n;i++)
    {
        now=0;
        for(LL p=1;now<n;p++)
        {
            now=i*(1-pow(i,p))/(1-i);
            if(now==n)
            {
                printf("n=%I64d k=%I64d r=%I64d\n",n,i,p);
            }
        }
    }
}

int main()
{
    LL N;
    while(~scanf("%I64d",&N))
        find(N);
    return 0;
}
