#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2000+100;
int N,M,k;
const double err=1E-7;
double p1,p2,p3,p4;
double p21,p31,p41;
double pp[maxn];

double dp[maxn][maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int end;
    while(~scanf("%d%d%d",&N,&M,&k))
    {
        scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
        if(p4<err)
        {
            puts("0.00000");
            continue;
        }
        p21=p2/(1-p1);
        p31=p3/(1-p1);
        p41=p4/(1-p1);
        dp[1][1]=p4/(1-p1-p2);
        pp[0]=1;
        for(int i=1;i<=N;i++)
            pp[i]=pp[i-1]*p21;
        for(int i=2;i<=N;i++)
        {
            dp[i][i]=0;
            for(int j=1;j<i;j++)
                dp[i][i]+=pp[i-j-1]*p31*dp[i-1][j];
            end=min(i,k);
            for(int j=1;j<=end;j++)
                dp[i][i]+=pp[i-j]*p41;
            dp[i][i]/=(1-pp[i]);
            dp[i][1]=p21*dp[i][i]+p41;
            for(int j=2;j<=end;j++)
                dp[i][j]=dp[i][j-1]*p21+p31*dp[i-1][j-1]+p41;
            for(int j=k+1;j<i;j++)
                dp[i][j]=dp[i][j-1]*p21+p31*dp[i-1][j-1];
        }
        printf("%.5f\n",dp[N][M]);
    }
    return 0;
}
