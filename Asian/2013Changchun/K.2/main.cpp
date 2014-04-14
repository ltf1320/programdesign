#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn=1E12;
const LL inf=(LL)0x3f3f3f3f*0x3f3f3f3f;
LL N;
LL K,R;
LL mx;
int lg2(LL n)
{
    int res=1;
    while(n)
    {
        res++;
        n>>=1;
    }
    return res;
}

int comp(LL a,int p,LL s)
{
    LL now=a;
    LL sum=a;
    for(int i=1;i<p;i++)
    {
        if(sum>s)
            return 1;
        now*=a;
        sum+=now;
        if(now<=0)
            return 1;
    }
    if(sum==s) return 0;
    else if(sum>s) return 1;
    else return -1;
}

void find(LL n)
{
    int p=lg2(n);
    LL l,r,m;
    for(int i=p;i>=1;i--)
    {
        l=2,r=maxn;
        while(r>=l)
        {
            m=(r+l)/2;
            int t=comp(m,i,n);
            if(!t)
            {
                if(mx>i*m||(mx==i*m&&i<R))
                {
                    mx=i*m;
                    R=i;
                    K=m;
                }
                break;
            }
            else if(t==1)
                r=m-1;
            else l=m+1;
        }
    }
}

void work()
{
    mx=inf;
    find(N-1);
    find(N);
    printf("%I64d %I64d\n",R,K);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%I64d",&N))
        work();
    return 0;
}
