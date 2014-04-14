#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100000+100;
double C,F,X;
double sum[maxn];

void pre()
{
    sum[0]=1.0/2;
    for(int i=1;i<=X;i++)
        sum[i]=sum[i-1]+1.0/(2+i*F);
}

double getDT(int n)
{
    return X/(2+(n+1)*F)+(C-X)/(2+n*F);
}

double getT(int n)
{
    return X/(2+n*F)+C*sum[n-1];
}

bool judge(int n)
{
    if(getDT(n)<=0)
        return true;
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    double res;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%lf %lf %lf",&C,&F,&X);
        pre();
        if(2*C+F*C-F*X>=0)
        {
            res=X/2;
        }
        else
        {
            int l=0,r=X+1,m;
            while(l<=r)
            {
                m=(l+r)/2;
                if(judge(m))
                    l=m+1;
                else r=m-1;
            }
            res=getT(l);
        }
        printf("Case #%d: %.7f\n",cas,res);
    }
    return 0;
}
