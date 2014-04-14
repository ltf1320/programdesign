#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int MID=501;
int X,Y,N;
bool map[maxn][maxn];
int dis[maxn][maxn];
struct Node
{
    int x,y,dis;
    Node(){}
    Node(int xx,int yy,int d):x(xx),y(yy),dis(d){}
};
queue<Node> que;
int bfs()
{
    que.push(Node(MID,MID,0));
    Node now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.x==X&&now.y==Y)
        {
            while(!que.empty()) que.pop();
            return dis[X][Y];
        }
        if(!map[now.x-1][now.y]&&!dis[now.x-1][now.y])
        {
            dis[now.x-1][now.y]=now.dis+1;
            que.push(Node(now.x-1,now.y,now.dis+1));
        }
        if(!map[now.x+1][now.y]&&!dis[now.x+1][now.y])
        {
            dis[now.x+1][now.y]=now.dis+1;
            que.push(Node(now.x+1,now.y,now.dis+1));
        }
        if(!map[now.x][now.y-1]&&!dis[now.x][now.y-1])
        {
            dis[now.x][now.y-1]=now.dis+1;
            que.push(Node(now.x,now.y-1,now.dis+1));
        }
        if(!map[now.x][now.y+1]&&!dis[now.x][now.y+1])
        {
            dis[now.x][now.y+1]=now.dis+1;
            que.push(Node(now.x,now.y+1,now.dis+1));
        }
    }
    return -1;
}

void work()
{
    printf("%d\n",bfs());
}

void input()
{
    int x,y;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&x,&y);
        map[x+MID][y+MID]=1;
    }
}

void init()
{
    memset(map,0,sizeof(map));
    memset(dis,0,sizeof(dis));
    X+=MID;Y+=MID;
    for(int i=0;i<1000;i++)
    {
        map[0][i]=1;
        map[1002][i]=1;
        map[i][0]=1;
        map[i][1002]=1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&X,&Y,&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
