#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int N,M;
struct Num
{
    static const LL MOD=(LL)1E15;
    LL n1,n2;
    Num operator*(const Num &a)const
    {
        Num res;
        res.n2=n2*a.n2;
        res.n1=res.n2/MOD+a.n2*n1+a.n1*n2;
        res.n2=res.n2%MOD;
        return res;
    }
    Num(){}
    Num(int a){n2=a;n1=0;}
    Num operator^(int a)
    {
        Num now=*this;
        Num res(1);
        while(a)
        {
            if(a&1)
                res=now*res;
            a>>=1;
            now=now*now;
        }
        return res;
    }
    Num operator/(int a)
    {
        Num res;
        LL last=n1%a;
        res.n1=n1/a;
        res.n2=(n2+last*MOD)/a;
        return res;
    }
    void print()
    {
        if(n1)
        {
            printf("%I64d",n1);
        }
        printf("%I64d",n2);
    }
};

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int gc;
    while(T--)
    {
        scanf("%d%d",&M,&N);
        gc=gcd(M,N);
        printf("%d/",N/gc);
        Num now(M);
        now=now^(N-1);
        now=now/gc;
        now.print();
        puts("");
    }
    return 0;
}
