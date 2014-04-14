#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int N;
    int a,b,c;
    scanf("%d",&N);
    if(N==1)
    {
        scanf("%d",&a);
        if(a)
            printf("BitLGM\n");
        else printf("BitAryo\n");
    }
    else if(N==2)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        c=b-a;
        double f=(sqrt(5)+1)/2;
        if(a!=(int)(f*c))
            printf("BitLGM\n");
        else printf("BitAryo\n");
    }
    else
    {
        scanf("%d%d%d",&a,&b,&c);
        int k=a^b^c;
        if(k)
            printf("BitLGM\n");
        else printf("BitAryo\n");
    }
    return 0;
}
