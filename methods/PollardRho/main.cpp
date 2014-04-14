#include <iostream>
#include <cstdlib>
using namespace std;

//强伪素数测试miller
int xsushu[10]={2,3,5,7,11,13,17,19,23,29};

long long mod(long long a,long long s,long long n)   //a的s次方mod n
{
    long long res=1;
    while(s)
    {
        if(s&1)
            res=res*a%n;
        a=a*a%n;
        s>>=1;
    }
    return res;
}

bool miller(long long n,long long a=10)
{
    long long t,s;
    for(long long i=0;i<10;++i)
        if(n%xsushu[i]==0 && n!=xsushu[i]) return 0;
    for(long long i=0;i<a;++i)
    {
        s=(rand()*(n-2)/RAND_MAX)+1;
        t=mod(s,n-1,n);
        if(t!=1 && t!=-1)
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
        a=b;
    }
    return a;
}

long long pollar(long long n,long long c)  //找到一个因数
{
    long long i,k,x,y,d;
    i=1;
    k=2;
    x=rand()%n;
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

}

int main()
{
    long long n;
    while(cin>>n)
        cout<<miller(n)<<endl;
    return 0;
}
