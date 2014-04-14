
//#define END_
#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstdlib>
#include <stdexcept>
#include <cstring>
using namespace std;
int cal(int n);
int cal2(int n);
const int maxn=100000000;
int arr[maxn];

int main()
{
#ifndef END_
//    freopen("in.txt","r",stdin);
#endif
    int i,j;
    int max,maxi,tem;
    memset(arr,0,sizeof(arr));
    arr[1]=1;
    while(cin>>i>>j&&(max=0,maxi=i))
    {
        int upper=::max(i,j);
        int lower=min(i,j);
        for(int k=lower; k<=upper; k++)
        {
            if((tem=cal(k))>max)
            {
                maxi=k;
                max=tem;
            }
        }
        cout<<i<<" "<<j<<" "<<max<<endl;
    }
#ifndef END_
    cout<<"time used ="<<static_cast<double>(clock())/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}

int cal(int n)
{
    int result=0;
    if(n<0||n>=maxn)
    {
        cout<<n<<endl;
        throw runtime_error("n");
    }
    if(arr[n])
        return arr[n];
    else if(n%2)
        result=cal(3*n+1);
    else result=cal(n/2);
    ++result;
    arr[n]=result;
    return result;
}
/*
int zhan[100000];
int cal(int n)
{
    int result=0;
    int front=0,rear=0;
    zhan[front]=n;
    while(1)
    {
        now=next;
        if(arr[now])
        {
            result+=arr[now];
            break;
        }
        else if(now%2)
            next=now*3+1;
        else next=now/2;
        ++result;
        arr[now]=result;
    }
    return result;
}
*/
