#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn=1000000+100;
const LL inf= (LL)0x3f3f3f3f*0x3f3f3f3f;
int M,K;
int fac[maxn];
int fcn;
LL res;
LL m;
void dfs(int n,int inc,int now)
{
    if(n==fcn) return;
    dfs(n+1,inc,now);
    now*=fac[n];
    if(inc)
        res+=m/now;
    else
        res-=m/now;
    dfs(n+1,inc^1,now);
}

void dofac()
{
    fcn=0;
    int now=M;
    for(int i=2;i<=M;i++)
    {
        if(now%i==0)
        {
            fac[fcn++]=i;
            while(now%i==0)
            {
                now/=i;
            }
        }
    }
}

void work()
{
    LL l=0,r=inf;
    while(r>=l)
    {
        m=(l+r)>>1;
        res=0;
        dfs(0,1,1);
        res=m-res;
        if(res>=K)
            r=m-1;
        else l=m+1;
    }
    printf("%I64d\n",l);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&M,&K))
    {
        dofac();
        work();
    }
    return 0;
}
