#include <iostream>
#include <cstdio>
#include<cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn=100000+1000;
const int maxn2=50000+1000;
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
int box[maxn2];

struct FSO
{
    int to,dis;
    FSO(const int &to_,const int &dis_):to(to_),dis(dis_){}
    bool operator<(const FSO &a)const {return dis<a.dis;}
};

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
int dijkstra(int from,int to)
{
    priority_queue<FSO> que;
    for(int i=0; i<maxn2; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    dis[from]=0;
    que.push(FSO(from,0));
    while(1)
    {
        from=que.top().to;
        if(que.empty())  break;
        que.pop();
        if(vis[from])
        {
            from=que.top().to;
            if(que.empty())  break;
            que.pop();
            continue;
        }
        for(int i=box[from]; i; i=edge[i].next)
        {
            if(vis[from]==0 && dis[edge[i].to]>dis[from]+1)
                dis[edge[i].to]=dis[from]+1;
            if(vis[edge[i].to]==0)
                que.push(FSO(edge[i].to,dis[edge[i].to]));
        }
        vis[from]=1;
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
        else res=dijkstra(PP,1);
        if(res==-1) printf("Emmm..\n");
        else printf("%d\n",res-1);
    }
    return 0;
}
