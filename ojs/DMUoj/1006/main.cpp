#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000+100;
int feb[maxn+100];
int main()
{
    int n;
    feb[0]=1;
    feb[1]=1;
    for(int i=2;i<maxn;++i)
        feb[i]=(feb[i-1]+feb[i-2])%100000007;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",feb[n]);
    }
    return 0;
}
