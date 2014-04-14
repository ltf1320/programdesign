#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn=30+10;
const LL inf=(LL)0x3f3f3f3f*0x3f3f3f3f;
const int MOD=99997;

const int dx[]={-1,-1,1,1,-2,-2,2,2};
const int dy[]={2,-2,2,-2,1,-1,1,-1};

int N,M;
int map[maxn][maxn];
struct Point
{
    Point(int xx,int yy):x(xx),y(yy){}
    Point (){}
    int x,y;
    bool check()
    {
        if(map[x][y]==2) return false;
        if(x>=0&&x<N&&y>=0&&y<M) return true;
        return false;
    }
    bool operator==(const Point &a)const
    {
        return x==a.x&&y==a.y;
    }
};
Point start,end;

LL mm[maxn][maxn]; //0 for min step,1 for ways
vector<Point> prePnt[maxn][maxn];

deque<Point> que;
bool in[maxn][maxn];
void getM(int sx,int sy)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            mm[i][j]=inf;
            prePnt[i][j].clear();
        }
    memset(in,0,sizeof(in));
    mm[sx][sy]=0;
    in[sx][sy]=1;
    que.push_back(Point(sx,sy));
    Point now,tp;
    int dd;
    while(!que.empty())
    {
        now=que.front();
        que.pop_front();
        for(int i=0;i<8;i++)
        {
            tp.x=now.x+dx[i];
            tp.y=now.y+dy[i];
            if(tp.check())
            {
                dd=1;
                if(map[tp.x][tp.y]==1||map[tp.x][tp.y]==3||map[tp.x][tp.y]==4)
                    dd=0;
                if(mm[tp.x][tp.y]>mm[now.x][now.y]+dd)
                {
                    mm[tp.x][tp.y]=mm[now.x][now.y]+dd;
                    prePnt[tp.x][tp.y].clear();
                    prePnt[tp.x][tp.y].push_back(now);
                    if(!in[tp.x][tp.y])
                    {
                        in[tp.x][tp.y]=1;
                        if(dd)
                            que.push_back(tp);
                        else que.push_front(tp);
                    }
                }
                else if(mm[tp.x][tp.y]==mm[now.x][now.y]+dd)
                    prePnt[tp.x][tp.y].push_back(now);
            }
        }
        in[now.x][now.y]=0;
    }
}

struct State
{
    bool use[maxn][maxn];
    bool operator==(const State &a)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(use[i][j]!=a.use[i][j])
                    return false;
        return true;
    }
    int getHas()
    {
        LL res;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                if(use[i][j])
                {
                    res+=i*M+(1<<j);
                }
            }
        return  res%MOD;
    }
};

vector<State> has[100000];
State nst;
LL way;

void hfind()
{
    int h=nst.getHas();
    for(int i=0;i<(int)has[h].size();i++)
    {
        if(has[h][i]==nst)
            return;
    }
    has[h].push_back(nst);
    way++;
}
void dfs(Point now)
{
    if(now==start)
    {
        hfind();
        return;
    }
    if(map[now.x][now.y]==0)
        nst.use[now.x][now.y]=1;
    for(int i=0;i<(int)prePnt[now.x][now.y].size();i++)
    {
        dfs(prePnt[now.x][now.y][i]);
    }
    nst.use[now.x][now.y]=0;
}
void findWay()
{
    way=0;
    memset(nst.use,0,sizeof(nst.use));
    dfs(end);
}

void work()
{
    getM(start.x,start.y);
    if(mm[end.x][end.y]==inf)
    {
        printf("-1\n");
        return;
    }
    findWay();
    printf("%I64d\n%I64d\n",mm[end.x][end.y],way);
}

void input()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==3)
            {
                start.x=i;
                start.y=j;
            }
            if(map[i][j]==4)
            {
                end.x=i;
                end.y=j;
            }
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        work();
    }
    return 0;
}
