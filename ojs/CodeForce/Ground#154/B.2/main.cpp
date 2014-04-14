#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5000+10;
const int KN=5000;
int data[maxn];
int sum[maxn];
int N;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tmp,res;
    while(~scanf("%d",&N))
    {
        memset(data,0,sizeof(data));
        memset(sum,0,sizeof(sum));
        for(int i=0; i<N; i++)
        {
            scanf("%d",&tmp);
            data[tmp]++;
        }
        for(int i=1;i<=KN;i++)
        {
            sum[i]=sum[i-1]+data[i];
        }
        res=N;
        for(int i=1; i<=KN/2; i++)
        {
            if(N-sum[2*i]+sum[i-1]<res)
                res=N-sum[2*i]+sum[i-1];
        }
        printf("%d\n",res);
    }
    return 0;
}
