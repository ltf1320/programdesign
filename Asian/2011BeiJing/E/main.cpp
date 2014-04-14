#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50+10;
const int maxm=10000+100;

struct EDGE
{
    int to,next;
    int cap,cost,kcost;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
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

int in[maxn];
int dis[maxn];
int from[maxn];
queue<int> que;

bool spfa(int f,int t)
{
    int now;
    for(int i=0; i<2*N+2; i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push(f);
    in[f]=1;
    dis[f]=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
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
    return dis[t];
}

int fyl(int f,int t)
{
    int cost=0;
    int mincap;
    while(spfa(f,t))
    {
        mincap=inf;
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[t]*mincap;
    }
    return cost;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
