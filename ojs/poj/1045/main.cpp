#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    double VS,R,C,w;
    double res;
    scanf("%lf%lf%lf%d",&VS,&R,&C,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&w);
        printf("%.3f\n",VS*C*R*w/sqrt(1+C*R*w*C*R*w));
    }
    return 0;
}
