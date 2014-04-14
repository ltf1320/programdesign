#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000;
int arr[maxn];
int main()
{
 //   freopen("in.txt","r",stdin);
    int n,res,m;
    while(~scanf("%d",&n))
    {
        res=0;
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        for(int i=0;i<n-1;++i)
        {
            m=0;
            for(int j=i+1;j<n;++j)
            {
                if(m>arr[j])
                {
                    continue;
                }
                if(arr[i]<arr[j])
                {
                    res++;
                    break;
                }
                res++;
                if(arr[j]>m)
                    m=arr[j];
            }
//            printf("i=%d  res=%d  m=%d\n",i,res,m);
        }
        printf("%d\n",res);
    }
    return 0;
}
