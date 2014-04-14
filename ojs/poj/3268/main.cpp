#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxm=100000+10;
const int inf=0x3f3f3f3f;
int N,M,X;
int map[maxn][maxn];

struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int dis[maxn];
int xdis[maxn];
bool in[maxn];
queue<int> que;

void spfa(int s)
{
    for(int i=0;i<=N;i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    que.push(s);
    dis[s]=0;
    in[s]=1;
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
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
        }
        in[now]=0;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(box,-1,sizeof(box));
    scanf("%d%d%d",&N,&M,&X);
    int f,t,v;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            map[i][j]=inf;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
    }
    spfa(X);
    memcpy(xdis,dis,sizeof(dis));
    int res=0;
    for(int i=1;i<=N;i++)
    {
        spfa(i);
        if(dis[X]+xdis[i]>res)
            res=dis[X]+xdis[i];
    }
    printf("%d\n",res);
    return 0;
}
