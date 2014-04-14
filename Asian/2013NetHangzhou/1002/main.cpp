#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=500;
const int inf=0x3f3f3f3f;
int N;
struct Point
{
    int x,y;
};
Point pns[22];

struct EDGE
{
    int next,to,v;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void _add(int f,int t,int v)
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

int knt;
void work()
{
    knt=0;
    for(int ul=0;ul<N;ul++)
    {
        for(int ur=0;ur<N;ur++)
        {
            if(ul==ur) continue;
            if(pns[ul].y!=pns[ur].y) continue;
            if(pns[ur].x<=pns[ul].x) continue;
            for(int dl=0;dl<N;dl++)
            {
                if(pns[ul].y-pns[dl].y!=pns[ur].x-pns[ul].x) continue;
                if(pns[dl].y>=pns[ul].y) continue;
                if(dl==ul) continue;
                if(pns[dl].x!=pns[ul].x) continue;
                for(int dr=0;dr<N;dr++)
                {
                    if(pns[dr].y!=pns[dl].y) continue;
                    if(pns[dr].x!=pns[ur].x) continue;
                    add(knt+N+2,ur+2,1);
                    add(knt+N+2,ul+2,1);
                    add(knt+N+2,dr+2,1);
                    add(knt+N+2,dl+2,1);
                    knt++;
                }
            }
        }
    }
    for(int i=0;i<knt;i++)
        add(0,i+N+2,4);
    for(int i=0;i<N;i++)
        add(i+2,1,1);
    int pp=dinic(0,1);
    int res=0;
    for(int i=box[0];i!=-1;i=edge[i].next)
    {
        if(edge[i].v==0)
        {
            res+=4;
        }
    }
    printf("%d\n",res);
}


void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&pns[i].x,&pns[i].y);
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==-1) break;
        init();
        input();
        work();
    }
    return 0;
}
