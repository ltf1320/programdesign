#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=100+10;
const int maxk=200+10;
const int inf=0x3f3f3f3f;
int N,K;
int dp[maxn][2][2*maxk];
int app[maxn];
int ent;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];

void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void dfs(int now,int father)
{
    for(int i=0;i<=K;i++)
        dp[now][0][i]=dp[now][1][i]=app[now];
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to==father) continue;
        dfs(edge[i].to,now);
        for(int j=K; j>=0; j--)
            for(int k=0; k<=j; k++)
            {
                dp[now][1][j+2]=max(dp[now][1][j+2],dp[now][1][j-k]+dp[edge[i].to][1][k]);
                dp[now][0][j+2]=max(dp[now][0][j+2],dp[now][0][j-k]+dp[edge[i].to][1][k]);//!
                dp[now][0][j+1]=max(dp[now][0][j+1],dp[now][1][j-k]+dp[edge[i].to][0][k]);
            }
    }
}

void input()
{
    int f,t;
    for(int i=1; i<=N; i++)
        scanf("%d",&app[i]);
    for(int i=1; i<N; i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    memset(dp,0,sizeof(dp));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int res;
    while(~scanf("%d%d",&N,&K))
    {
        res=0;
        init();
        input();
        dfs(1,1);
        /*
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=K+1;j++)
            {
                printf("%d ",dp[i][0][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n",dp[1][0][K]);
    }
    return 0;
}

