#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int A,B,C,D,E;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&A,&B,&C,&D,&E);
        if(A==0&&B==0&&C==0)
        {
            printf("[0.0000, 0.0000]\n");
        }
        else if(A==0&&B==0)
        {
            if(D*D-4*E<0)
            {
                float a=(0.0+C)/(0.0+E-D*D/4);
                if(C>0)
                {
                    printf("(0, %.4f]\n",a);
                }
                else
                {
                    printf("[%.4f, 0)\n",a);
                }
            }
            else if(D*D-4*E>0)
            {
                float a=(0.0+C)/(0.0+E-D*D/4);
                if(C>0)
                {
                    printf("(-INF, %.4f] U (0, INF)\n",a);
                }
                else
                {
                    printf("(-INF, 0] U (%.4f, INF)\n",a);
                }
            }
            else
            {
                if(C>0)
                {
                    printf("(0, INF]\n");
                }
                else
                {
                    printf("[-INF, 0)\n");
                }
            }
        }
        else if(A==0)
        {
            a=-1.0*C/B;
            if(a*a+D*a+E==0)
            {
                printf("(-INF, 0) U (0,INF)\n");
            }
            else
            {
                if(4*C*C+4*B*(B*E-D*C)<0)
                {

                }
            }
        }
        else
        {

        }
    }
    return 0;
}
