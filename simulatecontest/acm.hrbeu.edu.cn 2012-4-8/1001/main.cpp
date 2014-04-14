#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
   freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(1)
    {
        if(n==0)
            break;
        cout<<'+';
        for(int i=0;i<n;++i)
            cout<<'-';
        cout<<'+'<<endl;
        for(int i=0;i<n;++i)
        {
            cout<<"|";
            for(int j=0;j<n;++j)
                cout<<" ";
            cout<<"|";
            cout<<endl;
        }
        cout<<'+';
        for(int i=0;i<n;++i)
            cout<<'-';
        cout<<'+'<<endl;
        for(int i=0;i<n;++i)
        {
            cout<<"|";
            for(int j=0;j<n;++j)
                cout<<" ";
            cout<<"|";
            cout<<endl;
        }
        cout<<'+';
        for(int i=0;i<n;++i)
            cout<<'-';
        cout<<'+'<<endl;
        cin>>n;
        if(n) cout<<endl<<endl;
    }
    return 0;
}
