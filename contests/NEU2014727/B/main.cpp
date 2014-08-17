#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+100;

int main()
{
    int T;
    scanf("%d",&T);
    int n,x;
    while(T--)
    {
        scanf("%d%d",&n,&x);
        x=min(x,n-x);
        printf("%d.0000\n",x*n-x*x);
    }
}
