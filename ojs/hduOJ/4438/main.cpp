#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main()
{
    freopen("in.txt","r",stdin);
    double Q,P;
    double q1,q2;
    LL X,Y;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%lf%lf",&X,&Y,&P,&Q);
        q1=(1-Q)*X+Q*P*Y+Q*P*X;  //tigher
        q2=Q*Y+(1-Q)*P*X+(1-Q)*P*Y; //wolf
        if(q1>q2)
            printf("tiger %.4f\n",q1);
        else printf("wolf %.4f\n",q2);
    }
    return 0;
}
