#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=32;
const int MID=35;
int dp[maxn][3*maxn];
void pre()
{
    memset(dp,0,sizeof(dp));
    dp[0][1+MID]=1;
    dp[0][MID-1]=1;
    for(int i=1;i<maxn;i++)
        for(int j=MID-i-1;j<=MID+i+1;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        }
}

int bit[maxn];

int toBit(int a,int& is)
{
    int t=0;
    while(a)
    {
        if(a&1)
        {
            is++;
            bit[t]=1;
        }
        else
        {
            is--;
            bit[t]=0;
        }
        t++;
        a>>=1;
    }
    if(is<=0) is=1;
    else is=0;
    return t-1;
}



int getSum(int a)
{
    if(a==0) return 0;
    int res=0;
    int len=toBit(a,res);
    int nned=0;
    for(int i=len;i>0;i--)
    {
        if(bit[i]==1)
        {
            for(int j=MID-nned;j>MID-i;j--)
            {
                res+=dp[i-1][j-1];
            }
            nned++;
        }
        else
        {
            nned--;
        }
    }
    return res;
}

int main()
{
    pre();
    int start,finish;
    scanf("%d%d",&start,&finish);
    printf("%d\n",getSum(finish)-getSum(start-1));
    return 0;
}
