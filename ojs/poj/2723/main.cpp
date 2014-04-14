#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2100;
const int maxm=20000;
int N,M;
struct Men
{
    int a,b;
};
Men ms[maxn];
Men key[maxn];

struct EDGE
{
    int to,next;
};
EDGE edge[maxm];
int box[maxn];
int box2[maxn];
int ent,ent2;

void add1(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add2(int f,int t)
{
    edge[ent2].to=t;
    edge[ent2].next=box2[f];
    box2[f]=ent2++;
}

void initMap2()
{
    ent2=ent;
    memset(box2,-1,sizeof(box2));
}
void initMap()
{
    ent=0;
    memset(box,-1,sizeof(box));
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
    for(int i=box2[now];i!=-1;i=edge[i].next)
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

bool check(int m)
{
    initMap2();
    for(int i=0;i<m;i++)
    {
        add2(ms[i].a*2+1,ms[i].b*2);
        add2(ms[i].b*2+1,ms[i].a*2);
    }
    initTarjan();
    for(int i=0;i<N*2;i++)
        if(!dfn[i])
            tarjan(i);
    for(int j=0;j<N;j++)
        {
            if(fl[j*2]==fl[j*2+1])
            {
                return false;
            }
        }
    return true;
}

int work()
{
    int l=0,r=M;
    int m;
    while(r>l)
    {
        m=(r+l)/2;
        if(check(m))
            l=m;
        else r=m-1;
    }
    return r;
}

void input()
{
    int f,t;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&t);
        add1(f*2,t*2+1);
        add1(t*2,f*2+1);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        ms[i].a=f;
        ms[i].b=t;
    }
}



int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        initMap();
        input();
        printf("%d\n",work());
    }
    return 0;
}
