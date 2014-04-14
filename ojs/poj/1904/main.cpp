#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=2*2000+100;
const int maxm=2*200000+100;
int N;

struct EDGE
{
    int next,to;
};
EDGE edge[maxm];
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
    int t,s;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&t);
        for(int j=0;j<t;j++)
        {
            scanf("%d",&s);
            add(i,s+N);
        }
    }
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&s);
        add(s+N,i);
    }
}

int ans;
int s[maxn];

void work()
{
    initTarjan();
    for(int i=1;i<=2*N;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=N;i++)
    {
        ans=0;
        for(int j=box[i];j!=-1;j=edge[j].next)
        {
            if(fl[i]==fl[edge[j].to])
            {
                s[ans++]=edge[j].to-N;
            }
        }
        sort(s,s+ans);
        printf("%d",ans);
        for(int j=0;j<ans;j++)
            printf(" %d",s[j]);
        puts("");
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
    while(~scanf("%d",&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
