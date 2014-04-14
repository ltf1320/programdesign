#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000;
int arr[maxn+100];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n==0) {printf("where is people?\n");continue;}
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        printf("%d\n",arr[k-1]);
    }
    return 0;
}
