#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL N,M,K;
LL T,cas=1;

void sort(LL* a,LL* b,LL* c)
{
    LL t;
    if(*a<*b)
    {
        t=*b;
        *b=*a;
        *a=t;
    }
    if(*b<*c)
    {
        t=*b;
        *b=*c;
        *c=t;
    }
    if(*a<*b)
    {
        t=*b;
        *b=*a;
        *a=t;
    }
}

LL get1(LL N,LL M,LL K)
{
    /*
    if(N==1&&M==1&&K==1) return 0;
    if(N==1) return M*K-1;
    sort(&N,&M,&K);
    if(N%2)
        return (get1(N/2,M,K)+get1(N/2+1,M,K)+1);
    else return (2*get1(N/2,M,K)+1);
    */
    return N*M*K-1;
}

LL g(LL a,LL b)
{
    if(b>a){LL t=b;b=a;a=t;}
    if(a==1) return 0;
    if(a&1)
        return g(a/2,b)+g(1,b)+2;
    else return g(a/2,b)+1;
}

LL qr(LL a)
{
    LL i=0;
    LL k=1;//艹，这都能写成i=1,k=2
    while(k<a)
    {
        i++;
        k<<=1;
    }
    return i;
}

LL get2(LL N,LL M,LL K)
{
    return (qr(N)+qr(M)+qr(K));
}






int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    scanf("%I64d",&T);
    while(cas<=T)
    {
        scanf("%I64d%I64d%I64d",&N,&M,&K);
        printf("Case #%I64d: %I64d %I64d\n",cas++,get1(N,M,K),get2(N,M,K));
    }
    return 0;
}
