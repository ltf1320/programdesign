#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

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

int main()
{
    int n;
    scanf("%d",&n);
    int gc,tt;
    cin>>gc;
    for(int i=1;i<n;i++)
    {
        cin>>tt;
        gc=gcd(gc,tt);
    }
    cout<<n*gc<<endl;
    return 0;
}
