#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3000+100;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn];
int N,M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[maxn];
int box[maxn];
int ent;
void add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

int pri[maxn];


int dfs(int now,int v)
{
    if(pri[now]>0)
    {
        dp[now][1]=pri[now]-v;
        return 1;
    }
    int n=0;
    int tmp=0;
    dp[now][0]=-v;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        tmp=dfs(edge[i].to,edge[i].v);
        n+=tmp;
        for(int j=n;j>=0;j--)
            for(int k=1;k<=tmp;k++)
            {
                if(dp[edge[i].to][k]<=-inf) break;
                if(dp[now][j+k]<dp[now][j]+dp[edge[i].to][k])
                    dp[now][j+k]=dp[now][j]+dp[edge[i].to][k];
            }
    }
    return n;
}

void input()
{
    int k,t,v;
    for(int i=1;i<=N-M;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d%d",&t,&v);
            add(i,t,v);
        }
    }
    for(int i=N-M+1;i<=N;i++)
    {
        scanf("%d",&k);
        pri[i]=k;
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    for(int i=1;i<=N;i++)
        for(int j=0;j<=N;j++)
            dp[i][j]=-inf;
    memset(pri,0,sizeof(pri));
}


int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    init();
    input();
    dfs(1,0);
    for(int i=N;i>=0;i--)
        if(dp[1][i]>=0)
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}
