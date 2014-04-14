#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=300+10;
const int maxp=30+5;
const int inf=0x3f3f3f3f;
int V,P;
int pos[maxn];
int mindis[maxn][maxn];
int dp[maxn][maxp];

int mabs(int a)
{
    return a>0?a:-a;
}

void getminDis()
{
    for(int i=1;i<=V;i++)
        for(int j=i+1;j<=V;j++)
        {
            int m=(i+j)/2;
            for(int k=i;k<=j;k++)
            {
                mindis[i][j]+=mabs(pos[m]-pos[k]);
            }
        }
}

void printDP()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=P;j++)
        {
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&V,&P))
    {
        pos[0]=0;
        for(int i=1;i<=V;i++)
        {
            scanf("%d",&pos[i]);
        }
        getminDis();
        for(int i=1;i<=V;i++)
            for(int j=1;j<=P;j++)
                dp[i][j]=inf;
        for(int i=1;i<=V;i++)
            dp[i][1]=mindis[1][i];
        for(int p=2;p<=P;p++)
            for(int i=p;i<=V;i++)
            {
                for(int k=p-1;k<=i;k++)
                    dp[i][p]=min(dp[i][p],dp[k][p-1]+mindis[k+1][i]);
            }
 //       printDP();
        printf("%d\n",dp[V][P]);
    }
    return 0;
}
