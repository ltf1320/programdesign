#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

long long multiply( long long a,long long b,long long n)
{
    long long exp,res=0;
    exp=a%n;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>n)
                res-=n;
        }
        exp<<=1;
        if(exp>n)
            exp-=n;
        b/=2;
    }
    return res;
}
long long paw(long long a,long long t,long long n)
{
    long long ans=1;
    a=a%n;
    while(t)
    {
        if(t%2==1)
            ans=multiply(ans,a,n);
        a=multiply(a,a,n);
        t/=2;
    }
    return ans;
}

bool miller_rabin(long long n,long long ti)
{
    if(n==2)
        return true;
    if(n<2||!(n&1))
        return false;
    long long p=n-1;
    long long k=0,a,x;
    while(p%2==0)
    {
        p/=2;
        k++;
    }
    long long ans;
    srand(time(0));
    for(int t=1; t<=ti; t++)
    {
        a=rand()%(n-1)+1;
        x=paw(a,p,n);
        for(int i=1; i<=k; i++)
        {
            ans=multiply(x,x,n);
            if(ans==1&&x!=1&&x!=n-1)
                return false;
            x=ans;
        }
        if(ans!=1)
            return false;
    }
    return true;
}




int main()
{
    long long a,d,n;
    long long k;
    freopen("in.txt","r",stdin);
    while(~scanf("%I64d%I64d%I64d",&a,&d,&n))
    {
        if(a==0 &&d==0 && n==0) break;
        k=0;
        while(1)
        {
            if(miller_rabin(a,1))
            {
                k++;
                if(k==n)
                {
                    printf("%I64d\n",a);
                    break;
                }
            }
            a+=d;
        }
    }
    return 0;
}
