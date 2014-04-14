#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
char str[maxn];
int dp[2][maxn];

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
        scanf("%c",&str[i]);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(str[i]==str[n-j+1])
                dp[i&1][j]=dp[(i&1)^1][j-1]+1;
            else dp[i&1][j]=max(dp[(i&1)^1][j],dp[i&1][j-1]);
        }
    printf("%d\n",n-dp[n&1][n]);
    return 0;
}
