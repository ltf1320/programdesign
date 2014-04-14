#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=5100;
const int maxm=20000+100;
const int inf=0x3f3f3f3f;

int N,K;
int map[maxn][maxn];

struct EDGE
{
    int from,to,next,cap,cost;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].from=f;
    edge[ent].to=t;
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
int from[maxn];
queue<int> que;

bool spfa(int f,int t)
{
    for(int i=0;i<maxn;i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push(f);
    dis[f]=0;
    in[f]=1;
    int now;
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
    if(dis[t]==inf) return false;
    else return true;
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

inline int getCode(int i,int j)
{
    return i*N+j+1;
}

void input()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            add(getCode(i,j)*2,getCode(i,j)*2+1,1,-map[i][j]);
            add(getCode(i,j)*2,getCode(i,j)*2+1,inf,0);
            if(i<N-1)
                add(getCode(i,j)*2+1,getCode(i+1,j)*2,inf,0);
            if(j<N-1)
                add(getCode(i,j)*2+1,getCode(i,j+1)*2,inf,0);
        }
    add(0,getCode(0,0)*2,K,0);
    add(getCode(N-1,N-1)*2+1,1,K,0);
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;

}

int main()
{
    freopen("in.txt","r",stdin);
  //  cout<<getCode(50,50)<<endl;
    while(~scanf("%d%d",&N,&K))
    {
        init();
        input();
        printf("%d\n",-fyl(0,1));
    }
    return 0;
}
