#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxm=30+5;
const int maxn=1000+10;
int M,T,N;
double tmp[maxm];
double dp[maxm][maxm];

double gl[maxn][2]; //0 for at least one ,1 for less than n

int main()
{
    freopen("in.txt","r",stdin);
    float g1,g2;//都做出一道的概率，冠军没做出N道的概率
    while(~scanf("%d%d%d",&M,&T,&N))
    {
        if(M==0&&T==0&&N==0) break;
        for(int i=0;i<T;i++)
        {
            for(int j=1;j<=M;j++)
                scanf("%lf",&tmp[j]);
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int k=1;k<=M;k++)
            {
                dp[k][0]=dp[k-1][0]*(1-tmp[k]);
                for(int h=1;h<=k;h++)
                    dp[k][h]=dp[k-1][h-1]*tmp[k]+dp[k-1][h]*(1-tmp[k]);
            }
            gl[i][0]=1-dp[M][0];
            gl[i][1]=0;
            for(int k=1;k<N;k++)
                gl[i][1]+=dp[M][k];

        }
        g1=1;
        for(int i=0;i<T;i++)
            g1*=gl[i][0];
        g2=1;
        for(int i=0;i<T;i++)
            g2*=gl[i][1];
        printf("%.3f\n",g1-g2);
    }
    return 0;
}
