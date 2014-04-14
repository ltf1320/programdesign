#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long lld;
const int maxn=10;
lld has[maxn];
lld p10[maxn];
const lld MOD=1E9+7;



int Pow(lld a,lld n,lld p)
{
    lld x=a;
    lld res=1;
    while(n)
    {
        if(n&1)
        {
            res=(res*x)%p;
        }
        n>>=1;
        x=(x*x)%p;
    }
    return res;
}
int Cm(lld n,lld m,lld p)
{
    lld a=1,b=1;
    if(m>n)return 0;//实现(a!/(a-b)!) * (b!)^(p-2)) mod p,由于n比较大，所以，此处不知道有什么好的优化
    while(m)
    {
        a=(a*n)%p;
        b=(b*m)%p;
        m--;
        n--;
    }
    return (a*Pow(b,p-2,p))%p;
}

lld AA(lld n)
{
    lld res=1;
    for(int i=2; i<n; i++)
    {
        res=res*i;
        if(res>MOD) res%=MOD;
    }
    return res;
}

int Lucas(lld n,lld m,lld p)
{
    if(m==0)
        return 1;
    return (Cm(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}

int main()
{
    int res;
    p10[0]=1;
    for(int i=1; i<10; i++)
        p10[i]=p10[i-1]*10;
    has[0]=0;
    has[1]=2;
    for(int i=2; i<10; i++)
        has[i]=has[i-1]*8+2*(p10[i-1]-has[i-1]);
    int n,p,nk;
    scanf("%d",&n);
    nk=0;
    p=n;
    for(int i=1; i<=9; i++)
    {
        for(int j=0; j<p%10; j++)
        {
            if(j==4||j==7)
                nk+=p10[i-1];
            else nk+=has[i-1];
        }
        p/=10;
    }
    res=(Lucas(n,nk,MOD)*AA(nk))%MOD;
    res*=AA(n-nk);
    res%=MOD;
    printf("%d\n",res);
    return 0;
}
