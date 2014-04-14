#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=100+10;
int N;
int num[maxn];
int dp[maxn][maxn];

int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&N);
    int cnt=0;
    int res;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]) cnt++;
    }
    res=0;
    for(int i=0;i<N;i++)
    {
        dp[i][i]=cnt;
        for(int j=i+1;j<=N;j++)
        {
            if(num[j-1])
                dp[i][j]=dp[i][j-1]-1;
            else dp[i][j]=dp[i][j-1]+1;
            res=max(res,dp[i][j]);
        }
    }
    printf("%d\n",res);
    return 0;
}
