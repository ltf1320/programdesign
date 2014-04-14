/*
0 3 5 3
2 0 3 3
2 0 2 3

*/

#include <iostream>
#include <cstdio>
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    long long res;
    if(b==0)
    {
        x=1;
        y=0;
        res=a;
    }
    else
    {
        res=exgcd(b,a%b,x,y);
        long long t=x;
        x=y;
        y=t-a/b*y;
    }
    return res;
}

  int main()
{
    freopen("in.txt","r",stdin);
    long long a,b,c,k,d,mn,diff;
    long long x,y;
    while(cin>>a>>b>>c>>k)
    {
        if(!cin) break;
        if((a==0)&&(b==0)&&(c==0)&&(k==0))
            break;
        mn=static_cast<long long>(1)<<k;
        diff=b-a;
        d=exgcd(c,mn,x,y);
        if(diff%d)
            printf("FOREVER\n");
        else
        {
            x*=diff/d;
            x=x%(mn/d);     //x每次增加或减少mn/d都是可行解，找到最小的大于或等于0的可行解
            if(x<0)
                x+=mn/d;
            cout<<x<<endl;
        }
    }
    return 0;
}
