#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=50+10;
const int inf=1000*10000+100;
int N,M,K;
int dis[maxn][maxn];
int dp[1<<11][maxn];
bool vis[maxn];

void floyd()
{
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int res;
int pp[10];
void dfs(int n)
{
    if(n==K)
    {
        int nst,nres,rt;
        int end=pow(K,K);
        int now;
        for(int i=0;i<end;i++)
        {
            nres=0;
            for(int j=0;j<K;j++)
            {
                nst=0;
                now=i;
                for(int k=0;k<K;k++)
                {
                    if(now%K==j)
                    {
                        nst|=1<<k;
                        nst|=1<<(pp[k]+K);
                        rt=k;
                    }
                    now/=K;
                }
                if(nst)
                    nres+=dp[nst][rt];
            }
            res=min(res,nres);
        }
        return;
    }
    for(int i=0;i<K;i++)
    {
        if(!vis[i])
        {
            pp[n]=i;
            vis[i]=1;
            dfs(n+1);
            vis[i]=0;
        }
    }
}
void work()
{
    floyd();
    int mx,mi;
    for(int i=0;i<K;i++)
        for(int j=0;j<N;j++)
            dp[1<<i][j]=dis[i][j];
    for(int i=0;i<K;i++)
        for(int j=0;j<N;j++)
            dp[1<<(i+K)][j]=dis[N-i-1][j];
    for(int i=1;i<(1<<(K*2));i++)
    {
        if(!(i&(i-1)))
            continue;
        for(int k=0;k<N;k++)
        {
            vis[k]=0;

            for(int j=i;j;j=(j-1)&i)
                dp[i][k]=min(dp[i][k],dp[j][k]+dp[i-j][k]);
            /*
            for(int j=0;j<i;j++)
                if((j|i)==i)
                    dp[i][k]=min(dp[i][k],dp[j][k]+dp[i-j][k]);
            */
        }
        for(int k=0;k<N;k++)
        {
            mx=inf+1;
            for(int j=0;j<N;j++)
            {
                if(dp[i][j]<mx&&!vis[j])
                {
                    mx=dp[i][j];
                    mi=j;
                }
            }
            vis[mi]=1;
            for(int j=0;j<N;j++)
                dp[i][j]=min(dp[i][j],dp[i][mi]+dis[mi][j]);
        }
    }
    res=inf;
    for(int i=0;i<K;i++)
        vis[i]=0;
    dfs(0);
    if(res==inf)
        puts("No solution");
    else
        printf("%d\n",res);

}

void input()
{
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        f--;t--;
        dis[f][t]=dis[t][f]=min(dis[f][t],v);
    }
}

void init()
{
    for(int i=0;i<(1<<(2*K));i++)
        for(int j=0;j<N;j++)
            dp[i][j]=inf;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=i==j?0:inf;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        init();
        input();
        work();
    }
    return 0;
}
