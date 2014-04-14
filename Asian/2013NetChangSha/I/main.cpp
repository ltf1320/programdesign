#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=20000+100;
const int maxm=100000+100;
const int inf=0x3f3f3f3f;

int X,Y,M;

int getS(char c)
{
    if(c<='9'&&c>='0')
        return c-'0';
    else return c-'A'+10;
}

struct EDGE
{
    int from,to,next;
    int v;
};
EDGE edge[maxm*2+maxn*2];
int box[maxn*2];
int ent;

void _add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].from=f;
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

int dfn[maxn],low[maxn];
int fl[maxn],fln;
int stack[maxn],top;
bool in[maxn];
int ti;

void tarjan(int now)
{
    dfn[now]=low[now]=ti++;
    stack[++top]=now;
    in[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].v==0) continue;
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
    }
    int nd;
    if(dfn[now]==low[now])
    {
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fl[nd]=fln;
            in[nd]=0;
            if(nd==now) break;
        }
        fln++;
    }
}

void initTarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    top=-1;
    fln=0;
}

int res;
int ress[maxm];
void work()
{
    int pi=dinic(0,1);
    initTarjan();
    for(int i=0;i<X+Y+2;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<M;i++)
    {
        if(edge[2*i].v&&fl[edge[2*i].from]!=fl[edge[2*i].to])
        {
            ress[res++]=i;
        }
    }
    printf("%d\n",res);
    for(int i=0;i<res;i++)
    {
        if(i) putchar(' ');
        printf("%d",ress[i]);
    }
    puts("");
}

void input()
{
    char tmp[10];
    int x,y;
    for(int i=0;i<M;i++)
    {
        scanf("%s",tmp);
        x=0;
        for(int j=0;j<3;j++)
        {
            x<<=5;
            x+=getS(tmp[j]);
        }
        y=0;
        for(int j=0;j<3;j++)
        {
            y<<=5;
            y+=getS(tmp[j+3]);
        }
        add(x+2,y+X+2,1);
    }
    for(int i=0;i<X;i++)
        add(0,i+2,1);
    for(int i=0;i<Y;i++)
        add(i+X+2,1,1);
}


void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    res=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&X,&Y,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
