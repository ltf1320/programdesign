#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define p2(x) ((x)*(x))
using namespace std;
const int maxn=150+10;
const int maxk=3;
const int maxm=maxn*maxk*100;
const int inf=0x3f3f3f3f;
int N,M;
int NN;
int need[maxn][10];
int begtime[maxn],endtime[maxn];
struct Point
{
    int x,y;
};
Point pts[maxn];
Point depot;

int dis[maxn][maxn];

int getDis(Point &a,Point &b)
{
    return ceil(sqrt(1.0*p2(a.x-b.x)+p2(a.y-b.y)));
}

struct EDGE
{
    int next,to,v;
};
EDGE edge[maxm];
int box[maxn*maxk];
int ent;

void _add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int v)
{
    _add(f,t,v);
    _add(t,f,0);
}

int level[maxn*maxk];
bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    level[s]=1;
    queue<int> que;
    que.push(s);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(edge[i].v==0) continue;
            if(level[edge[i].to]) continue;
            level[edge[i].to]=level[now]+1;
            que.push(edge[i].to);
            if(edge[i].to==t) return 1;
        }
    }
    return false;
}


int que[maxn*maxk*10];
int dinic(int s,int t)
{
    int ans = 0;
    while(makelevel(s,t))
    {
        int now, x, y, back, iter = 1;
        while(iter)
        {
            x = (iter == 1) ? s : edge[que[iter - 1]].to;
            if (x == t)
            {
                int minCap = inf;
                for (int i = 1; i < iter; i++)
                {
                    now = que[i];
                    if (edge[now].v < minCap)
                    {
                        minCap = edge[now].v;
                        back = i;
                    }
                }
                for (int i = 1; i < iter; i++)
                {
                    now = que[i];
                    edge[now].v -= minCap;
                    edge[now ^ 1].v += minCap;
                }
                ans += minCap;
                iter = back;
            }
            else
            {
                for (now = box[x]; now + 1; now = edge[now].next)
                {
                    y = edge[now].to;
                    if (edge[now].v && level[y] >= level[x] + 1)
                        break;
                }
                if (now+1)
                    que[iter++] = now;
                else
                {
                    level[x] = -1;
                    iter--;
                }
            }
        }
    }
    return ans;
}

void initMap()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

void work()
{
    int sum=0,res=0;
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            if(i!=j)
                dis[i][j]=getDis(pts[i],pts[j]);
    for(int k=0; k<M; k++)
    {
        initMap();
        for(int i=1;i<N;i++)
        {
            add(0,i*2+2,need[i][k]);
            add(i*2+1+2,1,need[i][k]);
            sum+=need[i][k];
        }
        for(int i=1; i<N; i++)
        {
            for(int j=1; j<N; j++)
            {
                if(i==j) continue;
                if(endtime[i]+dis[i][j]<=begtime[j])
                {
                    add(i*2+2,j*2+1+2,inf);
                }
            }
        }
        res+=dinic(0,1);
    }
    printf("%d\n",sum-res);
}

void input()
{
    scanf("%d%d",&N,&M);
    NN=N*M+2;
    scanf("%d%d",&depot.x,&depot.y);
    for(int i=1; i<N; i++)
    {
        scanf("%d%d",&pts[i].x,&pts[i].y);
        scanf("%d%d",&begtime[i],&endtime[i]);
        for(int j=0; j<M; j++)
            scanf("%d",&need[i][j]);
        endtime[i]+=begtime[i];
    }
}



int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
