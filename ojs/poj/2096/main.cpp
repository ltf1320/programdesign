#include <iostream>
#include<cstring>
#include<cstdio>
#include <cmath>
using namespace std;

const int maxn=1100;
double dp[maxn][maxn];

int main()
{

    freopen("in.txt","r",stdin);
    int n,s;
    while(cin>>n>>s)
    {
        memset(dp,0,sizeof(dp));
        for(int i=n; i>=0; --i)
            for(int j=s; j>=0; --j)
            {
                if(i==n&&j==s) continue;
                dp[i][j]=(1.0*(n-i)*j/s/n*dp[i+1][j]+1.0*i*(s-j)/s/n*dp[i][j+1]+1.0*(n-i)*(s-j)/n/s*dp[i+1][j+1]+1)/(1-1.0*i*j/s/n);
            }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
