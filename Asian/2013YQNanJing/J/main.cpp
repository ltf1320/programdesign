#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
int N,M;
int num[31][maxn];
int sum[31][maxn];

int getN(int a)
{
    int res=0;
    while(a)
    {
        res++;
        a/=10;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int t,tn;
    int l,r,res;
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&t);
            tn=getN(t);
            num[tn][i]=1;
            for(int j=0;j<31;j++)
                sum[j][i]=sum[j][i-1]+num[j][i];
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&l,&r);
            l+=i;
            r-=i;
            if(r<=l)
                puts("0");
            else
            {
                res=0;
                tn=0;
                for(int j=0;j<31;j++)
                {
                    tn=sum[j][r]-sum[j][l-1];
                    res+=tn*(tn-1)/2;
                }
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
