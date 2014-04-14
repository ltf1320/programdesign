#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i=0;
        if(n>m)
        {
            for(; i<m; i++)
                printf("BG");
            for(; i<n; i++)
                printf("B");
            putchar('\n');
        }
        else
        {
            for(; i<n; i++)
                printf("GB");
            for(; i<m; i++)
                printf("G");
            putchar('\n');
        }
    }
    return 0;
}
