
#include <stdio.h>
#include <math.h>
using namespace std;


double abs(double a)
{
    return a>0?a:-a;
}

int main()
{
    freopen("in.txt","r",stdin);
    double x1,y1,x2,y2,r1,r2;
    double xc,yc,xd,yd;
    double L,k1,k2,x0,y0,r0;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2))
    {
        L=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    }
    return 0;
}


