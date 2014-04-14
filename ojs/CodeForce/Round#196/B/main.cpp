#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,c,d;

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}


int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ac=lcm(a,c);
    int bd=lcm(b,d);
    int p,q,g;
    if(ac/a*b<=d*ac/c)
    {
        p=ac/a*b;
        q=d*ac/c;
        g=gcd(p,q);
        p/=g;
        q/=g;
    }
    if(ac/c*d<=b*ac/a)
    {
        p=ac/c*d;
        q=b*ac/a;
        g=gcd(p,q);
        p/=g;
        q/=g;
    }
    if(bd/b*a<=c*bd/d)
    {
        p=bd/b*a;
        q=c*bd/d;
        g=gcd(p,q);
        p/=g;
        q/=g;
    }
    if(bd/d*c<=a*bd/b)
    {
        p=bd/d*c;
        q=a*bd/b;
        g=gcd(p,q);
        p/=g;
        q/=g;
    }
    printf("%d/%d",q-p,q);
    return 0;
}
