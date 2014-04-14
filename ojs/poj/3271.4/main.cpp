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
EDGE edge[maxn*maxn*8];
int box[maxn*maxn];
int ent;
int did[maxn*maxn][maxn*maxn];

void add(int f,int t,int v)
{
    printf("%d %d %d\n",f,t,v);
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

vector<Point> bibao[maxn*maxn];
int bin;
int bel[maxn][maxn];

void printbel()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            printf("%d ",bel[i][j]);
        puts("");
    }
    puts("");
}

void enclose(int n,Point pt)
{
    bel[pt.x][pt.y]=n;
    bibao[n].push_back(pt);
    Point now;
    for(int i=0;i<8;i++)
    {
        now.x=pt.x+dx[i];
        now.y=pt.y+dy[i];
        if(now.check())
        {
            if(map[now.x][now.y]==1)
                enclose(n,now);
        }
    }
}

void getEdge()
{
    bin=1;
    enclose(bin++,start);
    queue<int> que;
    que.push(1);
    int now;
    Point tp;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<(int)bibao[now].size();i++)
        {
            for(int j=0;j<8;j++)
            {
                tp.x=bibao[now][i].x+dx[j];
                tp.y=bibao[now][i].y+dy[j];
                if(!tp.check()) continue;
                if(!bel[tp.x][tp.y])
                {
                    enclose(bin,tp);
                    que.push(bin);
                    bin++;
 //                   printbel();
                }
                if(now!=bel[tp.x][tp.y]&&!did[now][bel[tp.x][tp.y]])
                {
                    did[now][bel[tp.x][tp.y]]=1;
                    add(now,bel[tp.x][tp.y],1);
                }
            }
        }
    }
    printbel();
}

bool in[maxn*maxn];
int dis[maxn*maxn];
queue<int> que;
LL way[maxn*maxn];

bool spfa(int s,int t)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<bin;i++)
        dis[i]=0x3f3f3f3f;
    dis[s]=0;
    in[s]=1;
    way[s]=1;
    que.push(s);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
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
    }
    if(dis[t]==0x3f3f3f3f) return false;
    return true;
}

void work()
{
    getEdge();
  //  printbel();
    if(!spfa(1,bel[end.x][end.y]))
    {
        printf("-1\n-1\n");
    }
    else
    {
        printf("%d\n%I64d\n",dis[bel[end.x][end.y]]-1,way[bel[end.x][end.y]]);
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
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
