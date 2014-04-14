#include <iostream>
#include <cstdio>
#include<cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn=100000+1000;
const int maxn2=50000+200;
const int PP=50001;
const int Inf=maxn;
int t=static_cast<double>(clock())/CLOCKS_PER_SEC;
struct Node
{
    int to,next;
    void reset()
    {
        to=next=0;
    }
};
Node edge[maxn];

int box[maxn2];

void inti()
{
    for(int i=0; i<maxn; i++)
        edge[i].reset();
}
int ent;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}
int dis[maxn2];
bool vis[maxn2];
int dijkstra(const int &n,int from,int to)
{
    for(int i=0; i<maxn2; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    dis[from]=0;
    int mx,mdis;
    for(int j=box[from]; j; j=edge[j].next)
    {
        dis[edge[j].to]=1;
    }
    for(int i=1; i<=n; ++i)
    {
        mdis=Inf;
        for(int j=1; j<=n; ++j)
            if(vis[j]==0 && dis[j]<mdis)
            {
                mdis=dis[j];
                mx=j;
            }
        for(int j=box[mx]; j; j=edge[j].next)
        {
            if(dis[edge[j].to]>dis[mx]+1)
                dis[edge[j].to]=dis[mx]+1;
        }
        vis[mx]=1;
    }
    if(dis[to]!=Inf)
        return dis[to];
    else return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n,m,q;
    int a,b,res;
    int need;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        if(!n && !m && !q) break;
        inti();
        ent=1;
        need=0;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            if(a==1||b==1) need=1;
        }
        for(int i=0; i<q; ++i)
        {
            scanf("%d",&a);
            if(a==1) need=-1;
            add(PP,a);
        }
        if(need==0) res=-1;
        else if(need==-1) res=1;
        else res=dijkstra(n,PP,1);
//        res=dijkstra(n,PP,1);
        if(res==-1) printf("Emmm..\n");
        else printf("%d\n",res-1);
    }
    return 0;
}
