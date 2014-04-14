#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200+10;
const int maxm=maxn*maxn;
int N;

int map[maxn][maxn];

struct EDGE
{
    int next,to;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
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

void input()
{
    int t;
    for(int i=1;i<=N;i++)
    {
        while(true)
        {
            scanf("%d",&t);
            if(t==0) break;
            map[i][t]=1;
        }
    }
}

void work()
{
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        {
            if(!(map[i][j]&&map[j][i]))
            {
                add(i*2+1,j*2);
                add(i*2,j*2+1);
                add(j*2+1,i*2);
                add(j*2,i*2+1);
            }
        }
    initTarjan();
    for(int i=1;i<=2*N;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=N;i++)
        if(fl[i*2]==fl[i*2+1])
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(map,0,sizeof(map));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
