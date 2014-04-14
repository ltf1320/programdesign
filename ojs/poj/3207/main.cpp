#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1000+100;
int N,M;

struct EDGE
{
    int to,next;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct CON
{
    int a,b;
};
CON cns[maxn];

int dfn[maxn],low[maxn];
int fl[maxn],fln;
vector<int> fls[maxn];
int stack[maxn],top;
bool in[maxn];
int time;
    bool flag;

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
        fls[fln].clear();
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fls[fln].push_back(nd);
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

void input()
{
    int t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&cns[i].a,&cns[i].b);
        if(cns[i].a>cns[i].b)
        {
            t=cns[i].b;
            cns[i].b=cns[i].a;
            cns[i].a=t;
        }
    }
}

bool judge(int i,int j)
{
    if(cns[j].a>cns[i].a&&cns[j].a<cns[i].b)
    {
        if(cns[j].b>cns[i].b||cns[j].b<cns[i].a)
            return true;
    }
    if(cns[j].a<cns[i].a)
    {
        if(cns[j].b>cns[i].a&&cns[j].b<cns[i].b)
            return true;
    }
    return false;
}

bool work()
{
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
        {
            if(i==j) continue;
            if(judge(i,j))
            {
                add(i*2,j*2+1);
                add(i*2+1,j*2);
            }
        }
    for(int i=0;i<2*M;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<M;i++)
        if(fl[i*2]==fl[i*2+1])
            return false;
    return true;
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    initTarjan();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        if(work())
            printf("panda is telling the truth...\n");
        else
            printf("the evil panda is lying again\n");
    }
    return 0;
}
