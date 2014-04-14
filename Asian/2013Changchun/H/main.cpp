#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+100;
const int maxk=100+10;
const int MOD=1E9+7;

int N,M,K;

int pri[10];
int prn;

int yzs[100];
int yzn;
int wc[maxn];

void div(int n)
{
    prn=yzn=0;
    memset(wc,-1,sizeof(wc));
    int now=n;
    int p;
    yzs[yzn++]=1;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            yzs[yzn++]=i;
            if(now%i==0)
            {
                pri[prn]=i;
                p=1;
                while(now%i==0)
                {
                    now/=i;
                    p*=i;
                }
                wc[p]=prn;
                prn++;
            }
        }
    }
}

int dp[2][maxn][maxn];//k st j

void work()
{
    div(M);
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int k=0;k<K;k++)
    {
        memset(dp[(k&1)^1],0,sizeof(dp[0]));
        for(int st=0;st<(1<<prn);st++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<yzn;j++)
                {
                    if(i+yzs[j]<=N&&dp[k&1][st][i])
                    {
                        if(wc[yzs[j]]!=-1)
                        {
                            dp[(k&1)^1][st|(1<<wc[yzs[j]])][i+yzs[j]]+=dp[k&1][st][i];
                            if(dp[(k&1)^1][st|(1<<wc[yzs[j]])][i+yzs[j]]>=MOD)
                                dp[(k&1)^1][st|(1<<wc[yzs[j]])][i+yzs[j]]-=MOD;
                        }
                        else
                        {
                            dp[(k&1)^1][st][i+yzs[j]]+=dp[k&1][st][i];
                            if(dp[(k&1)^1][st][i+yzs[j]]>=MOD)
                                dp[(k&1)^1][st][i+yzs[j]]-=MOD;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",dp[K&1][(1<<prn)-1][N]);
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&N,&M,&K))
        work();
    return 0;
}
