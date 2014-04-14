//dp[i]=min{dp[j]+sum[i]-sum[j]-(i-j)*a[j+1]}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=500000+100;
int N,k;
LL num[maxn];
LL sum[maxn];
LL dp[maxn];

int que[maxn];
int head,tail;

LL getUp(int i,int j)
{
    return dp[i]-sum[i-1]+num[i+1]*i-(dp[j]-sum[j-1]+num[j+1]*j);
}

LL getdown(int i,int j)
{
    return num[i+1]-num[j+1];
}

bool judge(int i,int j,int k)
{
    if(getdown(j,k)==0) return true;
    if(getUp(i,j)*getdown(j,k)<getUp(j,k)*getdown(i,j)) //=
        return true;
    return false;
}

void work()
{
    head=tail=0;
    que[tail]=0;
    dp[0]=0;
 //   que[tail]=0;
 //   dp[0]=0;
    for(int i=k;i<=N;i++)
    {
        while(tail>head&&getUp(que[head+1],que[head])<=i*getdown(que[head+1],que[head]))
            head++;
        dp[i]=dp[que[head]]+sum[i]-sum[que[head]]-(i-que[head])*num[que[head]+1];
        while(tail>head&&judge(i,que[tail],que[tail-1]))
            tail--;
        que[++tail]=i;
    }
    printf("%I64d\n",dp[N]);
}

void input()
{
    scanf("%d%d",&N,&k);
    num[0]=sum[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%I64d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
