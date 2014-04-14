#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=1600+10;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn];
int N,sum;

bool judge(int a,int b)
{
    int c=sum-a-b;
    if(a+b>c&&a+c>b&&b+c>a) return true;
    return false;
}

int getAera(int a,int b,int c)
{
    double s=1.0*sum/2; //!!
    double res=sqrt(1.0*s*(s-a)*(s-b)*(s-c));
    return static_cast<int>(res*100);
}

int main()
{
    int tmp,res;

    while(~scanf("%d",&N))
    {
        sum=0;
        res=-1;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0; i<N; i++)
        {
            scanf("%d",&tmp);
            sum+=tmp;
            for(int j=sum; j>=0; j--)
            {
                for(int k=j; k>=0; k--)
                {
                    if(j>=tmp&&dp[j-tmp][k])
                        dp[j][k]=1;
                    if(k>=tmp&&dp[j][k-tmp])
                        dp[j][k]=1;
                }
            }
            dp[tmp][0]=dp[0][tmp]=1;;
        }
        for(int i=1; i<sum; i++)
            for(int j=1; j<=i; j++)
            {
                if(dp[i][j]&&judge(i,j))
                {
                    res=max(res,getAera(i,j,sum-i-j));
                }
            }

        printf("%d\n",res);
    }
    return 0;
}
