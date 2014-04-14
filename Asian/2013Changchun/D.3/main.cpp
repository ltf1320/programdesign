#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double err=1E-7;
int A,B,C,D,E;

double mabs(double a)
{
    return a>0?a:-a;
}

double f(double x)
{
    return (B*x+C)/(x*x+D*x+E);
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&A,&B,&C,&D,&E);
        if(A)
        {
            B-=D*A;
            C-=E*A;
        }
        if(B==0)
        {
            if(C==0)
            {
                printf("[%.4f, %.4f]\n",1.0*A,1.0*A);
                continue;
            }
            int d=D*D-4*E;
            if(d<0)
            {
                if(C>0)
                    printf("(%.4f, %.4f]\n",1.0*A,1.0*A+f(-1.0*D/2));
                else
                    printf("[%.4f, %.4f)\n",1.0*A+f(-1.0*D/2),1.0*A);
            }
            else if(d==0)
            {
                if(C>0)
                    printf("(%.4f, INF)\n",1.0*A);
                else
                    printf("(-INF, %.4f)\n",1.0*A);
            }
            else //! d>0
            {
                if(C>0)
                    printf("[-INF, %.4f] U (%.4f, INF)\n",1.0*A+f(-1.0*D/2),1.0*A);
                else
                    printf("(-INF, %.4f) U [%.4f, INF)\n",1.0*A,1.0*A+f(-1.0*D/2)); //C/(E-1.0*D*D/4)
            }
        }
        else
        {
            int d1=4*C*C+4*B*B*E-4*B*C*D;
            int d2=D*D-4*E;
            if(d1==0)//可约分
            {
                double a,b;
                if(C)
                    a=1.0/B,b=1.0*E/C;
                else
                    a=1.0/B,b=1.0*D/B;  //!/B ,1.0*
                double k1=-1.0*C/B; //!
                if(mabs(a*k1+b)<=err) //分母等于分子平方
                {
                    printf("(-INF, %.4f) U (%.4f, INF)\n",1.0*A,1.0*A);
                }
                else
                {
                    double p=1.0/(a*k1+b);
                    if(p<0)
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n",p+1.0*A,p+1.0*A,1.0*A,1.0*A);
                    else
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n",1.0*A,1.0*A,p+1.0*A,p+1.0*A);
                }
            }
            else if(d1>0)
            {
                double x1=(2*C+sqrt(1.0*d1))/(-2*B);
                double x2=(2*C-sqrt(1.0*d1))/(-2*B);
                double xx1=(-1.0*D-sqrt(1.0*d2))/2;
                double xx2=(-1.0*D+sqrt(1.0*d2))/2;
                if(x2<x1)
                {
                    double tt=x1;
                    x1=x2;
                    x2=tt;
                }
                double k1=-1.0*D/2,k2=-1.0*C/B;
                if(d2>0)
                {
                    if(k1<x2&&k1>x1) //!
                        puts("(-INF, INF)");
                    else
                    {
                        double f1=f(x1),f2=f(x2);
                        if(k1<x1)
                        {
                            if(B>0)
                            {
                                if(f2>f1)
                                    printf("(-INF, %.4f] U [%.4f, INF)\n",1.0*A+f1,1.0*A+f2);
                                else
                                    puts("(-INF, INF)");
                            }
                            else
                            {
                                if(f2<f1)
                                    printf("(-INF, %.4f] U [%.4f, INF)\n",1.0*A+f2,1.0*A+f1);
                                else
                                    puts("(-INF, INF)");
                            }
                        }
                        else
                        {
                            if(B>0)
                            {
                                if(f1>f2)
                                    printf("(-INF, %.4f] U [%.4f, INF)\n",1.0*A+f2,1.0*A+f1);
                                else
                                    puts("(-INF, INF)");
                            }
                            else
                            {
                                if(f1<f2)
                                    printf("(-INF, %.4f] U [%.4f, INF)\n",1.0*A+f1,1.0*A+f2);
                                else
                                    puts("(-INF, INF)");
                            }
                        }
                    }
                }
                //------
                else if(d2==0)
                {
                    if(B>0&&B*D<2*C)
                    {
   //                     double kkkk=f(max(x1,x2));
                        printf("[%.4f, INF)\n",A+f(min(x1,x2)));
                    }
                    else if(B>0&&B*D>2*C)
                    {
   //                     double kkkk=f(min(x1,x2));
                        printf("(-INF, %.4f]\n",A+f(max(x1,x2)));
                    }
                    else if(B<0&&B*D>2*C)
                    {
  //                      double kkkk=f(max(x1,x2));
                        printf("(-INF, %.4f]\n",A+f(min(x1,x2)));
                    }
                    else if(B<0&&B*D<2*C)
                    {
    //                    double kkkk=f(min(x1,x2));
                        printf("[%.4f, INF)\n",A+f(max(x1,x2)));
                    }
                    else
                    {
                        int tt=0;
                        printf("%d",1/tt);
                    }
                }
                else  //d2<0
                {
                    double f1=f(x1),f2=f(x2);
                    printf("[%.4f, %.4f]\n",A+min(f1,f2),A+max(f1,f2));
                }
            }
            else
            {
                if(d2>0)
                    puts("(-INF, INF)");
                else
                {
                    int tt=0;
                    printf("%d",1/tt);
                }
            }
        }
    }
    return 0;
}
