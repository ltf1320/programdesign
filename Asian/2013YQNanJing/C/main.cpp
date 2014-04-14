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

LL get(int n)
{
    LL res=0;
    int now;
    LL jw=0;
    int i;
    for(i=0;((LL)1<<i)<=n||jw;i++)
    {
        now=n/p2[i+1]*p2[i]+max(n%p2[i+1]-p2[i]+1,(LL)0)+jw;
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
        printf("%I64d\n",get(b)-get(a-1));
    }
    return 0;
}
