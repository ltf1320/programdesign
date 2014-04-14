#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=250;
const int end=245;
const int inf=0x3f3f3f3f;
const int maxm=maxn*maxn;
int N,M;
struct EDGE
{
    int next,to,v,from;
};
EDGE edge[2*maxm];
int box[maxn];
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

void work()
{
    printf("%d\n",N-dinic(0,end));
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f*2,t*2+1,1);
    }
    for(int i=1;i<=N;i++)
    {
        add(0,i*2,1);
        add(i*2+1,end,1);
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        init();
        input();
        work();
    }
    return 0;
}
