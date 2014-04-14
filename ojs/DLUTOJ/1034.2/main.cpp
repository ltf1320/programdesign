#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+10;
const int maxm=100000+100;
const int inf=0x3f3f3f3f;
int N,M;
int suml,sumc;

struct EDGE
{
    int to,next;
    int l,c;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;
void add(int f,int t,int l,int c)
{
    edge[ent].to=t;
    edge[ent].l=l;
    edge[ent].c=c;
    edge[ent].next=box[f];
    box[f]=ent++;
}


int low_dis[maxn];
int low_cos[maxn];
bool vis[maxn];
void prim()
{
    for(int i=1;i<=N;i++)
        low_cos[i]=low_dis[i]=inf;
    low_cos[1]=0;
    low_dis[1]=0;
    memset(vis,0,sizeof(vis));
    suml=sumc=0;
    int ndis,ncos,now,next;
    now=1;
    vis[1]=1;
    for(int i=1;i<N;i++)
    {
        ndis=ncos=inf;
        next=-1;
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(vis[edge[i].to]) continue;
            if(edge[i].l<low_dis[edge[i].to])
            {
                low_dis[edge[i].to]=edge[i].l;
                low_cos[edge[i].to]=edge[i].c;
            }
            if(edge[i].l==low_dis[edge[i].to]&&low_cos[edge[i].to]>edge[i].c)
                low_cos[edge[i].to]=edge[i].c;
        }
        for(int i=1;i<=N;i++)
        {
            if(vis[i]) continue;
            if(low_dis[i]<ndis)
            {
                ndis=low_dis[i];
                next=i;
                ncos=low_cos[i];
            }
            else if(low_cos[i]<ncos&&low_dis[i]==ndis)
            {
                next=i;
                ncos=low_cos[i];
            }
        }
        if(next==-1)
        {
            suml=sumc=-1;
            return;
        }
        vis[next]=1;
        suml+=ndis;
        sumc+=ncos;
        now=next;
    }
    for(int i=1;i<=N;i++)
        if(!vis[i])
        {
            suml=sumc=-1;
            return;
        }
}


void input()
{
    ent=0;
    memset(box,-1,sizeof(box));
    int f,t,l,c;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d%d",&f,&t,&l,&c);
        add(f,t,l,c);
        add(t,f,l,c);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        prim();
        printf("%d %d\n",suml,sumc);
    }
    return 0;
}
