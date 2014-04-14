#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;

int N1[maxn],N2[maxn];
int n1,n2;

int dp[maxn][maxn];

void printdp()
{
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
            printf("%d ",dp[i][j]);
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int k1,k2;
    while(T--)
    {
        scanf("%d%d",&n1,&n2);
        for(int i=1;i<=n1;i++)
            scanf("%d",&N1[i]);
        for(int i=1;i<=n2;i++)
            scanf("%d",&N2[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(N1[i]!=N2[j])
                {
                    for(k1=i-1;k1;k1--)
                        if(N1[k1]==N2[j]) break;
                    for(k2=j-1;k2;k2--)
                        if(N2[k2]==N1[i]) break;
                    if(k1&&k2)
                        dp[i][j]=max(dp[i][j],dp[k1-1][k2-1]+2);
                }
            }
        printf("%d\n",dp[n1][n2]);
//        printdp();
    }
    return 0;
}
