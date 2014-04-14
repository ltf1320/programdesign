#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;

const int maxn=1000;

char s1[maxn],s2[maxn];
int dp[maxn][maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int l1,l2;
    while(~scanf("%s%s",s1+1,s2+1))
    {
        memset(dp,0,sizeof(dp));
        l1=strlen(s1+1);
        l2=strlen(s2+1);
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++)
            {
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}
