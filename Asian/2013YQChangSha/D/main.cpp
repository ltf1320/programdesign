#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int maxk=15;
const int inf=0x3f3f3f3f;
int N,M,K;
int map[maxn][maxn];

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

bool isValid(int x,int y)
{
    if(x<1||x>N)
        return false;
    if(y<1||y>M)
        return false;
    return true;
}

struct Point
{
    int x,y;
    Point(){}
    Point(int xx,int yy):x(xx),y(yy){}
};
Point tre[maxk];

int inout[maxn][maxn];
int ndis[maxn][maxn];
bool in[maxn][maxn];
int dis[maxk][maxk];

queue<Point> que;
void getinout()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            inout[i][j]=inf;
    for(int i=1;i<=N;i++)
    {
        if(map[i][1]!=-1)
        {
            inout[i][1]=map[i][1];
            in[i][1]=1;
            que.push(Point(i,1));
        }
        if(map[i][M]!=-1)
        {
            inout[i][M]=map[i][M];
            in[i][M]=1;
            que.push(Point(i,M));
        }
    }
    for(int i=1;i<=M;i++)
    {
        if(map[1][i]!=-1)
        {
            inout[1][i]=map[1][i];
            in[1][i]=1;
            que.push(Point(1,i));
        }
        if(map[N][i]!=-1)
        {
            inout[N][i]=map[N][i];
            in[N][i]=1;
            que.push(Point(N,i));
        }
    }
    Point now;
    int nx,ny;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            nx=now.x+dx[i];
            ny=now.y+dy[i];
            if(isValid(nx,ny)&&map[nx][ny]!=-1)
            {
                if(inout[now.x][now.y]+map[nx][ny]<inout[nx][ny])
                {
                    inout[nx][ny]=inout[now.x][now.y]+map[nx][ny];
                    if(!in[nx][ny])
                        que.push(Point(nx,ny));
                }
            }
        }
        in[now.x][now.y]=0;
    }
}

void getDis(int nk)
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            ndis[i][j]=inf;
    ndis[tre[nk].x][tre[nk].y]=0;
    que.push(Point(tre[nk].x,tre[nk].y));
    in[tre[nk].x][tre[nk].y]=1;
    Point now;
    int nx,ny;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            nx=now.x+dx[i];
            ny=now.y+dy[i];
            if(isValid(nx,ny)&&map[nx][ny]!=-1)
            {
                if(ndis[now.x][now.y]+map[nx][ny]<ndis[nx][ny])
                {
                    ndis[nx][ny]=ndis[now.x][now.y]+map[nx][ny];
                    if(!in[nx][ny])
                        que.push(Point(nx,ny));
                }
            }
        }
        in[now.x][now.y]=0;
    }
    for(int i=0;i<K;i++)
    {
        dis[nk][i]=ndis[tre[i].x][tre[i].y];
    }
}

int dp[1<<13][maxk];

void AC()
{
    getinout();
    for(int i=0;i<K;i++)
        getDis(i);
    for(int i=0;i<(1<<K);i++)
        for(int j=0;j<K;j++)
            dp[i][j]=inf;
    for(int i=0;i<K;i++)
        dp[1<<i][i]=inout[tre[i].x][tre[i].y];
    int nst;
    for(int st=0;st<(1<<K);st++)
    {
        for(int j=0;j<K;j++)
        {
            if(dp[st][j]!=inf)
            {
                for(int k=0;k<K;k++)
                {
                    if(j==k) continue;
                    nst=st|(1<<k);
                    if(dp[st][j]+dis[j][k]<dp[nst][k])
                    {
                        dp[nst][k]=dp[st][j]+dis[j][k];
                    }
                }
            }
        }
    }
    int res=inf;
    for(int i=0;i<K;i++)
        res=min(res,dp[(1<<K)-1][i]+inout[tre[i].x][tre[i].y]-map[tre[i].x][tre[i].y]);
    printf("%d\n",res);
}

void input()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&map[i][j]);
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d%d",&tre[i].x,&tre[i].y);
        tre[i].x++;tre[i].y++;
    }
}

void init()
{

}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        init();
        input();
        AC();
    }
    return 0;
}
