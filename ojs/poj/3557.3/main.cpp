#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=22;
int N;double p;
double dp[maxn];
double pp[maxn*maxn];
int C[maxn][maxn];

void pre()
{
    for(int i=1;i<maxn;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i][j-1]*(i-j+1)/j;
        }
    }
}

void cal()
{
    pp[0]=1;
    for(int i=1;i<N*N;i++)
        pp[i]=pp[i-1]*(1-p);
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(~scanf("%d%lf",&N,&p))
    {
        cal();
        dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            dp[i]=0;
            for(int j=1;j<i;j++)
            {
                dp[i]+=C[i-1][j-1]*dp[j]*pp[j*(i-j)];
            }
            dp[i]=1-dp[i];
        }
        printf("%.5f\n",dp[N]);
    }
    return 0;
}
