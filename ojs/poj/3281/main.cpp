#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=400+10;
const int inf=0x3f3f3f3f;
int N,F,D;
struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void _add(int f,int t,int cap)
{
    edge[ent].to=t;
    edge[ent].v=cap;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap)
{
    _add(f,t,cap);
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

void input()
{
    int f,d;
    int tt;
    for(int i=0;i<F;i++)
    {
        add(0,2+2*N+i,1);
    }
    for(int i=0;i<D;i++)
        add(2+2*N+F+i,1,1);
    for(int i=0;i<N;i++)
        add(2+i,2+N+i,1);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&d);
        for(int j=0;j<f;j++)
        {
            scanf("%d",&tt);
            add(tt+2*N+1,2+i,1);
        }
        for(int j=0;j<d;j++)
        {
            scanf("%d",&tt);
            add(2+N+i,tt+2*N+F+1,1);
        }
    }
}

void work()
{
    printf("%d\n",dinic(0,1));
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&F,&D);
    init();
    input();
    work();
    return 0;
}
