#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
long long top=0,pri[100];
long long multiply( long long a,long long b,long long n)
{
    long long exp,res=0;
    //这个就是用加法，来模拟乘法，为了防止运算的数太大，
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
long long gcd(long long a,long long b)
{
    long long c;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
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
            //注意这个判断！
            return false;
    }
    return true;
}
long long pollard_rho(long long a,long long k,long long n)
{
    srand(time(0));
    long long x=rand()%(n-1)+1;
    long long i=1,t=2;
    long long y=x;
    while(1)
    {
        i++;
        x=(multiply(x,x,n)+k)%n;
        long long ans=gcd(y-x,n);
        if(ans>1&&ans<n)
            return ans;
        if(x==y)
            return n;
        if(t==i)
        {
            y=x;
            t*=2;
        }
    }
}
void search(long long n,long long k)
{
    if(miller_rabin(n,10))
    {
        pri[++top]=n;
        return ;
    }
    else
    {
        long long p=n;
        while(p>=n)
            p=pollard_rho(p,k--,n);
        search(p,k);
        search(n/p,k);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int cas,i;
    long long n;
    cin>>cas;
    while(cas--)
    {
        scanf("%lld",&n);
        if(miller_rabin(n,10ll))
            printf("Prime\n");
        else
        {
            top=0;
            search(n,180);
            long long min=-1;
            for(i=1; i<=top; i++)
            {
                if(min<0||min>pri[i])
                    min=pri[i];
            }
            printf("%lld\n",min);
        }
    }
    return 0;
}
