#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double tx,px;
double ang;
double a,b,h;

double getjf(double x)
{
    return -a*x*x*x/3+b*x*x/2;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&px,&tx,&ang);
        b=tan(ang);
        a=(b*tx+(px-tx)*b)/(2*tx*px-tx*tx);
        h=-a*tx*tx+b*tx;
        double res=getjf(tx)+h*(px-tx)/2;
        printf("%.3f\n",res);
    }
    return 0;
}
