#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=5000+100;
const int maxm=60000+100;
const LL inf=1E9;
int N,M;
LL sum;

struct EDGE
{
    int next,to;
    LL v;
};
EDGE edge[maxm*2];
int box[maxn];
int ent;
void _add(int f,int t,LL v)
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

int que[maxn*10];
LL dinic(int s,int t)
{
    LL ans = 0;
    while(makelevel(s,t))
    {
        LL now, x, y, back, iter = 1;
        while(iter)
        {
            x = (iter == 1) ? s : edge[que[iter - 1]].to;
            if (x == t)
            {
                LL minCap = inf;
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
    ent=0;
    sum=0;
    memset(box,-1,sizeof(box));
    int n,v;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&v);
        if(v>0)
        {
            sum+=v;
            add(0,i,v);
        }
        if(v<0)
            add(i,N+1,-v);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&n,&v);
        add(n,v,inf);
    }
}


bool vis[maxn];
int num;
void dfs(int now)
{
    num++;
    vis[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
        if(edge[i].v&&!vis[edge[i].to])
            dfs(edge[i].to);
}

void work()
{
    LL flow;
    num=-1;
    flow=dinic(0,N+1);
    memset(vis,0,sizeof(vis));
    dfs(0);
    cout<<num<<" "<<sum-flow<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        work();
    }
    return 0;
}
