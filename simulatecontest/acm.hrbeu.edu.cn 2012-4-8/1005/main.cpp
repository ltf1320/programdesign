#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int modExp(int a,int b,int n)
{
    int t=1,y=a;
    while(b)
    {
        if(b%2==1) t=t*y%n;
        y=y*y%n;
        b=b/2;
    }
    return t;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int b[60],result;
    int n;
    b[1]=0;b[2]=1;
    for(int i=3;i<=30;++i)
        b[i]=b[i-1]+b[i-2];
    cin>>n;
    while(cin)
    {
        result=modExp(2,b[n],2008);
        if(result<0) result+=2008;
        cout<<result<<endl;
        cin>>n;
    }
    return 0;
}
