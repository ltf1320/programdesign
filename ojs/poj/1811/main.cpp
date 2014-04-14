#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
const long long MAX=(long long)1<<62;
long long MIN;
//强伪素数测试miller
//int xsushu[10]={2,3,5,7,11,13,17,19,23,29};

long long mod_mut(long long a,long long b,long long n) //(a*b)%n
{
    long long res=0;
    a%=n;
    while(b)
    {
        if(b&1)
        {
            res+=a;
            res%=n;
        }
        a<<=1;
        a%=n;
        b>>=1;
    }
    return res;
}

long long mod(long long a,long long s,long long n)   //a的s次方mod n
{
    long long res=1;
    while(s)
    {
        if(s&1)
            res=mod_mut(res,a,n);
        a=mod_mut(a,a,n);
        s>>=1;
    }
    return res;
}

bool witness(long long a,long long n)
{
    long long x,d=1,i=ceil(log(n-1.0)/log(2.0));
    for(;i>=0;i--)
    {
        x=d;d=mod_mut(d,d,n);
        if(d==1 && x!=1 && x!=n-1) return 1;
        if(((n-1)&(1<<i))>0) d=mod_mut(d,a,n);
    }
    return (d==1?0:1);
}

bool miller(long long n,long long a=20)
{
    long long s;
    if(n==1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    srand(time(0));
    for(long long i=0;i<a;++i)
    {
        s=(rand()*(n-2)/RAND_MAX)+1;
        if(witness(s,n))
            return 0;
    }
    return 1;
}
//end miller

//因数分解 pollard rho

long long gcd(long long a,long long b)
{
    long long t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

long long pollar(long long n,long long c)  //找到一个因数
{
    srand(time(0));
    long long i,k,x,y,d;
    i=1;
    k=2;
    x=rand()%(n-1)+1;
    y=x;
    while(1)
    {
        i++;
        x=(mod(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(d>1 && d<n)
            return d;
        if(y==x) return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}

void search(long long n,long long c)
{
    if(n==1) return;
    long long m;
    if(miller(n))
    {
        if(n<MIN) MIN=n;
        return;
    }
    while(1)
    {
        m=pollar(n,c--);
        if(m<n) break;
    }
    if(m<MIN) MIN=m;
    search(m,c);
    search(n/m,c);
}

int main()
{
    freopen("in.txt","r",stdin);
    long long n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        if(miller(n))
        {
            printf("Prime\n");
            continue;
        }
        MIN=MAX;
        search(n,240);
        printf("%I64d\n",MIN);
    }
    return 0;
}
