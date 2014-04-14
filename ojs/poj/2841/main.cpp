#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int N,M;
char map[maxn][maxn];

int mabs(int a)
{
    return a>0?a:-a;
}
struct Point
{
    int x,y;
};
Point Hs[maxn];
int hn;

int getH(int x,int y)
{
    int res=inf;
    for(int i=0; i<hn; i++)
    {
        res=min(res,mabs(x-Hs[i].x)+mabs(y-Hs[i].y));
    }
    return res;
}

struct FSO
{
    int x,y,f,dis,h;
    FSO(int xx,int yy,int ff,int d,int hh):x(xx),y(yy),f(ff),dis(d),h(hh) {}
    FSO() {}
    bool operator<(const FSO& a)const
    {
        return h>a.h;
    }
};
int dp[maxn][maxn][2];
int next[maxn][2];

void getNext(int x,int y,int f)
{
    memset(next,-1,sizeof(next));
    int now=dp[x][y][f],con=1,nf=f;
    if(map[x-1][y]=='B') next[y][nf]=now;
    if(map[x-1][y]=='F') nf^=1;
    if(map[x-1][y]=='S') next[y][nf]=now+2;
    if(map[x-1][y]=='.') next[y][nf]=now+1;
    for(int i=y+1; i<M; i++)
    {
        if(map[x][i]=='O') break;
        if(map[x][i]=='.') now+=con;
        if(map[x][i]=='F') {nf^=1;now+=con;}
        if(map[x][i]=='S') now+=2*con;
        if(map[x-1][i]=='B') next[i][nf]=now;
        if(map[x-1][i]=='F') nf^=1;
        if(map[x-1][i]=='S') next[i][nf]=now+2;
        if(map[x-1][i]=='.') next[i][nf]=now+1;
        con++;
    }
    now=dp[x][y][f],con=1,nf=f;
    for(int i=y-1; i>=0; i--)
    {
        if(map[x][i]=='O') break;
        if(map[x][i]=='.') now+=con;
        if(map[x][i]=='F') nf^=1;
        if(map[x][i]=='S') now+=2*con;
        if(map[x-1][i]=='B') next[i][nf]=now;
        if(map[x-1][i]=='F') nf^=1;
        if(map[x-1][i]=='S') next[i][nf]=now+2;
        if(map[x-1][i]=='.') next[i][nf]=now+1;
        con++;
    }
}

void getNow(int y,int f)
{
    int now=dp[0][y][f],con=1,nf=f;
    memset(next,-1,sizeof(next));
    next[y][f]=now;
    for(int i=y+1; i<M; i++)
    {
        if(map[0][i]=='O') break;
        if(map[0][i]=='.') now+=con;
        if(map[0][i]=='F') nf^=1;
        if(map[0][i]=='S') now+=2*con;
        next[i][f]=now;
    }
    now=dp[0][y][f],con=1,nf=f;
    for(int i=y-1; i>=0; i--)
    {
        if(map[0][i]=='O') break;
        if(map[0][i]=='.') now+=con;
        if(map[0][i]=='F') nf^=1;
        if(map[0][i]=='S') now+=2*con;
        next[i][f]=now;
    }
}

priority_queue<FSO> que;
int AStar()
{
    FSO now;
    while(!que.empty())
    {
        now=que.top();
        que.pop();
        if(now.x==0)
        {
            if(map[now.x][now.y]=='H'&&now.f==1)
                return now.dis;
            getNow(now.y,now.f);
            for(int i=0; i<M; i++)
            {
                for(int f=0; f<2; f++)
                {
                    if(next[i][f]==-1) continue;
                    if(next[i][f]<dp[0][i][f])
                    {
                        dp[0][i][f]=next[i][f];
                        que.push(FSO(0,i,f,next[i][f],next[i][f]+getH(0,i)));
                    }
                }
            }
        }
        if(dp[now.x][now.y][now.f]<now.dis) continue;
        dp[now.x][now.y][now.f]=now.dis;
        getNext(now.x,now.y,now.f);
        for(int i=0; i<M; i++)
        {
            for(int f=0; f<2; f++)
            {
                if(next[i][f]==-1) continue;
                if(next[i][f]<dp[now.x-1][i][f])
                {
                    dp[now.x-1][i][f]=next[i][f];
                    que.push(FSO(now.x-1,i,f,next[i][f],next[i][f]+getH(now.x-1,i)));
                }
            }
        }
    }
    return -1;
}

void input()
{
    for(int j=0; j<M; j++)
    {
        map[0][j]=getchar();
        if(map[0][j]==' '||map[0][j]=='\n')
        {
            j--;
            continue;
        }
        if(map[0][j]=='H')
        {
            Hs[hn].x=0;
            Hs[hn++].y=j;
        }
    }
    for(int i=1; i<N-1; i++)
    {
        for(int j=0; j<M; j++)
        {
            map[i][j]=getchar();
            if(map[i][j]==' '||map[i][j]=='\n')
            {
                j--;
                continue;
            }
        }
    }
    for(int j=0; j<M; j++)
    {
        map[N-1][j]=getchar();
        if(map[N-1][j]==' '||map[N-1][j]=='\n')
        {
            j--;
            continue;
        }
        if(map[N-1][j]=='H')
        {
            map[N-1][j]='B';
            dp[N][j][0]=0;
            que.push(FSO(N,j,0,0,getH(N-1,j)));
        }
    }
    for(int j=0;j<M;j++)
    {
        map[N][j]='.';
    }
}

void init()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<M;j++)
            for(int f=0;f<2;f++)
                dp[i][j][f]=inf;
    while(!que.empty()) que.pop();
    hn=0;
}

void work()
{
    int res=AStar();
    if(res==-1)
        printf("No solution\n");
    else printf("%d\n",res);
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
