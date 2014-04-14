#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%4==0) printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
