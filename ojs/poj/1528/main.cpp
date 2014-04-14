#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int find(int n)
{
    int res=1;
    if(n==1) return 0;
    int sqn=sqrt(0.0+n);
    for(int i=2;i<=sqn;i++)
    {
        if(n%i==0)
        {
            res+=i;
            res+=n/i;
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    printf("PERFECTION OUTPUT\n");
    int n,sum;
    while(~scanf("%d",&n))
    {
        if(!n) break;
        printf("%5d  ",n);
        sum=find(n);
        if(sum==n)
            printf("PERFECT\n");
        else if(sum>n)
            printf("ABUNDANT\n");
        else printf("DEFICIENT\n");
    }
    printf("END OF OUTPUT");
    return 0;
}
