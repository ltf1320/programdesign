#include <iostream>
#include <cstdio>
using namespace std;

void pspace(int n)
{
    for(int i=0;i<n;++n)
        printf(" ");
}

void pg(int n)
{
    for(int i=0;i<n;++n)
        printf("-");
    printf("\n");
}

int getw(long long n)
{
    int res=1;
    while(n/=10) res++;
    return res;
}



void cal(long long a,long long b)
{
    long long res;
    int n,t;
    res=a*b;
    n=getw(res); //n求得了答案的位数
    t=getw(a);
    pspace(n-t);
    printf("%lld\n",a);
    t=getw(b);
    pspace(n-t);
    printf("%lld\n",b);
 //   pg(n);
}

int main()
{
    long long a,b;
    int pnum=0;
    while(~scanf("%lld%lld",&a,&b))
    {
        pnum++;
        printf("Problem %d\n",pnum);
        if(a==0 && b==0) break;


    }
    return 0;
}
