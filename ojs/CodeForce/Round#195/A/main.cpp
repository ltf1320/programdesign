#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int mabs(int a)
{
    return a>0?a:-a;
}

int main()
{
    int x,y;
    int rx,ry;
    scanf("%d%d",&x,&y);
    rx=ry=mabs(x)+mabs(y);
    if(x<0) rx*=-1;
    if(y<0) ry*=-1;
    if(rx<0)
        printf("%d %d %d %d\n",rx,0,0,ry);
    else printf("%d %d %d %d\n",0,ry,rx,0);
    return 0;
}
