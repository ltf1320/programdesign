#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int x,int y)
{
    if(!x||!y) return x>y?x:y;
    for(int t;t=x%y;x=y,y=t);
    return y;
}

int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(gcd(N,M)==1)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
