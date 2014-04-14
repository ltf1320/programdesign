#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=30+10;
const LL inf=(LL)0x3f3f3f3f*0x3f3f3f3f;

const int dx[]={-1,-1,1,1,-2,-2,2,2};
const int dy[]={2,-2,2,-2,1,-1,1,-1};

int N,M;
int map[maxn][maxn];

struct Point
{
    Point(int xx,int yy):x(xx),y(yy){}
    Point (){}
    int getId()
    {
        return x*M+y;
    }
    int x,y;
    bool check()
    {
        if(map[x][y]==2) return false;
        if(x>=0&&x<N&&y>=0&&y<M) return true;
        return false;
    }
};
Point start,end;

struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxn*maxn*maxn];
int box[maxn*maxn];
int ent;
int did[maxn*maxn][maxn*maxn];

void add(int f,int t,int v)
{
 //   printf("%d %d %d %d %d\n",f/M,f%M,t/M,t%M,v);
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}
vector<Point> bibao;
int bel[maxn][maxn];

void enclose(Point pt)
{
    bel[pt.x][pt.y]=1;
    bibao.push_back(pt);
    Point now;
    for(int i=0;i<8;i++)
    {
        now.x=pt.x+dx[i];
        now.y=pt.y+dy[i];
        if(now.check())
        {
            if(bel[now.x][now.y]) continue;
            if(map[now.x][now.y]==1)
                enclose(now);
        }
    }
}
bool vis[maxn*maxn];
void getEdge()
{
    queue<int> que;
    que.push(start.getId());
    memset(vis,0,sizeof(vis));
    vis[start.getId()]=1;
    int now;
    int nx,ny;
    Point tp;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        nx=now/M;
        ny=now%M;
        if(map[nx][ny]==1||map[nx][ny]==4) continue;
        memset(bel,0,sizeof(bel));
        bibao.clear();
        enclose(Point(nx,ny));
        for(int i=0;i<(int)bibao.size();i++)
        {
            for(int j=0;j<8;j++)
            {
                tp.x=bibao[i].x+dx[j];
                tp.y=bibao[i].y+dy[j];
                if(!tp.check()) continue;
                if(bel[tp.x][tp.y]) continue;
                if(!did[now][tp.getId()])
                {
                    did[now][tp.getId()]=1;
                    add(now,tp.getId(),1);
                }
                if(!vis[tp.getId()])
                {
                    vis[tp.getId()]=1;
                    que.push(tp.getId());
                }
            }
        }
    }
}

bool in[maxn*maxn];
LL dis[maxn*maxn];
queue<int> que;
LL way[maxn*maxn];

bool spfa(int s,int t)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<N*M;i++)
        dis[i]=inf;
    dis[s]=0;
    in[s]=1;
    way[s]=1;
    que.push(s);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now==end.getId())continue;
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                way[edge[i].to]=way[now];
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
            else if(dis[edge[i].to]==dis[now]+edge[i].v)
            {
                way[edge[i].to]+=way[now];
            }
        }
        in[now]=0;
        way[now]=0;
    }
    if(dis[t]==inf) return false;
    return true;
}

void work()
{
    getEdge();
  //  printbel();
    if(!spfa(start.getId(),end.getId()))
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n%I64d\n",dis[end.getId()]-1,way[end.getId()]);
    }
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

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    memset(bel,0,sizeof(bel));
    memset(did,0,sizeof(did));
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    {
        init();
        input();
        work();
    }
    return 0;
}
