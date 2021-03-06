#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=300;
const int maxm=maxn*maxn;
const int inf=0x3f3f3f3f;
int N;

struct EDGE
{
    int from,to,cap,cost,next;
};
EDGE edge[maxm];
int box[maxn];
int ent;

int flow[maxn];

struct Node
{
    int x,y,z,w;
};
Node nds[maxn];
int getDis(Node &a,Node &b)
{
    return (int)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

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

void Add(int f,int t,int l,int r,int cost)
{
    add(f,t,r-l,cost);
    flow[f]-=l;
    flow[t]+=l;
}


bool vis[maxn];
int cost,ans;
const int T=1;
int que[maxn*10];
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
                    if (edge[now].v &&edge[now].cost && level[y] >= level[x] + 1)
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

bool modlabel()
{
    int delta = inf;
    for(int u = 0; u < 2+2*N; u++)//找最小可增广费用
        if(vis[u])
            for(int i = box[u]; i != -1; i = edge[i].next)
                if(edge[i].cap && !vis[edge[i].to] && edge[i].cost < delta)
                    delta = edge[i].cost;
    if(delta == inf) return false;
    for(int u = 0; u < 2+2*N; u++)
        if(vis[u])
            for(int i = box[u]; i != -1; i = edge[i].next)//对于两个点都在里面的，正向修改一次，反向修改一次，即没修改
                edge[i].cost -= delta, edge[i^1].cost += delta;
    cost += delta;
    return true;
}
void costflow()
{
    do
    {
        memset(vis, 0, sizeof(vis));
        ans+=cost*dinic(0,T);
    }while(modlabel());
}

void work()
{
    for(int i=0;i<N;i++)
    {
        Add(2+2*i,2+2*i+1,nds[i].w,nds[i].w,0);
        for(int j=0;j<N;j++)
        {
            if(i==j) continue;
            Add(2+2*i+1,2+2*j,0,inf,getDis(nds[i],nds[j]));
        }
    }
    for(int i=2;i<2+2*N;i++)
    {
        if(flow[i]>0)
            add(0,i,flow[i],0);
        else if(flow[i]<0)
            add(i,1,-flow[i],0);
    }
    ans=0;
    costflow();
    for(int i=box[0];i!=-1;i=edge[i].next)
    {
        if(edge[i].cap)
        {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",ans);
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&nds[i].x,&nds[i].y,&nds[i].z,&nds[i].w);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    cost=0;
    memset(flow,0,sizeof(flow));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        init();
        input();
        work();
    }
    return 0;
}
