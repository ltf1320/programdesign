#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T,C;
    int q,d,n,p;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        cas++;
        scanf("%d",&C);
        q=C/25;
        d=C%25;
        n=d%10;
        d=d/10;
        p=n%5;
        n=n/5;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",cas,q,d,n,p);
    }
    return 0;
}
