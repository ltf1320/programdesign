#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
int mid;
const int inf=0x3f3f3f3f;
int N;
int dp[2][2*maxn*maxm];
int s[maxn],f[maxn];
int mis[maxn],mas[maxn];

void printdp()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=mid+mis[i];j<=mid+mas[i];j++)
        {
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    mid=N*1000;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&s[i],&f[i]);
        mis[i]=mis[i-1];
        mas[i]=mas[i-1];
        if(s[i]<0) mis[i]+=s[i];
        else mas[i]+=s[i];
    }
    for(int j=0;j<=2*N*maxm;j++)
        dp[0][j]=-inf;
    dp[0][mid]=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=2*N*maxm;j++) //*2
            dp[i&1][j]=-inf;
        for(int j=mid+mis[i];j<=mid+mas[i];j++)
        {
            if(j==mid)
            {
                j++;
                j--;
            }
            dp[i&1][j]=max(dp[(i^1)&1][j],dp[(i^1)&1][j-s[i]]+f[i]);
        }
    }
    int res=0;
 //   for(int i=mid;i<=mid+mas[N];i++)
 //       printf("%d ",dp[N&1][i]);
//    puts("");
    for(int j=mid;j<=mid+mas[N];j++)
    {
        if(dp[N&1][j]>=0)
        res=max(res,j-mid+dp[N&1][j]);
    }
    printf("%d\n",res);
    return 0;
}
