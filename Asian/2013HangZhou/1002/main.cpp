#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N,M,K;

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int map[maxn][maxn];
int startx,starty;
int dis[1<<4][maxn][maxn];
int res;
struct Node
{
    int st,x,y,dis;
    Node(int s,int xx,int yy,int d):st(s),x(xx),y(yy),dis(d){}
    Node(){}
};

queue<Node> que;

void work()
{
    int nx,ny,nst;
    Node now;
    now.st=map[startx][starty];
    now.x=startx;
    now.y=starty;
    now.dis=0;
    que.push(now);
    dis[now.st][now.x][now.y]=0;
    res=inf;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.st==(1<<K)-1)
        {
            res=min(res,now.dis);
            continue;
        }
        for(int i=0;i<4;i++)
        {
            nx=now.x+dx[i];
            ny=now.y+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(map[nx][ny]==-1) continue;
            nst=now.st|map[nx][ny];
            if(dis[nst][nx][ny]==-1||now.dis+1<dis[nst][nx][ny])
            {
                dis[nst][nx][ny]=now.dis+1;
                que.push(Node(nst,nx,ny,now.dis+1));
            }
        }
    }
    if(res==inf)
        puts("-1");
    else
        printf("%d\n",res);
}

void input()
{
    char ch;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            ch=getchar();
            if(ch==' '||ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='#')
                map[i][j]=-1;
            if(ch=='.')
                map[i][j]=0;
            if(ch=='@')
            {
                map[i][j]=0;
                startx=i;
                starty=j;
            }
        }
    scanf("%d",&K);
    int x,y;
    for(int i=0;i<K;i++)
    {
        scanf("%d%d",&x,&y);
        x--;y--;
        map[x][y]|=1<<i;
    }
}

void init()
{
    memset(dis,-1,sizeof(dis));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)
            break;
        init();
        input();
        work();
    }
    return 0;
}
