#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1000*2+100;
int N;
struct Wed
{
    int start,end;
};
Wed wds[maxn];
int chose[maxn];


struct EDGE
{
    int to,next,from;
};
EDGE edge[maxn*maxn];
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
int opfl[maxn];
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

bool judge(int i,int j)
{//
    if(wds[i].start>wds[j].start&&wds[i].start<wds[j].end) return true;
    if(wds[i].end>wds[j].start&&wds[i].end<wds[j].end) return true;
    if(wds[i].start<=wds[j].start&&wds[i].end>=wds[j].end) return true;
    if(wds[i].start>=wds[j].start&&wds[i].end<=wds[j].end) return true;
    return false;
}

void createMap()
{
    for(int i=0;i<2*N;i++)
        for(int j=0;j<2*N;j++)
        {
            if(i==j) continue;
            if(judge(i,j))
            {
                add(i,j^1);
                add(j,i^1);
            }
        }
}

queue<int> que;
int du[maxn];
vector<int> ft[maxn];
void topSort()
{
    for(int i=0;i<ent;i++)
        if(fl[edge[i].from]!=fl[edge[i].to])
        {
            ft[fl[edge[i].to]].push_back(fl[edge[i].from]);
            du[fl[edge[i].from]]++;
        }
    for(int i=0;i<fln;i++)
        if(du[i]==0)
            que.push(i);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(chose[now]!=-1)
        {
            chose[now]=1;
            chose[opfl[now]]=-1;
        }
        for(int i=0;i<(int)ft[now].size();i++)
        {
            du[ft[now][i]]--;
            if(du[ft[now][i]]==0)
                que.push(ft[now][i]);
        }
    }
}

void work()
{
    createMap();
    for(int i=0;i<2*N;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<N;i++)
    {
        if(!flag) break;
        if(fl[i*2]==fl[i*2+1])
        {
            flag=0;
        }
        opfl[fl[i*2]]=fl[i*2+1];
        opfl[fl[i*2+1]]=fl[i*2];
    }
    if(flag)
    {
        printf("YES\n");
        topSort();
        for(int i=0;i<N;i++)
        {
            if(chose[fl[i*2]]!=-1)
            {
                printf("%02d:%02d",wds[i*2].start/60,wds[i*2].start%60);
                printf(" %02d:%02d\n",wds[i*2].end/60,wds[i*2].end%60);
            }
            else
            {
                printf("%02d:%02d",wds[i*2+1].start/60,wds[i*2+1].start%60);
                printf(" %02d:%02d\n",wds[i*2+1].end/60,wds[i*2+1].end%60);
            }
        }
    }
    else printf("NO\n");
}

void input()
{
    int h1,m1,h2,m2,t;
    for(int i=0;i<N;i++)
    {
        scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&t);
        wds[i*2].start=h1*60+m1;
        wds[i*2].end=wds[i*2].start+t;
        wds[i*2+1].end=h2*60+m2;
        wds[i*2+1].start=wds[i*2+1].end-t;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    while(!que.empty()) que.pop();
    memset(du,0,sizeof(du));
    for(int i=0;i<maxn;i++)
        ft[i].clear();
    memset(dfn,0,sizeof(dfn));
    fln=0;
    top=-1;
    memset(in,0,sizeof(in));
    time=1;
    flag=1;
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
