#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=200+10;
int N,M,L,R;

int getNext(int n,int w)
{
    return (n+w)%N;
}
int getFor(int n,int w)
{
    n=n-w;
    while(n<0) n+=N;
    return n%N;
}

double dp[2][maxn];

int main()
{
  //  freopen("in.txt","r",stdin);
    int w;
    double res;
    while(~scanf("%d%d%d%d",&N,&M,&L,&R))
    {
        if(N==0&&M==0&&L==0&&R==0) break;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1.0;
        for(int i=0; i<M; i++)
        {
            memset(dp[(i&1)^1],0,sizeof(dp[(i&1)^1]));
            scanf("%d",&w);
            for(int j=0; j<N; j++)
            {
                if(dp[i&1][j])
                {
                    dp[(i&1)^1][getNext(j,w)]+=dp[i&1][j]*0.5;
                    dp[(i&1)^1][getFor(j,w)]+=dp[i&1][j]*0.5;
                }
            }
        }
        L--;R--;
        res=0.0;
        for(int i=L;i<=R;i++)
        {
            res+=dp[M&1][i];
        }
        printf("%.4f\n",res);
    }
    return 0;
}
