#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=300+10;
const int inf=0x3f3f3f3f;

int N,M;
int mabs(int a)
{
    return a>0?a:-a;
}

struct Point
{
    int x,y;
};
Point Man[maxn],Hou[maxn];
int Mn,Hn;

int getDis(Point &a,Point &b)
{
    return mabs(a.x-b.x)+mabs(a.y-b.y);
}

struct EDGE
{
    int to,next,cap,cost,from;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].cap=cap;
    edge[ent].cost=cost;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap,int cost)
{
    _add(f,t,cap,cost);
    _add(t,f,0,-cost);
}

int dis[maxn];
bool in[maxn];
queue<int> que;
int from[maxn];
bool spfa(int f,int t)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<=Mn+Hn+2;i++)
        dis[i]=inf;
    memset(from,-1,sizeof(from));
    int now;
    que.push(f);
    dis[f]=0;
    in[f]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(edge[i].cap&&dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                dis[edge[i].to]=dis[now]+edge[i].cost;
                from[edge[i].to]=i;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return 0;
    else return 1;
}

int fyl(int s,int t)
{
    int cost=0;
    int mincap;
    while(spfa(s,t))
    {
        mincap=inf;
        for(int i=from[t];i!=-1;i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[t];i!=-1;i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[t]*mincap;
    }
    return cost;
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
                j--;continue;
            }
            switch(ch)
            {
                case 'm':
                    Man[Mn].x=i;
                    Man[Mn].y=j;
                    Mn++;
                    break;
                case 'H':
                    Hou[Hn].x=i;
                    Hou[Hn].y=j;
                    Hn++;
                    break;
                default:
                    break;
            }
        }
    for(int i=0;i<Mn;i++)
        add(0,i+2,1,0);
    for(int i=0;i<Hn;i++)
        add(i+Mn+2,1,1,0);
    for(int i=0;i<Mn;i++)
        for(int j=0;j<Hn;j++)
        {
            add(i+2,j+Mn+2,inf,getDis(Man[i],Hou[j]));
        }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    Mn=Hn=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        init();
        input();
        printf("%d\n",fyl(0,1));
    }
    return 0;
}
