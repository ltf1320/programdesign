#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const double err=1E-10;

double get(double start,int N,int r,double p,int i)
{
    int r1=1,r2=1,r3=1;
    while(r1<=r&&r2<=r)
    {
        if(start<1)
        {
            start*=(N-r1+1);
            r1++;
        }
        else
        {
            start=start*p/r2;
            r2++;
        }
    }
    while(r1<=r&&r3<=i)
    {
        if(start<1)
        {
            start*=(N-r1+1);
            r1++;
        }
        else
        {
            start*=(1-p);
            r3++;
        }
    }
    while(r1<=r)
    {
        start*=(N-r1+1);
        r1++;
    }
    while(r3<=i)
    {
        start*=(1-p);
        r3++;
    }
    while(r2<=r)
    {
        if(start<err) return 0.0;
        start=start*p/r2;
        r2++;
    }
    return start;
}



int main()
{
    freopen("in.txt","r",stdin);
    int N;
    double p,res;
    while(cin>>N>>p)
    {
        N++;
        res=0.0;
        for(int i=0; i<N; i++)
        {
            res+=get((N-i-1),N+i-1,N-1,p,i)*p;
            res+=get((N-i-1),N+i-1,N-1,1-p,i)*(1-p);
        }
        cout<<res<<endl;
    }
    return 0;
}
