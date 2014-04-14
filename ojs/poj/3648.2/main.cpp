#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn=5000+10;
const int maxm=50000+100;
int N,M;
struct EDGE
{
    int next,to,from;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int dfn[maxn],low[maxn];
int fl[maxn],fln;
vector<int> fls[maxn];
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

int indu[maxn];
queue<int> que;
vector<int> ft[maxn];
int opp[maxn];
int chose[maxn];

void initTopSort()
{
    memset(indu,0,sizeof(indu));
    while(!que.empty()) que.pop();
    for(int i=0;i<maxn;i++)
        ft[i].clear();
    memset(chose,0,sizeof(chose));
}

void topSort()
{
    for(int i=0;i<ent;i++)
    {
        if(fl[edge[i].to]!=fl[edge[i].from])
        {
            indu[fl[edge[i].from]]++;
            ft[fl[edge[i].to]].push_back(fl[edge[i].from]);
        }
    }
    for(int i=0;i<fln;i++)
        if(indu[i]==0)
            que.push(i);
    for(int i=0;i<N;i++)
    {
        opp[fl[i*2]]=fl[i*2+1];
        opp[fl[i*2+1]]=fl[i*2];
    }
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(chose[now]==0)
        {
            chose[now]=1;
            chose[opp[now]]=-1;
        }
        for(int i=0;i<(int)ft[now].size();i++)
        {
            indu[ft[now][i]]--;
            if(indu[ft[now][i]]==0)
                que.push(ft[now][i]);
        }
    }
}


void work()
{
    for(int i=0;i<N*2;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<N;i++)
    {
        if(fl[i*2]==fl[i*2+1])
        {
            printf("bad luck\n");
            return;
        }
    }
    topSort();
    for(int i=1;i<N;i++)
    {
        if(chose[fl[2*i]]==1)
            printf("%dh",i);
        else printf("%dw",i);
        if(i<N-1)
            putchar(' ');
        else puts("");
    }
}

void input()
{
    int f,t;
    char fc,tc;
    for(int i=0;i<M;i++)
    {
        scanf("%d%c%d%c",&f,&fc,&t,&tc);
        if(fc=='w')
            f=f*2;
        else f=f*2+1;
        if(tc=='w')
            t=t*2;
        else t=t*2+1;
        add(f,t^1);
        add(t,f^1);
    }
    add(0,1);
}

void init()
{
    initTarjan();
    initTopSort();
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        init();
        input();
        work();
    }
    return 0;
}
