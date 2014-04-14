#include <iostream>
#include<cstdio>
using namespace std;

int s[10000];
void pailie(int n,int now=0)
{
    if(n==now)
    {
        for(int i=0;i<n;++i)
            cout<<s[i];
        cout<<" ";
        return;
    }
    for(int i=0;i<n;++i)
    {
        bool ok=1;
        for(int j=0;j<now;++j)
            if(s[j]==i+1) ok=0;
        if(ok)
        {
            s[now]=i+1;
            pailie(n,now+1);
        }
    }
}


int main()
{
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    pailie(n);
    return 0;
}
