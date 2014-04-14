#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=100000+100;

double getLen(int r,int i)
{
    if(i==1)
        return sqrt(2)*r+2*r;
    else
        return sqrt(2)*2*r+(i-1)*r*2;
}

int main()
{
    double res=0;
    int M,R;
    scanf("%d%d",&M,&R);
    res=1.0*M*2*R/M;
    for(int i=1;i<M;i++)
    {
        res+=2*(M-i)*getLen(R,i)/M;
    }
    printf("%.10lf\n",res/M);
    return 0;
}
