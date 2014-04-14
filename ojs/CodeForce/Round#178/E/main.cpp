#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;  //!!
const int maxn=5000+10;
const LL inf=0x3ffffffffffffffLL;

int N;

struct EDGE
{
    int to,v,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int dep[maxn],son[maxn],S[maxn];
LL dp[maxn];
LL sum,Min;
int pnode;

void pre(int now,int from)
{
    son[now]=1;
    dep[now]=dep[from]+1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        pre(edge[i].to,now);
        son[now]+=son[edge[i].to];
    }
}
int root;
void getS(int now,int from)
{
    S[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from||edge[i].to==pnode) continue;
        getS(edge[i].to,now);
        S[now]+=S[edge[i].to];
    }
}

void dfs1(int now,int from)
{
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from||edge[i].to==pnode) continue;
        dfs1(edge[i].to,now);
        sum+=(LL)S[edge[i].to]*(S[root]-S[edge[i].to])*edge[i].v;  //Ç¿ÖÆ×ª»»
        dp[now]+=dp[edge[i].to]+(LL)S[edge[i].to]*edge[i].v;
    }
}

void dfs2(int now,int from,int ed)
{
    if(now==root)
    {
        Min=min(dp[now],Min);
    }
    else
    {
        dp[now]=dp[from]+(S[root]-2*S[now])*(LL)edge[ed].v;
        Min=min(dp[now],Min);
    }
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from||edge[i].to==pnode) continue;
        dfs2(edge[i].to,now,i);
    }
}

int main()
{
    int f,t,v;
    LL res=inf;
    ent=0;
    LL tmp;
    memset(box,-1,sizeof(box));
    scanf("%d",&N);
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
        add(t,f,v);
    }
    pre(1,0);
    for(int i=0;i<N-1;i++)
    {
        memset(dp,0,sizeof(dp));
        f=edge[2*i].to;
        t=edge[2*i+1].to;
        if(dep[f]>dep[t])
        {
            int a=f;
            f=t;
            t=a;
        }
        pnode=t;
        tmp=(LL)edge[2*i].v*(son[1]-son[pnode])*son[pnode]; //!!
        Min=inf;
        sum=0;
        root=1;
        getS(1,0);
        dfs1(1,0);
        dfs2(1,0,-1);
        tmp+=Min*son[pnode];
        tmp+=sum;
        sum=0;
        Min=inf;
        root=pnode;
        getS(pnode,f);
        dfs1(pnode,f);
        dfs2(pnode,f,-1);
        tmp+=Min*(son[1]-son[pnode]);
        tmp+=sum;
        res=min((LL)tmp,res);
    }
    printf("%I64d\n",res);
    return 0;
}


