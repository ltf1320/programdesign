#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
const int inf=0x3f3f3f3f;
int pre[maxm];
int N,M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn*maxm];
int box[maxn+maxm];
int ent;
void _add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void add(int from,int to,int v)
{
    _add(from,to,v);
    _add(to,from,0);
}
int level[maxm+maxn];
bool getlevel(int s,int t)
{
    int now;
    memset(level,-1,sizeof(level));
    level[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(level[edge[i].to]!=-1) continue;
            if(edge[i].v==0) continue;
            level[edge[i].to]=level[now]+1;
            que.push(edge[i].to);
        }
    }
    return level[t]!=-1;
}
int que[maxn+maxm];
int dinic(int s,int t)
{
    int ans = 0;
    while(getlevel(s,t))
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
int tn;
void input()
{
    int t,k;
    tn=2;
    for(int i=0; i<M; i++)
    {
        scanf("%d",&t);
        add(0,tn++,t);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d",&t);
        for(int j=0; j<t; j++)
        {
            scanf("%d",&k);
            if(pre[k]!=-1)
                add(pre[k],tn,inf);
            pre[k]=tn;
            add(k+1,tn,inf);
        }
        scanf("%d",&k);
        add(tn,1,k);
        tn++;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(pre,-1,sizeof(pre));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&M,&N))
    {
        init();
        input();
        printf("%d\n",dinic(0,1));
    }
    return 0;
}
