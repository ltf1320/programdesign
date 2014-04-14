#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn=500+100;
const int maxm=2000+100;
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

vector<int> ft[maxn];
int indu[maxn];
int chose[maxn];
int opp[maxn];
queue<int> que;
void topSort()
{
    int now;
    for(int i=0;i<ent;i++)
        if(fl[edge[i].from]!=fl[edge[i].to])
        {
            indu[fl[edge[i].from]]++;
            ft[fl[edge[i].to]].push_back(edge[i].from);
        }
    for(int i=0;i<N;i++)
    {
        opp[fl[i*2]]=fl[i*2+1];
        opp[fl[i*2+1]]=fl[i*2];
    }
    chose[fl[0]]=1;
    chose[fl[1]]=-1;
    que.push(fl[0]);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<(int)fls[fl[now]].size();i++)
        {
            for(int j=box[fls[now][i]];j!=-1;j=edge[j].next)
            {
                if(fl[edge[j].to]!=now)
                {
                    que.push(fl[edge[j].to]);
                    chose[fl[edge[j].to]]=1;
                    chose[fl[edge[j].to]]=-1;
                }
            }
        }
    }
    que.push(fl[1]);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<(int)fls[fl[now]].size();i++)
        {
            for(int j=box[fls[now][i]];j!=-1;j=edge[j].next)
            {
                if(fl[edge[j].to]!=now)
                {
                    que.push(fl[edge[j].to]);
                    chose[fl[edge[j].to]]=-1;
                    chose[fl[edge[j].to]]=1;
                }
            }
        }
    }
    for(int i=0;i<fln;i++)
        if(indu[i]==0)
            que.push(i);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(chose[now]!=-1)
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
        if(fl[i*2]==fl[i*2+1])
        {
            printf("bad luck\n");
            return;
        }
    topSort();

    for(int i=1;i<N;i++)
    {
        if(chose[fl[i*2]]==1)
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
    char fch,tch;
    for(int i=0;i<M;i++)
    {
        scanf("%d%c%d%c",&f,&fch,&t,&tch);
        if(fch=='w')
            f=f*2;
        else f=f*2+1;
        if(tch=='w')
            t=t*2;
        else t=t*2+1;
        add(f,t^1);
        add(t,f^1);
    }
    add(1,0);
}

void init()
{
    initTarjan();
    ent=0;
    memset(box,-1,sizeof(box));
    for(int i=0;i<maxn;i++)
        ft[i].clear();
    while(!que.empty()) que.pop();
    memset(chose,0,sizeof(chose));
    memset(indu,0,sizeof(indu));
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
