#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    double res=0;
    int M,R;
    int vn,un;
    scanf("%d%d",&M,&R);
    for(int i=0;i<M*M;i++)
    {
        vn=i/M+1;
        un=M+1+i%M;
        if(un-M-vn!=0)
            res+=sqrt((un-M-vn)*(un-M-vn)+1.0)*R;
        res+=2*R;
    }
    res/=(M*M);
    printf("%.10lf\n",res);
    return 0;
}
