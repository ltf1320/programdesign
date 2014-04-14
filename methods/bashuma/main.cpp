#include <iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
const int size=3;
const int maxn=1000000;

class Board
{
public:
    Board(const Board &a)
    {
        memcpy(tu,a.tu,sizeof(a));
    }
    Board()
    {
        memset(tu,0,sizeof(tu));
    }
    int tu[5][5];
    void read()
    {
        for(int i=0; i<size; ++i)
            for(int j=0; j<size; ++j)
                cin>>tu[i][j];
    }
};

Board state[maxn];
Board goal;
int dis[maxn];
int dx[]= {-1,-1,0,0};
int dy[]= {0,0,-1,-1};
set<int> vis;

bool nrep(const Board &board,const int rear)
{
    int code=0;
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            code=code*10+board.tu[i][j];
    cout<<code<<endl;
    if(vis.count(code)) return 0;
    vis.insert(code);
    return 1;
}

int bfs()
{
    vis.clear();
    int front=1,rear=2;
    while(front<rear)
    {
        Board &now=state[front];
        if(memcmp(now.tu,goal.tu,sizeof(now.tu))==0)
            return dis[front];
        for(int i=0; i<4; ++i)
        {
            int zx=-1,zy=-1;
            for(int j=0; j<size; ++j)
                for(int k=0; k<size; ++k)
                    if(now.tu[i][j]==0)
                    {
                        zx=j;
                        zy=k;
                    }
            int newx=zx+dx[i],newy=zy+dy[i];
            if(newx>=0&&newx<size&&newy>=0&&newy<size)
            {
                Board next(now);
                next.tu[zx][zy]=now.tu[newx][newy];
                next.tu[newx][newy]=now.tu[zx][zy];
                if(nrep(next,rear))
                {
                    state[rear]=next;
                    dis[rear++]=dis[front]+1;
                }
            }
        }
        front++;
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    Board start;
    start.read();
    goal.read();
    state[1]=start;
    dis[1]=0;
    int result=bfs();
    if(result>0)
        cout<<result;
    else cout<<-1;
    cout<<endl;
    return 0;
}
