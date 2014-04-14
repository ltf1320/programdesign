#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const double err=1E-12;

double ppow(double start,double p,int n)
{
    double now=p;
    while(n)
    {
        if(start<err) return 0.0;
        if(n&1)
            start*=now;
        n>>=1;
        now*=now;
    }
    return start;
}

int main()
{
    freopen("in.txt","r",stdin);
    int N,dd;
    int cas=1;
    double p,res,nowp,nowk;
    while(~scanf("%d%lf",&N,&p))
    {
        N++;
        res=0.0,nowp=1.0;
        nowk=nowp;
        dd=0;
        for(int i=0; i<N; i++)
        {
            if(i)
            {
                nowk=nowk*(1-p)*(N+i-1)/i;
                nowp=nowp*p*(N+i-1)/i;
                while(nowk>N||nowp>N)
                {
                    nowk*=p;
                    nowp*=(1-p);
                    dd++;
                }
            }
 //           res+=(N-i-1)*nowk*pn;
 //           res+=(N-i-1)*nowp*kpn;
            res+=ppow((N-i-1)*nowk,p,N-dd);
            res+=ppow((N-i-1)*nowp,1-p,N-dd);
        }
   //     cout<<res<<endl;
        printf("Case %d: %.6f\n",cas++,res);
    }
    return 0;
}
