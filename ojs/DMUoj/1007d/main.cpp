/*
50000 5 2
10 6
23 7
6 7
7 1
7 6
23 10
0 0 0
*/


#include <iostream>
#include <cstdio>
#include<cstring>
#include <queue>
using namespace std;
const int maxn=100000+1000;
const int maxn2=50000+200;
const int PP=50001;
const int Inf=maxn;

int dis[maxn2];
bool vis[maxn2];
int box[maxn2];

struct Node
{
    int to,next;
    void reset()
    {
        to=next=0;
    }
};
Node edge[maxn];

struct FSO
{
    int from,dis;
    FSO(int from_,int dis_):from(from_),dis(dis_) {}
    bool operator<(const FSO &n)const {return dis>n.dis;}
};


void inti()
{
    for(int i=0; i<maxn; i++)
        edge[i].reset();
    edge[PP].reset();
    memset(box,0,sizeof(box));
}
int ent;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}
int dijkstra(const int &n,int from,int to)
{
    for(int i=0; i<maxn2; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    priority_queue<FSO> que;
    que.push(FSO(from,0));
    dis[from]=0;
    int mx,now;
    while(1)
    {
        if(que.empty()) break;
        mx=que.top().from;
        if(vis[mx])
        {
            que.pop();
            continue;
        }
        que.pop();
        for(int j=box[mx]; j; j=edge[j].next)
        {
            now=edge[j].to;
            if(dis[now]>dis[mx]+1)
            {
                dis[now]=dis[mx]+1;
                que.push(FSO(edge[j].to,dis[now]));
            }
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
//    freopen("out.txt","w",stdout);
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
