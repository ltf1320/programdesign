
#include <stdio.h>
#include <string.h>
const int maxn=500000+1000;
const int inf=0x3f3f3f3f;
int dp[maxn][2];
int N,L,R;
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}
bool vis[maxn];
int dis;
int k;
void dfs(int now)
{
    vis[now]=1;
 //   if(dp[now][k]!=-1) return;
    int tmp;
    if(k) dp[now][k]=inf;
    else dp[now][k]=-2;
    bool flag=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(vis[edge[i].to]) continue;
        flag=0;
        if(k)
        {
            dis+=edge[i].v;
            k=0;
            if(dp[edge[i].to][0]==-1)
                dfs(edge[i].to);
            k=1;
            dis-=edge[i].v;
            tmp=dis+edge[i].v+dp[edge[i].to][0];
            if(tmp<=R&&tmp>=L)
                dp[now][k]=min(dp[now][k],edge[i].v+dp[edge[i].to][0]);
        }
        else
        {
            dis+=edge[i].v;
            k=1;
            if(dp[edge[i].to][1]==-1)
                dfs(edge[i].to);
            k=0;
            dis-=edge[i].v;
            tmp=dis+edge[i].v+dp[edge[i].to][1];
            if(tmp<=R&&tmp>=L)
                dp[now][k]=max(dp[now][k],edge[i].v+dp[edge[i].to][1]);
        }
    }
    if(flag) dp[now][k]=0;
    else if(dp[now][k]==inf||dp[now][k]==-2)
        dp[now][k]=-2;
}

int main()
{
    freopen("in.txt","r",stdin);
    int f,t,v;
    while(~scanf("%d%d%d",&N,&L,&R))
    {
        memset(box,-1,sizeof(box));
        ent=0;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d%d",&f,&t,&v);
            add(f,t,v);
            add(t,f,v);
        }
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        dis=0;
        k=0;
        dfs(0);
        if(dp[0][0]==-2||dp[0][0]==-1)
            printf("Oh, my god!\n");
        else printf("%d\n",dp[0][0]);
    }
    return 0;
}
