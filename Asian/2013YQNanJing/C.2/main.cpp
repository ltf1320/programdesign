#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=60;
typedef long long LL;
LL res;
int a,b;

LL p2[maxn];

void pre()
{
    p2[0]=1;
    for(int i=1;i<maxn;i++)
        p2[i]=p2[i-1]<<1;
}

LL get(int b,int a)
{
    LL res=0;
    a=max(a,0);
    int now;
    LL jw=0;
    int i;
    for(i=0;((LL)1<<i)<=b||jw;i++)
    {
        now=b/p2[i+1]*p2[i]+max(b%p2[i+1]-p2[i]+1,(LL)0)-(a/p2[i+1]*p2[i]+max(a%p2[i+1]-p2[i]+1,(LL)0))+jw;
        jw=now/2;
        res+=jw;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(~scanf("%d%d",&a,&b))
    {
        printf("%lld\n",get(b,a-1));
    }
    return 0;
}
