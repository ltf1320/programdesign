#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
bool arr[maxn+10];


int main()
{
    freopen("in.txt","r",stdin);
    int n,s,res;
    scanf("%d",&n);
    while(n--)
    {
        memset(arr,0,sizeof(arr));
        scanf("%d",&s);
        for(int i=2;i<=s;++i)
        {
            for(int j=i;j<=s;j+=i)
            {
                arr[j]=!arr[j];
            }
        }
        res=0;
        for(int i=1;i<=s;++i)
            if(!arr[i]) res++;
        printf("%d\n",res);
    }
    return 0;
}
