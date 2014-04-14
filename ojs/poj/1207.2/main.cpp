#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=10000;
const int inf=0x3f3f3f3f;
int num[maxn+10];
int dp[maxn+10][20];
int p2[20];

void pre()
{
    p2[0]=1;
    for(int i=1; i<20; i++)
        p2[i]=p2[i-1]*2;
}
int find2(int n)
{
    return (int)(log(1.0*n+1)/log(2.0));
}

bool in[maxn+10];
int dfs(int now)
{
    if(now<=maxn)
    {
        if(num[now]) return num[now];
        if(now%2)
            num[now]=dfs(3*now+1)+1;
        else num[now]=dfs(now/2)+1;
        return num[now];
    }
    else
    {
        if(now%2)
            return dfs(3*now+1)+1;
        else return dfs(now/2)+1;
    }
}

void RMQ()
{
    for(int i=1; i<=maxn; i++)
        dp[i][0]=num[i];
    for(int j=1; p2[j]<=maxn; j++)
        for(int i=1; i<=maxn-p2[j-1]; i++)
            dp[i][j]=max(dp[i][j-1],dp[i+p2[j-1]][j-1]);
}

int query(int a,int b)
{
    int pp=find2(b-a);
    return max(dp[a][pp],dp[b-p2[pp]+1][pp]);
}

int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    pre();
    memset(num,0,sizeof(num));
    num[1]=1;
    for(int i=2; i<=maxn; i++)
        dfs(i);
    RMQ();
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d %d ",a,b);
        if(a>b)
        {
            int t=a;
            a=b;
            b=t;
        }
        printf("%d\n",query(a,b));
    }
    return 0;
}
