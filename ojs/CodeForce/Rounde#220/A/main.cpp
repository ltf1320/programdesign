#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m;
int mabs(int a)
{
    return a>0?a:-a;
}

int getDis(int x,int y,int i,int j,int a,int b)
{
    int dx=mabs(x-i),dy=mabs(y-j);
    if(dx%a!=0||dy%b!=0)
        return inf;
    dx=dx/a;
    dy=dy/b;
    if(mabs(dx-dy)%2)
        return inf;
    if(dx==0&&dy==0) return 0;
    if(i+a>n&&i-a<1)
        return inf;
    if(j+b>m&&j-b<1)
        return inf;
    return max(dx,dy);
}


int main()
{
    int i,j,a,b;
    scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
    int res=inf;
    res=min(res,getDis(1,m,i,j,a,b));
    res=min(res,getDis(n,m,i,j,a,b));
    res=min(res,getDis(n,1,i,j,a,b));
    res=min(res,getDis(1,1,i,j,a,b));
    if(res==inf)
        puts("Poor Inna and pony!");
    else printf("%d\n",res);
    return 0;
}
