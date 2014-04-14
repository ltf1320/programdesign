#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=20000*2+100;
const int maxm=200000*4+1000;
const int inf=0x3f3f3f3f;
typedef long long LL;
int N,M;
struct EDGE
{
    int to,next,v;
};
EDGE edge[maxm];
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

void work()
{
    printf("%d\n",dinic(0,1));
}

void input()
{
    int a,b,v;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&a,&b);
        add(0,i*2+2,a);
        add(i*2+1+2,1,b);
        add(i*2+2,i*2+1+2,inf);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&a,&b,&v);
        a--;b--;
        add(a*2+2,b*2+1+2,v);
        add(b*2+2,a*2+1+2,v);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
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
