#include <iostream>
#include <cstdio>
using namespace std;
double abs(const double a)
{
    return a>0?a:-a;
}
const double dev=1e-7;
int maxd;
double val;

bool ids(int d,double sum,int now)
{
    if(d==maxd)
    {
        if(abs(sum-val)<dev)
        {
            return 1;
        }
        else return 0;
    }
    int k=(maxd-d)/(abs(val-sum));
    for(int i=now; i<=k; ++i)
    {
        if(ids(d+1,sum+1.0/i,i+1))
        {
            cout<<"1/"<<i<<" ";
            return 1;
        }
    }
    return 0;
}


int main()
{/*
    freopen("in.txt","r",stdin);
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(!cin) break;
        maxd=0;
        val=static_cast<double>(a)/b;
        while(!ids(0,0,1))
            maxd++;
        cout<<endl;
    }
    */
    while(1)
        printf("%c",7);
    return 0;
}
