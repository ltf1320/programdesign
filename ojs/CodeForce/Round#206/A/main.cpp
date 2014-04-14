#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
const int inf=0x3f3f3f3f;
int N,l,r,ql,qr;
int num[maxn];
int sum[maxn];

int main()
{
    scanf("%d%d%d%d%d",&N,&l,&r,&ql,&qr);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    int res=inf;
    if(l==r)
        res=sum[N]*l;
    else if(l<r)
    {
        if(N%2)
        {
            res=min(res,sum[N/2+1]*l+(sum[N]-sum[N/2+1])*r);
            for(int i=1;i<=N/2;i++)
                res=min(res,sum[N/2+1+i]*l+(sum[N]-sum[N/2+1+i])*r+ql*(2*i));
        }
        else
        {
            res=min(res,sum[N/2]*l+(sum[N]-sum[N/2])*r);
            for(int i=1;i<=N/2;i++)
                res=min(res,sum[N/2+i]*l+(sum[N]-sum[N/2+i])*r+ql*(2*i-1));
        }
    }
    else
    {
        if(N%2)
        {
            res=min(res,sum[N/2]*l+(sum[N]-sum[N/2])*r);
            for(int i=1;i<=N/2;i++)
                res=min(res,sum[N/2-i]*l+(sum[N]-sum[N/2-i])*r+qr*(2*i));
        }
        else
        {
            res=min(res,sum[N/2]*l+(sum[N]-sum[N/2])*r);
            for(int i=1;i<=N/2;i++)
                res=min(res,sum[N/2-i]*l+(sum[N]-sum[N/2-i])*r+qr*(2*i-1));
        }

    }
    printf("%d\n",res);
    return 0;
}
