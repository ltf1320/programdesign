#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int a,b,t;
    double k=(sqrt(5)+1)/2;
    while(~scanf("%d%d",&a,&b))
    {
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        t=b-a;
        if(a==(int)(k*t))
            printf("%d\n",0);
        else printf("%d\n",1);
    }
    return 0;
}
