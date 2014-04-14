#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int end=401;
const int inf=0x3f3f3f3f;
int G,B,M;
int map[maxn][maxn];

struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn*maxn];
int box[2*maxn];
int ent;

void _add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    edge[ent].v=v;
    box[f]=ent++;
}

void add(int f,int t)
{
    _add(f,t,1);
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
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        map[f][t]=1;
    }
    for(int i=1;i<=G;i++)
        for(int j=1;j<=B;j++)
            if(!map[i][j])
                add(i,j+200);
    for(int i=1;i<=G;i++)
        add(0,i);
    for(int i=1;i<=B;i++)
        add(i+200,end);
}


void work()
{
    int res=G+B-dinic(0,end);
    printf("%d\n",res);
}

void init()
{
    memset(map,0,sizeof(map));
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%d%d%d",&G,&B,&M))
    {
        cas++;
        if(!(G&&B&&M)) break;
        printf("Case %d: ",cas);
        init();
        input();
        work();
    }
    return 0;
}
