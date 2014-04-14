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

int dfs(int now,int father)
{
    dp[now][0][1]=dp[now][1][1]=app[now];
    int mk=1;
    int tmk;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to==father) continue;
        tmk=dfs(edge[i].to,now);
        for(int j=mk; j>0; j--)
            for(int k=1; k<min(K+1,tmk+1); k++)
            {
                if(dp[now][1][j+k+1]<dp[now][1][j]+dp[edge[i].to][1][k])
                    dp[now][1][j+k+1]=dp[now][1][j]+dp[edge[i].to][1][k];
                dp[now][0][j+k]=max(dp[now][0][j+k],dp[now][1][j]+dp[edge[i].to][0][k]);
            }
        mk+=tmk+1;
        mk=min(K+1,mk);
        for(int j=0;j<=mk;j++){
            dp[now][0][j+1]=max(dp[now][0][j+1],dp[edge[i].to][0][j]+app[now]);
            dp[now][0][j+1]=max(dp[now][0][j+1],dp[edge[i].to][1][j]+app[now]);
            dp[now][0][j+1]=max(dp[now][0][j+1],dp[now][1][j+1]);
        }
//       for(int j=1;j<=min(maxk,mk);j++)
//           dp[now][0][j]=max(dp[now][0][j],dp[now][1][j]);
    }
    for(int i=1;i<=mk;i++)
        if(dp[now][0][i]<dp[now][0][i-1])
            dp[now][0][i]=dp[now][0][i-1];
    return mk;
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
    for(int i=0; i<=N; i++)
        for(int j=0; j<=2*K; j++)
            dp[i][0][j]=dp[i][1][j]=-inf;
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int mk;
    int res;
    while(~scanf("%d%d",&N,&K))
    {
        res=0;
        init();
        input();
        mk=dfs(1,1);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=K+1;j++)
            {
                printf("%d ",dp[i][0][j]);
            }
            printf("\n");
        }
        for(int i=0; i<=K+1; i++)
            if(dp[1][0][i]>res)
                res=dp[1][0][i];
        printf("%d\n",res);
    }
    return 0;
}

