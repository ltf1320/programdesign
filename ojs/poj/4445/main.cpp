#include <iostream>
#include <cstdio>
#include <cstring>
#define KK
using namespace std;
const double g=9.8;
const err=1E-8;
const int maxn=200+10;
double v,dt;
int H,L1,L2,R1,R2;

double getDt(int L)
{
    return 1.0*L*L-2.0*g*L*L/v/v*(1.0/2*g*L*L/v/v-H);
}
double getL(int L)
{
    return 1.0*(-L-dt)/(1.0*g*L*L/v/v);
}
double getR(int L)
{
    return 1.0*(-L+dt)/(g*L*L/v/v);
}

struct Range
{
    double l,r;
};
Range ami[maxn];
Range fre[maxn];

int main()
{
    double an1,an2,an3,an4;
    int ant,fnt;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        scanf("%d%d%d%d%d",&H,&L1,&R1,&L2,&R2);
        for(int i=0; i<N; i++)
        {
            scanf("%lf",&v);
            dt=getDt(L1);
            if(dt>=0.0)
            {
                an1=getL(L1);
                an2=getR(L1);
            }
        }
    }
    return 0;
}
