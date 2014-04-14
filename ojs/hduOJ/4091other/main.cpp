#define LL long long
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int n,s1,v1,s2,v2;
double d1,d2;
int choice;
LL ans;

LL cal(LL x)
{
    LL y=(n-s1*x)/s2;
    LL tans=x*v1+y*v2;
    if(tans>ans) ans=tans;
    return tans;
}


double getr()
{
    double p=1;
    int x=3;
    double pp=rand()/RAND_MAX;
    double ans=0;
    while(x--) ans+=p*pp*rand()/RAND_MAX,p-=p*pp;
    ans+=p*rand()/RAND_MAX;
    return ans;
}

int main()
{
    int t;
    int casno=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>s1>>v1>>s2>>v2;
        ans=0;
        d1=v1/s1;
        d2=v2/s2;
        cal(0);
        cal(n/s1);
        srand(time(NULL));
        int t=n/s1;
        for(int i=t-1;i>0&& i>t-40000;i--) cal(i);//范围改大一点
        for(int i=1;i<40000 && i<t;i++) cal(i);
   //     int m=30000;//完全没必要
   //     while(m--)
   //     {
   //         cal(int(getr()*t));
   //     }
        cout<<"Case #"<<casno++<<": ";
        cout<<ans<<endl;
    }
}
