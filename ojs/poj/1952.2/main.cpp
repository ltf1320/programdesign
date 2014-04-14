#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+10;
int N;
int a[maxn];
int dp[maxn];
int num[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
        num[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    num[i]=num[j];
                }
                else if(dp[i]==dp[j]+1)
                    num[i]+=num[j];
            }
            else if(a[i]==a[j])
                num[j]=0;
        }
    }
    int res=0,rn=0;
    for(int i=0;i<N;i++)
    {
        if(dp[i]>res)
        {
            res=dp[i];
            rn=num[i];
        }
        else if(dp[i]==res)
            rn+=num[i];
    }
    printf("%d %d\n",res,rn);
    return 0;
}
