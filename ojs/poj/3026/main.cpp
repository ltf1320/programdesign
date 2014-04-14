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


int vis[maxn][maxn];
int ndp[maxn][maxn];
int now,maxdp;
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
/*
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
*/
bool pvis[maxn];
int low_dis[maxn];
int prim()
{
    memset(pvis,0,sizeof(pvis));
    pvis[0]=1;
    for(int i=0;i<an;i++) low_dis[i]=inf;
    int res=0;
    int now=0;
    int l,ndis;
    for(int k=0;k<an-1;k++)
    {
        ndis=inf;
        for(int i=0;i<an;i++)
        {
            if(!pvis[i]&&dis[now][i]&&dis[now][i]<low_dis[i])
                low_dis[i]=dis[now][i];
            if(!pvis[i]&&ndis>low_dis[i])
            {
                l=i;
                ndis=low_dis[i];
            }
        }
        now=l;
        pvis[l]=1;
        res+=ndis;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    char ch;
    scanf("%d",&N);
    while(N--)
    {
        //input
        scanf("%d%d",&x,&y);
        an=1;
        for(int i=0;i<y;i++)
            for(int j=0;j<x;j++)
            {
                scanf("%c",&ch);
                switch(ch)
                {
                    case ' ':map[i][j]=0;break;
                    case 'S':map[i][j]=-2;
                        sx=j,sy=i;break;
                    case 'A':map[i][j]=an;
                        pnt[an].x=j;pnt[an].y=i;an++;
                        break;
                    case '#':map[i][j]=-1;break;
                    case '\n':j--;break;
                }
            }

        //calculate the dis
        now=0;
        maxdp=inf;
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dfs(sx,sy,0);
 //       bfs(sx,sy);
        for(now=1;now<an;now++)
        {
            memset(vis,0,sizeof(vis));
            maxdp=dis[0][now];
            dfs(pnt[now].x,pnt[now].y,0);
 //           bfs(pnt[now].x,pnt[now].y);
        }
        printf("%d\n",prim());
    }
    return 0;
}
