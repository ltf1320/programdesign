#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxt=300+10;
const int maxm=1000+10;
const int inf=0x3f3f3f3f;
int N,M,S,E,T;

int sat[maxn];
int cost[maxn];
int res;
int dp[maxn][maxt];
bool in[maxn][maxt];
//the last visited one,time,the position now

int dis[maxn][maxn];

struct Node
{
    int id,t;
    Node(int l,int tt):id(l),t(tt){}
    Node(){}
};

queue<Node> que;

void floyd()
{
    for(int k=0;k<=N;k++)
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

void spfa()
{
    que.push(Node(N,0));
    in[N][0]=1;
    res=0;
    Node now;
    int nt;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.t+dis[now.id][E]<=T)
            res=max(res,dp[now.id][now.t]);
        for(int i=0;i<N;i++)
        {
            if(sat[i]>sat[now.id])
            {
                nt=now.t+dis[now.id][i]+cost[i];
                if(nt<=T&&dp[i][nt]<dp[now.id][now.t]+sat[i])
                {
                    dp[i][nt]=dp[now.id][now.t]+sat[i];
                    if(!in[i][nt])
                        que.push(Node(i,nt));
                }
            }
        }
        in[now.id][now.t]=0;
    }
}

void AC()
{
    static int cas=1;
    floyd();
    spfa();
    printf("Case #%d:\n",cas++);
    printf("%d\n",res);
}

void init()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            if(i!=j)
                dis[i][j]=inf;
            else
                dis[i][j]=0;
    memset(dp,0,sizeof(dp));
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d",&cost[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&sat[i]);
    cost[N]=inf;
    sat[N]=0;
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        dis[t][f]=dis[f][t]=min(dis[f][t],v);
    }
    dis[N][S]=dis[S][N]=0;//!
}

int main()
{
    freopen("in.txt","r",stdin);
    int W;
    scanf("%d",&W);
    while(W--)
    {
        scanf("%d%d%d%d%d",&N,&M,&T,&S,&E);
        init();
        input();
        AC();
    }
    return 0;
}
