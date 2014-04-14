#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200+20;
int N;
struct Duan
{
    int col,len;
};
Duan ds[maxn];
int sum[maxn];
int dsn;
int dp[maxn][maxn][maxn];
int stack[maxn];
int pn;

void printdp()
{
    for(int i=0; i<dsn; i++)
    {
        for(int j=0; j<dsn; j++)
        {
            printf("%2d ",dp[i][j][0]);
        }
        putchar('\n');
    }
}


void work()
{
    int j;
    for(int i=1; i<=dsn; i++)
        dp[i][i-1][0]=0;
    for(int len=0; len<dsn; len++)
    {
        for(int i=1; i<=dsn-len; i++)
        {
            j=i+len;
            pn=0;
            for(int k=i; k<=j; k++)
            {
                if(ds[k].col==ds[j].col)
                    stack[pn++]=k;
            }
            for(int k=0; k<=sum[dsn]-sum[j+1]; k++)
            {
                dp[i][j][k]=dp[i][j-1][0]+(ds[j].len+k)*(ds[j].len+k);
                for(int q=0;q<pn;q++)
                {
                    if(dp[i][j][k]<dp[i][stack[q]][ds[j].len+k]+dp[stack[q]+1][j-1][0])
                        dp[i][j][k]=dp[i][stack[q]][ds[j].len+k]+dp[stack[q]+1][j-1][0];
                }
            }
        }
    }
}

void input()
{
    int ncol,nlen,tcol;
    scanf("%d",&tcol);
    ncol=tcol;
    nlen=1;
    for(int i=1; i<N; i++)
    {
        scanf("%d",&tcol);
        if(ncol==tcol)
            nlen++;
        else
        {
            ds[dsn].col=ncol;
            ds[dsn].len=nlen;
            dsn++;
            ncol=tcol;
            nlen=1;
        }
    }
    ds[dsn].col=ncol;
    ds[dsn].len=nlen;
    ncol=tcol;
    nlen=1;
    dsn++;
    sum[0]=0;
    for(int i=1;i<=dsn;i++)
        sum[i]=sum[i-1]+ds[i].len;
}

void init()
{
    dsn=1;
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int cas=1,T;
    scanf("%d",&T);
    while(cas<=T)
    {
        scanf("%d",&N);
        if(N==0)
        {
            printf("Case %d: %d\n",cas++,0);
            continue;
        }
        init();
        input();
        work();
        printdp();
        printf("Case %d: %d\n",cas++,dp[0][dsn-1][0]);
    }
    return 0;
}
