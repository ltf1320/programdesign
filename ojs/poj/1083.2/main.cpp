#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=400+10;
int a[maxn];
int b[maxn];
int sum[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int N,res;
    int l,r,t;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        res=0;
        scanf("%d",&N);
        while(N--)
        {
            scanf("%d%d",&l,&r);
            if(l>r)
            {
                t=r;
                r=l;
                l=t;
            }
            a[(l+1)/2]++;
            b[(r+1)/2]++;
        }
        for(int i=1;i<maxn;i++)
        {
            sum[0]=0;
            sum[i]=sum[i-1]+a[i];
            res=max(res,sum[i]);
            sum[i]-=b[i];
        }
        printf("%d\n",res*10);
    }
    return 0;
}
