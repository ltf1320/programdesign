#include <iostream>
#include <cstdio>
//6442640941
using namespace std;
typedef unsigned long long LL;

LL gcd(LL a,LL b)
{
    LL t;
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
//   freopen("out.txt","w",stdout);
    LL T;
    // scanf("%d",&T);
    cin>>T;
    LL N,s1,v1,s2,v2,t;
    LL dres,lgbs,lgbv;
    LL res,st;
    LL cas=1;
    while(T--)
    {
        cin>>N>>s1>>v1>>s2>>v2;
        if(v1*s2<v2*s1)
        {
            t=v1;
            v1=v2;
            v2=t;
            t=s1;
            s1=s2;
            s2=t;
        }
        lgbs=(s1/gcd(s1,s2))*s2;
        lgbv=(lgbs/s1)*v1;
        dres=0;
        if(N>=2*lgbs)
        {
            dres=(N/lgbs-1)*lgbv;
            N%=lgbs;
            N+=lgbs;
        }
        if(s1<s2)
        {
            t=v1;
            v1=v2;
            v2=t;
            t=s1;
            s1=s2;
            s2=t;
        }
        res=0;
        for(int i=0; i*s1<=N; i++)
        {
            st=i*v1+((N-i*s1)/s2)*v2;
            if(st>res) res=st;
        }
        cout<<"Case #"<<cas++<<": "<<dres+res<<endl;
    }
    return 0;
}
