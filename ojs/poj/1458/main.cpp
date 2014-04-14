#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1024;

int dp[maxn][maxn];

char str1[maxn];
char str2[maxn];
int n1,n2;


int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0; i<maxn; i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    while(~scanf("%s%s",str1,str2))
    {
        n1=strlen(str1);
        n2=strlen(str2);
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                        dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        printf("%d\n",dp[n1][n2]);
    }
    return 0;
}
