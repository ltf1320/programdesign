#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+365+2+2+100;
const int maxm=(1000+365*100+365+1000+365+365)*2;
const int inf=0x3f3f3f3f;
int N,M;

struct EDGE
{
    int next,to,v;
    int l;
};
EDGE edge[maxm];
int box[maxn];
int ent;

int flow[maxn];
int c[500];


void _add(int f,int t,int v,int l=0)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].l=l;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int v,int l=0)
{
    _add(f,t,v,l);
    _add(t,f,0,l);
}


void Add(int f,int t,int l,int r)
{
    add(f,t,r-l,l);
    flow[f]-=l;
    flow[t]+=l;
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
    int t,l,r;
    int d;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&t);
        Add(4+i,3,t,inf);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&c[i],&d);
        Add(2,4+M+i,0,d);
        for(int j=0;j<c[i];j++)
        {
            scanf("%d%d%d",&t,&l,&r);
            Add(4+M+i,t+4,l,r);
        }
    }
}

void work()
{
    int pent=ent;
    Add(3,2,0,inf);
    for(int i=3;i<4+M+N;i++)
    {
        if(flow[i]>0)
            add(0,i,flow[i]);
        else if(flow[i]<0)
            add(i,1,-flow[i]);
    }
    dinic(0,1);
    for(int i=box[0];i!=-1;i=edge[i].next)
    {
        if(edge[i].v)
        {
            printf("-1\n\n");
            return;
        }
    }
    int res=edge[pent+1].v;
    edge[pent].v=edge[pent+1].v=0;
    res+=dinic(2,3);
    printf("%d\n",res);
    int p=M;
    for(int i=0;i<N;i++)
    {
        p++;
        for(int j=0;j<c[i];j++)
        {
            printf("%d\n",edge[p*2+1].v+edge[p*2].l);
            p++;
        }
    }
    puts("");
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(flow,0,sizeof(flow));
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
