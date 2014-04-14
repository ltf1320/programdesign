#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int inf=0x3f3f3f3f;
const int maxk=15;
int N,M,K;
int map[maxn][maxn];
int inout[maxn][maxn];
int dis[maxk][maxk];
bool can[maxk];


void printInout()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            printf("%d ",inout[i][j]);
        puts("");
    }
    puts("");
}

void printDis()
{
    for(int i=0;i<=K;i++)
    {
        for(int j=0;j<=K;j++)
            printf("%d ",dis[i][j]);
        puts("");
    }
    puts("");
}

struct Trea
{
    int x,y;
};
Trea treas[maxk];

queue<int> que;
bool in[maxn*maxn];
bool getInOut()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            inout[i][j]=inf;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(i==0||i==N-1||j==0||j==M-1)
            {
                if(map[i][j]!=-1)
                {
                    inout[i][j]=map[i][j];
                    que.push(i*N+j);
                }
            }
            else inout[i][j]=inf;
        }
    int now,nxt;
    int x,y;
    memset(in,0,sizeof(in));
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        x=now/N;
        y=now%N;
        if(x>0)
            if(map[x-1][y]!=-1&&inout[x-1][y]>inout[x][y]+map[x-1][y])
            {
                inout[x-1][y]=inout[x][y]+map[x-1][y];
                nxt=(x-1)*N+y;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(x<N-1)
            if(map[x+1][y]!=-1&&inout[x+1][y]>inout[x][y]+map[x+1][y])
            {
                inout[x+1][y]=inout[x][y]+map[x+1][y];
                nxt=(x+1)*N+y;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(y>0)
            if(map[x][y-1]!=-1&&inout[x][y-1]>inout[x][y]+map[x][y-1])
            {
                inout[x][y-1]=inout[x][y]+map[x][y-1];
                nxt=x*N+y-1;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(y<N-1)
            if(map[x][y+1]!=-1&&inout[x][y+1]>inout[x][y]+map[x][y+1])
            {
                inout[x][y+1]=inout[x][y]+map[x][y+1];
                nxt=x*N+y+1;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        in[now]=0;
    }
    bool flag=0;
    memset(can,0,sizeof(can));
    for(int i=1;i<=K;i++)
    {
        if(inout[treas[i].x][treas[i].y]==inf)
            continue;
        if(map[treas[i].x][treas[i].y]==-1)
            continue;
        can[i]=1;
        flag=1;
        dis[0][i]=inout[treas[i].x][treas[i].y];
        dis[i][0]=inout[treas[i].x][treas[i].y]-map[treas[i].x][treas[i].y];
  //      dis[i][0]=inout[treas[i].x][treas[i].y];
    }
    return flag;
}

bool getDis(int start)
{
    for(int x=0;x<N;x++)
        for(int y=0;y<N;y++)
            inout[x][y]=inf;
    inout[treas[start].x][treas[start].y]=0;
    que.push(treas[start].x*N+treas[start].y);
    int now,nxt;
    int x,y;
    memset(in,0,sizeof(in));
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        x=now/N;
        y=now%N;
        if(x>0)
            if(map[x-1][y]!=-1&&inout[x-1][y]>inout[x][y]+map[x-1][y])
            {
                inout[x-1][y]=inout[x][y]+map[x-1][y];
                nxt=(x-1)*N+y;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(x<N-1)
            if(map[x+1][y]!=-1&&inout[x+1][y]>inout[x][y]+map[x+1][y])
            {
                inout[x+1][y]=inout[x][y]+map[x+1][y];
                nxt=(x+1)*N+y;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(y>0)
            if(map[x][y-1]!=-1&&inout[x][y-1]>inout[x][y]+map[x][y-1])
            {
                inout[x][y-1]=inout[x][y]+map[x][y-1];
                nxt=x*N+y-1;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        if(y<N-1)
            if(map[x][y+1]!=-1&&inout[x][y+1]>inout[x][y]+map[x][y+1])
            {
                inout[x][y+1]=inout[x][y]+map[x][y+1];
                nxt=x*N+y+1;
                if(!in[nxt])
                {
                    in[nxt]=1;
                    que.push(nxt);
                }
            }
        in[now]=0;
    }
    for(int i=1;i<=K;i++)
        if(i!=start&&can[i])
        {
            dis[start][i]=inout[treas[i].x][treas[i].y];
            if(dis[start][i]==inf)
             return 0;
        }
    return 1;
}



struct FSO
{
    int now,state;
    FSO(){}
    FSO(int n,int st):now(n),state(st){}
};
queue<FSO> dpque;
int dp[maxk][1<<15];
bool dpin[maxk][1<<15];


void work()
{
    if(!getInOut())
    {
        printf("0\n");
        return;
    }
 //   printInout();
    for(int i=1;i<=K;i++)
        if(!getDis(i))
        {
            printf("0\n");
            return;
        }
 //   printDis();
    FSO now;
    for(int i=1;i<=K;i++)
        for(int j=0;j<1<<(K+1);j++)
            dp[i][j]=inf;
    for(int i=1;i<=K;i++)
    {
        if(!can[i]) continue;
        dp[i][1<<i]=dis[0][i];
        dpque.push(FSO(i,1<<i));
    }
    memset(dpin,0,sizeof(dpin));
    while(!dpque.empty())
    {
        now=dpque.front();
        dpque.pop();
        for(int i=1;i<=K;i++)
        {
            if(!can[i]) continue;
            if(!(now.state&(1<<i)))
            {
                if(dp[i][now.state|(1<<i)]>dp[now.now][now.state]+dis[now.now][i])
                {
                    dp[i][now.state|(1<<i)]=dp[now.now][now.state]+dis[now.now][i];
                    if(!dpin[i][now.state|(1<<i)])
                    {
                        dpque.push(FSO(i,now.state|(1<<i)));
                        dpin[i][now.state|(1<<i)]=1;
                    }
                }
            }
        }
        dpin[now.now][now.state]=0;
    }
    int enst=0,res=inf;
    for(int i=1;i<=K;i++)
        if(can[i])
            enst|=(1<<i);
    for(int i=1;i<=K;i++)
        res=min(res,dp[i][enst]+dis[i][0]);
    if(res!=inf)
        printf("%d\n",res);
    else printf("0\n");
}

void input()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    scanf("%d",&K);
    for(int i=1;i<=K;i++)
        scanf("%d%d",&treas[i].x,&treas[i].y);
}

int main()
{
    freopen("in.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&N,&M);
        input();
        work();
    }
    return 0;
}


