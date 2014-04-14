#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

LL cal(LL t)
{
    if(t<6) return 0;
    LL sq=sqrt(t*1.0);
    LL res=0;
    if(sq&1)
        res++;
    res+=(t-4)>>1;
    return res;
}


int main()
{
 //   cout<<((LL)1<<63)-1<<endl;
 //   freopen("out.txt","w",stdout);
    int T;
    LL f,t,tt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&f,&t);
        if(f>t)
        {
            tt=t;
            t=f;
            f=tt;
        }
        printf("%I64d\n",cal(t)-cal(f-1));
    }
    return 0;
}
