#include <iostream>
#include <cstdio>
#include<cstring>
#include <cstdlib>
using namespace std;
const int maxn=100000+1000;
const int PP=50001;
const int Inf=0x3f3f3f3f;
struct Node
{
    int to,next;
    void reset()
    {
        to=next=0;
    }
};
Node edge[maxn];
int box[maxn];

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
int dis[maxn];
int que[10*maxn];
bool vis[maxn];
int dijkstra(int from,int to)
{
    for(int i=0; i<maxn; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    dis[from]=0;
    int front=0,rear=1;
    while(front<rear)
    {
        if(vis[from])
        {
            front++;
            continue;
        }
        for(int i=box[from]; i; i=edge[i].next)
        {
            if(vis[from]==0 && dis[edge[i].to]>dis[from]+1)
                dis[edge[i].to]=dis[from]+1;
            if(vis[edge[i].to]==0) que[rear++]=edge[i].to;
        }
        front++;
        vis[from]=1;
        from=que[front];
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
//    int need;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        if(!n && !m && !q) break;
        inti();
        ent=1;
//        need=0;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
//            if(a==1||b==1) need=1;
        }
        for(int i=0; i<q; ++i)
        {
            scanf("%d",&a);
//            if(a==1) need=-1;
            add(PP,a);
        }

//        if(need==0) res=-1;
//        else if(need==-1) res=1;
//        else res=dijkstra(PP,1);
        res=dijkstra(PP,1);
        if(res==-1) printf("Emmm..\n");
        else printf("%d\n",res-1);
    }
    return 0;
}
