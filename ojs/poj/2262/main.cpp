#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool isn[1000000]={0};
    int i,j;
    int n=1000000;
    int sqrtn=static_cast<int>(sqrt(0.0+n));
    for(i=4;i<n;i+=2)
        isn[i]=1;
    for(i=3;i<sqrtn;i+=2)
        if(isn[i]==0)
        {
            for(int s=2*i,j=i*i;j<n;j+=s)
                isn[j]=1;
        }
    int xn;
    cin>>xn;
    while(1)
    {
        if(xn==0)
            break;
        bool is=0;
        for(i=3;i<xn/2;i+=2)
        {
            if(isn[i]==0)
                if(isn[xn-i]==0)
                {
                    is=1;
                    break;
                }
            if(is)
                break;
        }
        cout<<xn<<" = "<<i<<" + "<<xn-i<<endl;
        cin>>xn;
    }
}
