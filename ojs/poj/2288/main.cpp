#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=15;
const int maxm=maxn*maxn;
typedef long long LL;
int N,M;
int v[maxn];

bool map[maxn][maxn];
int pp3[maxn][maxn][maxn];
int dp[1<<13][maxn][maxn];
LL num[1<<13][maxn][maxn];


void getpp3()
{
    memset(pp3,0,sizeof(pp3));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==j) continue;
            for(int k=0; k<N; k++)
            {
                if(k==i||k==j)continue;
                if(map[i][j]&&map[j][k]&&map[i][k])
                {
                    pp3[i][j][k]=v[i]*v[j]*v[k];
                }
            }
        }
}

void work()
{
    if(N==1)
    {
        printf("%d %d\n",v[0],1);
        return;
    }
    getpp3();
    int nst,now;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
        {
            if(map[i][j])
            {
                nst=(1<<i)+(1<<j);
                dp[nst][i][j]=dp[nst][j][i]=v[i]*v[j]+v[i]+v[j];
                num[nst][i][j]=num[nst][j][i]=1;
            }
        }
    for(int st=0; st<(1<<N); st++)
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                if(i==j)continue;
                if(num[st][i][j])
                {
                    for(int k=0; k<N; k++)
                    {
                        if(!map[i][k]) continue;
                        if(st&(1<<k))
                            continue;
                        now=dp[st][i][j];
                        now+=v[i]*v[k];
                        now+=pp3[i][j][k];
                        now+=v[k];
                        nst=st|(1<<k);
                        if(dp[nst][k][i]==now)
                            num[nst][k][i]+=num[st][i][j];
                        if(dp[nst][k][i]<now)
                        {
                            dp[nst][k][i]=now;
                            num[nst][k][i]=num[st][i][j];
                        }
                    }
                }
            }
    }
    LL res=0,nn=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i!=j)
            {
                if(dp[(1<<N)-1][i][j]==res)
                    nn+=num[(1<<N)-1][i][j];
                if(dp[(1<<N)-1][i][j]>res)
                {
                    res=dp[(1<<N)-1][i][j];
                    nn=num[(1<<N)-1][i][j];
                }

            }
    printf("%I64d %I64d\n",res,nn/2);
}

void input()
{
    int a,b;
    for(int i=0; i<N; i++)
        scanf("%d",&v[i]);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&a,&b);
        a--;
        b--;
        map[a][b]=map[b][a]=1;
    }
}

void init()
{
    memset(map,0,sizeof(map));
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        init();
        input();
        work();
    }
    return 0;
}
