#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int a,b,c;
double get(double x)
{
    return a*x*x*x/3+b*x*x/2+c*x;
}

int main()
{
    freopen("in.txt","r",stdin);
    double x1,x2;
    int dt;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        dt=b*b-4*a*c;
        if(dt<=0||a==0)
        {
            printf("%.2f\n",0.0);
            continue;
        }
        x1=(-b-sqrt(1.0*dt))/(2*a);
        x2=(-b+sqrt(1.0*dt))/(2*a);
        printf("%.2f\n",abs(get(x2)-get(x1)));
    }
    return 0;
}
