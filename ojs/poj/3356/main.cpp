#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int l1,l2;
    while(~scanf("%d",&l1))
    {
        scanf("%s",s1+1);
        scanf("%d",&l2);
        scanf("%s",s2+1);
        for(int i=1; i<=l1; i++)
        {
            dp[i][0]=i;
        }
        for(int i=1; i<=l2; i++)
        {
            dp[0][i]=i;
        }
        for(int i=1; i<=l1; i++)
            for(int j=1; j<=l2; j++)
            {
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    dp[i][j]++;
                }
            }
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
                printf("%d ",dp[i][j]);
            putchar('\n');
        }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}
