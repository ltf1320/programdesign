#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    int x,y;
    int now;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            scanf("%d",&now);
            if(now)
            {
                x=i;y=j;
                break;
            }
        }
    printf("%d\n",abs(x-2)+abs(y-2));
    return 0;
}
