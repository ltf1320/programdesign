#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+10;
int N,M;
struct EDGE
{
    int next,to;
};
EDGE edge[maxn*2];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

bool del[maxn];

int dfn[maxn],low[maxn];
int cnt[maxn];
int fln;
int dep;

void dfs(int now,int id)
{
    low[now]=dfn[now]=++dep;
//    int ndep=low[now];
    if(id!=-1)
        cnt[now]++;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(del[edge[i].to])
            continue;
        if((i^id)==1) continue;//Í¬±ß
        if(dfn[edge[i].to])
        {
            if(dfn[edge[i].to]<low[now])
                low[now]=dfn[edge[i].to];
        }
        else
        {
            dfs(edge[i].to,i);
            if(low[edge[i].to]<low[now])
                low[now]=low[edge[i].to];
            if(low[edge[i].to]>=dfn[now])
                cnt[now]++;
        }
    }
}

void work()
{
    int nres,res=0;
    for(int i=0; i<N; i++)
    {
        del[i]=1;
        nres=0;
        dep=0;
        fln=0;
        memset(cnt,0,sizeof(cnt));
        memset(dfn,0,sizeof(dfn));
        for(int j=0; j<N; j++)
            if(!dfn[j]&&!del[j])
            {
                fln++;
                dfs(j,-1);
            }
        for(int j=0; j<N; j++)
            nres=max(nres,cnt[j]);
        res=max(res,nres+fln-1);
        del[i]=0;
    }
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
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
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
