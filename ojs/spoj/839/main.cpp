#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=5000+10;
const int maxm=6000+10;
const int inf=0x3f3f3f3f;
int N,M,K;

struct EDGE
{
    int to,next,v;
};
EDGE edge[maxm*2];
int box[maxn];
int ent;

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct ED
{
    int f,t;
};
ED eds[maxm];

int ps[maxn];

int level[maxn];
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

int lalala(int k)
{
    int pp=1<<k;
    ent=0;
    memset(box,-1,sizeof(box));
    for(int i=0; i<M; i++)
    {
        add(eds[i].f,eds[i].t,1);
        add(eds[i].t,eds[i].f,1);
    }
    for(int i=1; i<=N; i++)
    {
        if(ps[i]==-1) continue;
        if(ps[i]&pp)
            add(0,i,inf);
        else add(i,N+1,inf);
    }
    return dinic(0,N+1);
}
bool vis[maxn];
int flag[maxn];
void dfs(int now)
{
    vis[now]=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].v&&!vis[edge[i].to])
            dfs(edge[i].to);
    }
}
int ans[maxn];

void work()
{
    for(int i=0; i<31; i++)
    {
        lalala(i);
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        dfs(0);
        /*
        for(int j=0;j<M;j++)
        {
            if(vis[eds[j].f]!=vis[eds[j].t])
            {
                if(vis[eds[j].f])
                    flag[eds[j].f]++;
                else flag[eds[j].f]--;
                vis[eds[j].f]=vis[eds[j].t]=0;
            }
        }
        */
        for(int j=1;j<=N;j++)
        {
            if(ps[j]!=-1) continue;
            if(vis[j])
                ans[j]+=1<<i;
        }
    }
    for(int j=1;j<=N;j++)
        printf("%d\n",ans[j]);
}

void input()
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&eds[i].f,&eds[i].t);
    }
    scanf("%d",&K);
    memset(ps,-1,sizeof(ps));
    memset(ans,0,sizeof(ans));
    int u,p;
    for(int i=0; i<K; i++)
    {
        scanf("%d%d",&u,&p);
        ps[u]=p;
        ans[u]=p;
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
