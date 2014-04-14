#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const double err=1E-7;
int a,b,c,d,e;
double x1,x2;

double f(double x)
{
    return (a*x*x+b*x+c)/(x*x+d*x+e);
}

void work()
{
    if(b-a*d==0&&c-a*e==0)
    {
        printf("[%.4f %.4f]\n",(double)A,(double)A);
        return;
    }
    double dt=d*d-4*e;
    if(dt<0) //分母无解,可以把A提出来
    {
        if(AD-B==0) //分子为常数
        {
            double k=f(d/2.0);
            if(k>0)
            {
                printf("(%.4f %.4f]\n",0.0,k);
                return;
            }
            else
            {
                printf("[%.4f %.4f)\n",k,0.0);
                return;
            }
        }
        else//分子为一次方程
        {
            /* 这项不可能
            if(b*d-a*d*d-2*c+2*a*e==0)//导数分母为常数
            {
                if(b*e-c*d==0)//函数为常数
                {
                    printf("[%.4f %.4f]\n",f(0),f(0));
                    return;
                }
                else if(b*e-c*d>0)//单调增
                {

                }
            }
            */
            double k=(b*e-c*d)/(1.0*b*d-a*d*d-2*c+2*a*e);
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
