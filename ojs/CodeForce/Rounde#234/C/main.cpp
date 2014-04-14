#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100000+100;

int n,m,x,y,z,p;

struct Point
{
    int x,y;
    void rotate90(int k)
    {
        int tx,ty;
        switch(k)
        {
        case 0:
            tx=x;
            ty=y;
            break;
        case 1:
            tx=y;
            ty=n-x+1;
            break;
        case 2:
            tx=n-x+1;
            ty=m-y+1;
            break;
        case 3:
            tx=m-y+1;
            ty=x;
            break;
        }
        x=tx;
        y=ty;
    }
    void hr(int k)
    {
        k=k%2;
        if(k)
        {
            y=m+1-y;
        }
    }
};
Point pnt[maxn];

int main()
{
  //  freopen("in.txt","r",stdin);
    int t;
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
    for(int i=0; i<p; i++)
        scanf("%d%d",&pnt[i].x,&pnt[i].y);
    x%=4;
    for(int i=0; i<p; i++)
    {
        pnt[i].rotate90(x);
    }
    if(x%2)
    {
        t=n;
        n=m;
        m=t;
    }
    for(int i=0; i<p; i++)
        pnt[i].hr(y);
    z=-z;
    z-=(z/4)*4-4;
    z%=4;
    for(int i=0; i<p; i++)
    {
        pnt[i].rotate90(z);
    }
    for(int i=0; i<p; i++)
        printf("%d %d\n",pnt[i].x,pnt[i].y);
    return 0;
}
