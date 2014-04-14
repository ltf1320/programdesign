#include <stdio.h>
#include <stdlib.h>
#pragma comment(linker,"/STACK:1024000000,1024000000")
#define N 10

//void GetFun(double x[N],double b[N]);

double ss[10],sy[10];
void GetFun(x,y)
double x[],y[];
{
	y[0]=x[0]*x[0]+x[1]*x[1]+x[2]*x[2]-1.0;
	y[1]=2.0*x[0]*x[0]+x[1]*x[1]-4.0*x[2];
	y[2]=3.0*x[0]*x[0]-4.0*x[1]+x[2]*x[2];

	return;
}
int main()
{
    GetFun(ss,sy);
    return 0;
}
