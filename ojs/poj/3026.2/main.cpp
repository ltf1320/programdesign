#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=50+10;
const int inf=0x3f3f3f3f;

int map[maxn][maxn];
//0 for space,-2 for S,n for An,-1 for wall
int x,y;
int sx,sy;
int an;
int dis[maxn][maxn];

struct Point
{
    int x,y;
};
Point pnt[maxn];

/*
int vis[maxn][maxn];
int ndp[maxn][maxn];
void dfs(int nx,int ny,int dp)
{
    if(dp>maxdp) return;
    if(map[ny][nx]==-1) return;
    if(vis[ny][nx]&&vis[ny][nx]<dp)
        return;
    if(map[ny][nx]>0)
        dis[now][map[ny][nx]]=dis[map[ny][nx]][now]=dp;
    vis[ny][nx]=dp;
    if(nx>0) dfs(nx-1,ny,dp+1);
    if(nx<x-1) dfs(nx+1,ny,dp+1);
    if(ny>0) dfs(nx,ny-1,dp+1);
    if(ny<y-1) dfs(nx,ny+1,dp+1);
}
*/

struct FBFS
{
    int x,y,dp;
    FBFS(int nx,int ny,int ndp){x=nx;y=ny;dp=ndp;}
};

int now,maxdp;
bool vis[maxn][maxn];
void bfs(int sx,int sy)
{
    int nx,ny,ndp;
    memset(vis,0,sizeof(vis));
    queue<FBFS> que;
    que.push(FBFS(sx,sy,0));
    while(!que.empty())
    {
        nx=que.front().x;
        ny=que.front().y;
        ndp=que.front().dp;
        if(vis[ny][nx])
        {
            que.pop();
            continue;
        }
        if(ndp>=maxdp) return;
        que.pop();
        if(map[ny][nx]==-1) continue;
        if(map[ny][nx]>0)
            dis[now][map[ny][nx]]=dis[map[ny][nx]][now]=ndp;
        if(nx>0) que.push(FBFS(nx-1,ny,ndp+1));
        if(nx<x-1) que.push(FBFS(nx+1,ny,ndp+1));
        if(ny>0) que.push(FBFS(nx,ny-1,ndp+1));
        if(ny<y-1) que.push(FBFS(nx,ny+1,ndp+1));
        vis[ny][nx]=1;
    }
}



struct FSO
{
    int p,dis;
    FSO(int pp,int d){p=pp;dis=d;}
    bool operator<(const FSO& a)const
    {
        return dis>a.dis;
    }
};

bool pvis[maxn];
int low_dis[maxn];
int prim()
{
    memset(pvis,0,sizeof(pvis));
    for(int i=0;i<an;i++) low_dis[i]=inf;
    int res=0;
    int now;
    int ndis;
    priority_queue<FSO> que;
    que.push(FSO(0,0));
    while(!que.empty())
    {
        now=que.top().p;
        ndis=que.top().dis;
        if(pvis[now])
        {
            que.pop();
            continue;
        }
        res+=ndis;
        que.pop();
        ndis=inf;
        for(int i=0;i<an;i++)
        {
            if(i==now) continue;
            if(pvis[i]) continue;
            if(!pvis[i]&&dis[now][i]&&dis[now][i]<low_dis[i])
            {
                low_dis[i]=dis[now][i];
                que.push(FSO(i,low_dis[i]));
            }
        }
        pvis[now]=1;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    char tmp[maxn];
    scanf("%d",&N);
    while(N--)
    {
        //input
        scanf("%d%d",&x,&y);
        gets(tmp);
        an=1;
        for(int i=0;i<y;i++)
        {
            gets(tmp);
            for(int j=0;j<x;j++)
            {
                switch(tmp[j])
                {
                    case ' ':map[i][j]=0;break;
                    case 'S':map[i][j]=-2;
                        sx=j,sy=i;break;
                    case 'A':map[i][j]=an;
                        pnt[an].x=j;pnt[an].y=i;an++;
                        break;
                    case '#':map[i][j]=-1;break;
                }
            }
        }
        //calculate the dis
        now=0;
        maxdp=inf;
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        bfs(sx,sy);
        for(now=1;now<an;now++)
        {
            memset(vis,0,sizeof(vis));
            maxdp=dis[0][now];
            bfs(pnt[now].x,pnt[now].y);
        }
        printf("%d\n",prim());
    }
    return 0;
}
