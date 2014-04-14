#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=300;
const int maxm=5000+100;
const int inf=0x3f3f3f3f;
const int end=401;
int N,M;
struct EDGE
{
    int next,to,v,from;
};
EDGE edge[2*maxm];
int box[2*maxn];
int ent;

void _add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    edge[ent].v=v;
    box[f]=ent++;
}

void add(int f,int t,int v)
{
    _add(f,t,v);
    _add(t,f,0);
}

int level[2*maxn];
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
        for(int i=box[now]; i!=-1; i=edge[i].next)
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
                int minCap = inf+1;
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

void input()
{
    int tt,f,t;
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&tt);
        add(2*i+1,end,tt);
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&tt);
        add(0,2*i,tt);
    }
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        add(f*2,t*2+1,inf);
    }
}

bool vis[maxn];
void dfs(int now)
{
    vis[now]=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].v&&!vis[edge[i].to])
            dfs(edge[i].to);
    }
}

bool ans[maxn][2];

void work()
{
    printf("%d\n",dinic(0,end));
    int sum=0;
    memset(vis,0,sizeof(vis));
    dfs(0);
    for(int i=0; i<4*N; i++)
    {
        if(!edge[i].v&&(vis[edge[i].from]^vis[edge[i].to]))
        {
            if(edge[i].to==end)
            {
                sum++;
                ans[edge[i].from/2][0]=1;
            }
            if(edge[i].from==0)
            {
                sum++;
                ans[edge[i].to/2][1]=1;
            }
        }
    }
    printf("%d\n",sum);
    for(int i=1; i<=N; i++)
    {
        if(ans[i][0])
            printf("%d +\n",i);
        if(ans[i][1])
            printf("%d -\n",i);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(ans,0,sizeof(ans));
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
