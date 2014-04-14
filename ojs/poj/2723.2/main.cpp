#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2048+1;
const int maxm=5000;
int N,M;
int mp[maxn];
struct Men
{
    int a,b;
};
Men ms[maxn];


struct EDGE
{
    int to,next;
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
int time;

void tarjan(int now)
{
    dfn[now]=low[now]=time++;
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
    time=1;
    fln=0;
}

void initMap()
{
    memset(box,-1,sizeof(box));
    ent=0;
}
int lstm;
bool check(int m)
{
    int start;
    initTarjan();
    if(lstm<m)
    {
        start=lstm+1;
    }
    else
    {
        initMap();
        start=0;
    }
    for(int i=start;i<m;i++)
    {
        add(ms[i].a^1,ms[i].b);
        add(ms[i].b^1,ms[i].a);
    }
    for(int i=0;i<N<<1;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<N;i++)
        if(fl[i<<1]==fl[i<<1|1])
            return false;
    return true;
}

int work()
{
    int l=0,r=M,m;
    while(r>=l)
    {
        m=(l+r)>>1;
        if(check(m))
            l=m+1;
        else r=m-1;
    }
    return r;
}

void input()
{
    lstm=M+1;
    int f,t;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&t);
        mp[f]=i<<1;
        mp[t]=i<<1|1;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        ms[i].a=mp[f];
        ms[i].b=mp[t];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        input();
        printf("%d\n",work());
    }
    return 0;
}
