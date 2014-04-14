#include<iostream>
#include <cstdio>
using namespace std;
const int maxn=10000000;
int arr[maxn];

int cal(int n)
{
    int i,res=0;
    for (i=2; i<=n; i++)
    {
        while(n>=i)
        {
            if(n%i==0)
            {
                res+=i;
                n=n/i;
            }
            else break;
        }
    }
    res++;
    return res%2;
}

int main()
{
    freopen("out.txt","w",stdout);
    int n,res;
    n=0;
    while(n++<maxn)
    {
        arr[n]=cal(n);
    }
    while(~scanf("%d",&n))
    {
        res=0;
        for(int i=1;i<n;++i)
        {
            res^=arr[i];
        }
        printf("%d\n",res&1);
    }
}
