#include <iostream>
#include<cstring>
#include<cstdio>
#include <cmath>
using namespace std;

const int maxn=1100;
double dp[maxn][maxn];
double p[maxn][maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,s;
    double ii,jj;
    while(cin>>n>>s)
    {
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        p[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=s;j++)
            {
                ii=i+0.0;
                jj=j+0.0;
                dp[i][j]=p[i-1][j]*(n-i+1)*j/(n*s-(i-1)*j)*(dp[i-1][j]+1.0*n*s*(n-i+1)*j/(n*s-(ii-1)*jj)/(n*s-(ii-1)*jj))\
                        +p[i][j-1]*(s-j+1)*i/(n*s-i*(j-1))*(dp[i][j-1]+1.0*n*s*(s-j+1)*i/(n*s-(jj-1)*ii)/(n*s-(jj-1)*ii))\
                        +p[i-1][j-1]*(n-i+1)*(s-j+1)/(n*s-(i-1)*(j-1))*(dp[i-1][j-1]+1.0*n*s*(n-i+1)*(s-j+1)/(n*s-(ii-1)*(jj-1))/(n*s-(ii-1)*(jj-1)));
                p[i][j]=p[i-1][j]*(n-i+1)*j/(n*s-(i-1)*j)\
                       +p[i][j-1]*(s-j+1)*i/(n*s-(j-1)*i)\
                       +p[i-1][j-1]*(n-i+1)*(s-j+1)/(n*s-(i-1)*(j-1));
                dp[i][j]/=p[i][j];
            }
 //       printf("%.4lf  ",p[n][s]);
        printf("%.4lf\n",dp[n][s]);
    }
    return 0;
}
