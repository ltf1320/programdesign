#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxm=200000+1000+100;
int N,M;
int res;
struct EDGE
{
    int next,to;
    int from;
};
EDGE edge[2*maxm];
bool is[maxm*2];
int box[maxn];
int ent;

void _add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t)
{
    _add(f,t);
    _add(t,f);
}

int pre[maxn],anc[maxn];
bool vis[maxn];
int from[maxn];

void dfs(int now,int fa,int dep)
{
    anc[now]=pre[now]=dep;
    vis[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa&&vis[edge[i].to])
        {
            if(pre[edge[i].to]<anc[now])
                anc[now]=pre[edge[i].to];//
        }
        if(!vis[edge[i].to])
        {
            from[edge[i].to]=i;
            dfs(edge[i].to,now,dep+1);
            if(anc[edge[i].to]<anc[now])
                anc[now]=anc[edge[i].to];
            if(anc[edge[i].to]>pre[now])
            {
                is[i]=1;
                res++;
            }
        }
    }
}

void insert(int f,int t)
{
    while(pre[f]<pre[t])
    {
        if(is[from[t]])
        {
            is[from[t]]=0;
            res--;
        }
        t=edge[from[t]].from;
    }
    while(pre[f]>pre[t])
    {
        if(is[from[f]])
        {
            is[from[f]]=0;
            res--;
        }
        f=edge[from[f]].from;
    }
    while(t!=f)
    {
        if(is[from[t]])
        {
            is[from[t]]=0;
            res--;
        }
        t=edge[from[t]].from;
        if(is[from[f]])
        {
            is[from[f]]=0;
            res--;
        }
        f=edge[from[f]].from;
    }
}

void work()
{
    int Q;
    int f,t;
    res=0;
    dfs(1,-1,1);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%d%d",&f,&t);
        insert(f,t);
        printf("%d\n",res);
    }
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(pre,0,sizeof(pre));
    memset(anc,0,sizeof(anc));
    memset(vis,0,sizeof(vis));
    memset(is,0,sizeof(is));
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%d%d",&N,&M)&&N&&M)
    {
        cas++;
        printf("Case %d:\n",cas);
        init();
        input();
        work();
    }
    return 0;
}
