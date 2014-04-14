#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int inf=0x3f3f3f3f;
int N,M,D;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}
bool sed[maxn];
int maxd[maxn];
int maxdn[maxn];
int maxd2[maxn];
int maxdn2[maxn];


void dfs1(int now,int from)
{
    if(sed[now])
        maxd[now]=0;
    else maxd[now]=-inf;
    maxdn[now]=now;
    maxd2[now]=-inf;
    maxdn2[now]=-1;
    int nxt;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        dfs1(edge[i].to,now);
        nxt=maxd[edge[i].to]+1;
        if(nxt>maxd[now])
        {
            maxd2[now]=maxd[now];
            maxdn2[now]=maxdn[now];
            maxd[now]=nxt;
            maxdn[now]=edge[i].to;
        }
        else if(nxt>maxd2[now])
        {
            maxd2[now]=nxt;
            maxdn2[now]=edge[i].to;
        }
    }
}

void dfs2(int now,int from,int md)
{
    if(md>maxd[now])
    {
        maxd2[now]=maxd[now];
        maxdn2[now]=maxdn[now];
        maxd[now]=md;
        maxdn[now]=from;
    }
    else if(md>maxd2[now])
    {
        maxd2[now]=md;
        maxdn2[now]=from;
    }
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        if(edge[i].to==maxdn[now])
            dfs2(edge[i].to,now,maxd2[now]+1);
        else dfs2(edge[i].to,now,maxd[now]+1);
    }
}

void work()
{
    dfs1(1,-1);
    for(int i=box[1];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==maxdn[1])
            dfs2(edge[i].to,1,maxd2[1]+1);
        else
            dfs2(edge[i].to,1,maxd[1]+1);
    }
    int ans=0;
    for(int i=1;i<=N;i++)
        if(maxd[i]<=D)
            ans++;
    printf("%d\n",ans);
}

void init()
{
    memset(sed,0,sizeof(sed));
    memset(box,-1,sizeof(box));
    ent=0;
}

void input()
{
    scanf("%d%d%d",&N,&M,&D);
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&f);
        sed[f]=1;
    }
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

int main()
{
   // freopen("in.txt","r",stdin);
    init();
    input();
    work();
    return 0;
}
