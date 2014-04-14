//¼û1038.5

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=150+10;
const int maxm=10+2;
const int maxd=60000;
int N,M,K;
int dp[2][maxd];
int ss[2][maxd];
int ssn[2];
int three[maxm];
bool map[maxn][maxm];
int tms[maxm],now[maxm],pre[maxm];

int readState(int *p)
{
    int res=0;
    for(int i=1; i<=M; i++)
    {
        if(p[i]==2)
            res+=2*three[i-1];
        if(p[i]==1)
            res+=three[i-1];
    }
    return res;
}

void writeState(int *p,int state)
{
    for(int i=1; i<=M; i++)
    {
        p[i]=state%3;
        state/=3;
    }
}

int nextState(int i,int state)
{
    writeState(tms,state);
    int res=0;
    for(int j=1; j<=M; j++)
    {
        if(map[i+1][j])
        {
            res+=2*three[j-1];
        }
        else
        {
            if(tms[j])
                res+=(tms[j]-1)*three[j-1];
        }
    }
    return res;
}

void dfs(int i,int y,int v,int state)
{
    int ks;
    if(state==1191)
    {
        state++;
        state--;
    }
    if(y+1<=M&&now[y]==0&&now[y+1]==0&&pre[y]==0&&pre[y+1]==0)
    {
        ks=state+2*three[y-1]+2*three[y];
        if(dp[(i&1)^1][ks]<v+1)
        {
            dp[(i&1)^1][ks]=v+1;
            ss[(i&1)^1][ssn[(i&1)^1]++]=ks;
        }
        dfs(i,y+2,v+1,ks);
    }
    if(y+2<=M&&now[y]==0&&now[y+1]==0&&now[y+2]==0&&pre[y]<2&&pre[y+1]<2&&pre[y+2]<2)
    {
        ks=state+2*three[y-1]+2*three[y]+2*three[y+1];
        if(dp[(i&1)^1][ks]<v+1)
        {
            dp[(i&1)^1][ks]=v+1;
            ss[(i&1)^1][ssn[(i&1)^1]++]=ks;
        }
        dfs(i,y+3,v+1,ks);
    }
    if(v>dp[(i&1)^1][state])
    {
        dp[(i&1)^1][state]=v; //!
        ss[(i&1)^1][ssn[(i&1)^1]++]=state;
    }
    if(y<M) dfs(i,y+1,v,state);
}

int work()
{
    if(N==1||M==1) return 0;
    ssn[0]=ssn[1]=0;
    int state;
    for(int i=1; i<=M; i++)
        if(map[1][i])
            now[i]=2;
        else now[i]=1;
    memset(dp[1],-1,sizeof(dp[1]));
    state=readState(now);
    ss[1][ssn[1]++]=state;
    dp[1][state]=0;
    for(int i=1; i<N; i++)
    {
        memset(dp[(i&1)^1],-1,sizeof(dp[(i&1)^1]));
        while(ssn[i&1]>0)
        {
            ssn[i&1]--;
            state=nextState(i,ss[i&1][ssn[i&1]]);
            writeState(now,state);
            writeState(pre,ss[i&1][ssn[i&1]]);
            dfs(i,1,dp[i&1][ss[i&1][ssn[i&1]]],state);
        }
    }
    int res=0;
    for(int i=0; i<three[M]; i++)
        if(dp[N&1][i]>res)
            res=dp[N&1][i];
    return res;
}

void input()
{
    scanf("%d%d%d",&N,&M,&K);
    int x,y;
    for(int i=0; i<K; i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
    }
}

void init()
{
    memset(dp,0,sizeof(dp));
    three[0]=1;
    for(int i=1; i<maxm; i++)
    {
        three[i]=three[i-1]*3;
    }
    memset(map,0,sizeof(map));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
