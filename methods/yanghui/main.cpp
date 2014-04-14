#include <iostream>

using namespace std;

int main()
{
    int arr[100];
    arr[0]=1;
    int n;
    cin>>n;
    cout<<"1"<<endl;
    for(int i=1;i!=n;++i)
    {
        if(i%2==0)
            arr[i/2+1]=2*arr[i/2];
        for(int j=i/2;j!=0;--j)
            arr[i/2]+=arr[i/2-1];
        int *p;
        for(p=arr;p!=&arr[i/2]+1;++p)
            cout<<*p<<" ";
        if(i%2!=0)
            --p;
        for(--p;p!=arr;--p)
            cout<<*p<<" ";
        cout<<*p<<endl;
    }
    return 0;
}
