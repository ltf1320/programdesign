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
int dsn;
int dp[maxn][maxn];
int stack[maxn];
int pn;

void printdp()
{
    for(int i=0;i<dsn;i++)
    {
        for(int j=0;j<dsn;j++)
        {
            printf("%2d ",dp[i][j]);
        }
        putchar('\n');
    }
}

int dfs(int s,int e,int p,int v,int q)
{
    if(p==pn)
        return dp[s][e]+v+q*q;
    int res=0;
    for(int i=p;i<pn;i++)
    {
        res=max(res,dfs(stack[i]+1,e,i+1,v+dp[s][stack[i]-1],q+ds[stack[i]].len));
    }
    return res;
}


void work()
{
    int j,nsum,lsum;
    for(int i=0; i<dsn; i++)
    {
        dp[i][i-1]=0;
        dp[i][i]=ds[i].len*ds[i].len;
    }
    for(int len=1; len<dsn; len++)
    {
        for(int i=0; i<dsn-len; i++)
        {
            j=i+len;
            pn=0;
            for(int k=i; k<=j; k++)
            {
                if(ds[k].col==ds[j].col)
                    stack[pn++]=k;
            }
            for(int q=i; q<j; q++)
            {
                if(dp[i][q]+dp[q+1][j]>dp[i][j])
                    dp[i][j]=dp[i][q]+dp[q+1][j];
            }
            /*
            nsum=0;
            lsum=0;
            for(int q=0; q<pn; q++)
                lsum+=ds[stack[q]].len;
            nsum+=lsum*lsum;
            nsum+=dp[i][stack[0]-1];
            for(int q=1; q<pn; q++)
                nsum+=dp[stack[q-1]+1][stack[q]-1];
            if(nsum>dp[i][j])
                dp[i][j]=nsum;
            */
            dp[i][j]=max(dfs(i,j,0,0,0),dp[i][j]);
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
}

void init()
{
    dsn=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
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
  //      printdp();
        printf("Case %d: %d\n",cas++,dp[0][dsn-1]);
    }
    return 0;
}
