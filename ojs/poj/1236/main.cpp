#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxm=maxn*maxn;
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

int low[maxn],dfn[maxn];
int time;
bool in[maxn];
int fln,fl[maxn];
int stack[maxn],top;
int indu[maxn],outdu[maxn];

void tarjan(int now)
{
    low[now]=dfn[now]=time++;
    in[now]=1;
    stack[++top]=now;
    for(int i=box[now]; i!=-1; i=edge[i].next)
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

void work()
{
    int resA,resB;
    for(int i=1; i<=N; i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1; i<=N; i++)
        for(int j=box[i]; j!=-1; j=edge[j].next)
        {
            if(fl[i]!=fl[edge[j].to])
            {
                indu[fl[edge[j].to]]++;
                outdu[fl[i]]++;
            }
        }
    int inn=0,outn=0;
    for(int i=0; i<fln; i++)
    {
        if(indu[i]==0)
            inn++;
        if(outdu[i]==0)
            outn++;
    }
    resA=inn;
    resB=max(inn,outn);
    if(fln==1) resB=0;
    printf("%d\n%d\n",resA,resB);
}

void input()
{
    int tmp;
    for(int i=1; i<=N; i++)
    {
        while(1)
        {
            scanf("%d",&tmp);
            if(tmp==0) break;
            add(i,tmp);
        }
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    time=1;
    fln=0;
    top=-1;
    memset(in,0,sizeof(in));
    memset(indu,0,sizeof(indu));
    memset(outdu,0,sizeof(outdu));
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
