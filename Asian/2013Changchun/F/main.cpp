#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
typedef long long LL;
using namespace std;
const int maxn=100000+100;
const int MOD=1000000007;
int N,M;

struct EDGE
{
    int to,next;
};
EDGE edge[maxn];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

LL mpow(int a,int n)
{
    LL res=1;
    LL now=a;
    while(n)
    {
        if(n&1)
        {
            res*=now;
            if(res>=MOD)
                res%=MOD;
        }
        now*=now;
        if(now>=MOD)
            now%=MOD;
        n>>=1;
    }
    return res;
}

int dfn[maxn],low[maxn];
int fl[maxn],fln;
vector<int> fls;
int stack[maxn],top;
bool in[maxn];
int ti;

void tarjan(int now)
{
    dfn[now]=low[now]=ti++;
    stack[++top]=now;
    in[now]=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
    }
    int nd;
    if(dfn[now]==low[now])
    {
        fls.clear();
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fls.push_back(nd);
            fl[nd]=fln;
            in[nd]=0;
            if(nd==now) break;
        }
        fln++;
    }
}

void initTarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    top=-1;
    fln=0;
}

LL dp[maxn][2];

void work()
{
    initTarjan();
    for(int i=1; i<=N; i++)
        if(!dfn[i])
        {
            tarjan(i);
            if(fln)
                break;
        }
    int k=fls.size();
    dp[0][0]=1;
    for(int i=1; i<k-1; i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0]*(M-1);
        if(dp[i][1]>=MOD)
            dp[i][1]%=MOD;
    }
    LL res=dp[k-2][1]*(M-2)+dp[k-2][0]*(M-1);
    if(k%2==0)
        res*=M;
    if(res>=MOD)
        res%=MOD;
    res*=mpow(M-1,N-k);
    if(res>=MOD)
        res%=MOD;
    printf("%I64d\n",res);
}

void input()
{
    int t;
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&t);
        add(i,t);
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
