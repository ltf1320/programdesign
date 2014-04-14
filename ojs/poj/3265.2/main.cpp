#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxp=300+10;
const int maxm=1000+10;
const int inf=0x3f3f3f3f;
int M,P;
struct Pro
{
    int now,next;
};
Pro prs[maxp];

int dp[maxp][maxm];


void printdp()
{
    for(int i=0;i<=P;i++)
    {
        for(int j=0;j<=M;j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&M,&P);
    for(int i=0;i<P;i++)
        scanf("%d%d",&prs[i].now,&prs[i].next);
    for(int i=0;i<=P;i++)
        for(int j=0;j<=M;j++)
            dp[i][j]=inf;
    dp[0][M]=1;
    int suma,sumb;
    for(int i=0;i<P;i++)
        for(int j=0;j<=M;j++)
            if(dp[i][j]!=inf)
            {
                sumb=0;
                suma=0;
                dp[i][M]=min(dp[i][M],dp[i][j]+1);
                for(int k=0;k<P-i;k++)
                {
                    sumb+=prs[i+k].next;
                    suma+=prs[i+k].now;
                    if(suma<=j&&sumb<=M)
                    {
                        dp[i+k+1][M-sumb]=min(dp[i+k+1][M-sumb],dp[i][j]+1);
                    }
                    else break;
                }
            }
    int res=dp[P][0]+1;
    for(int i=1;i<=M;i++)
        res=min(dp[P][i]+1,res);
    printf("%d\n",res);
 //   printdp();
    return 0;
}
