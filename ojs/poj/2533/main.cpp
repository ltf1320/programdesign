#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int dp[maxn];
int num[maxn];
int N;
int len;
int find(int v)
{
    int l=0,r=len;
    int m=(r+l)>>1;
    while(r-l>1)
    {
        if(dp[m]>v) r=m;
        else l=m;
        m=(l+r)>>1;
    }
    return r;
}

int main()
{
    freopen("in.txt","r",stdin);
    int k;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    dp[0]=inf;
    len=1;
    dp[len]=num[0];
    for(int i=1;i<N;i++)
    {
        if(num[i]>dp[len])
        {
            len++;
            dp[len]=num[i];
        }
        else
        {
            k=find(num[i]);
            if(dp[k]==num[i]) k++;
            if(dp[k]>num[i]) dp[k]=num[i];
        }
    }
    printf("%d\n",len);
    return 0;
}
