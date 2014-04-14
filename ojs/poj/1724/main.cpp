#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=10000+100;
const int inf=0x3f3f3f3f;
int K,N,R;

struct EDGE
{
    int from,to,next,front,v,c;
};
EDGE edge[maxm];
int box[maxn];
int rebox[maxn];
int ent;
void add(int f,int t,int v,int c)
{
    edge[ent].from=f;
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].c=c;
    edge[ent].next=box[f];
    edge[ent].front=rebox[t];
    box[f]=ent;
    rebox[t]=ent++;
}

struct FSO
{
    int n,dis;
    FSO(int nn,int d):n(nn),dis(d){}
    bool operator<(const FSO&a)const
    {
        return dis>a.dis;
    }
};

priority_queue<FSO> que;
int dis[maxn];
bool vis[maxn];
void dijkstra()
{
    for(int i=0;i<=N;i++) dis[i]=inf;
    int now,ndis;
    que.push(FSO(N,0));
    dis[N]=0;
    while(!que.empty())
    {
        now=que.top().n;
        if(vis[now])
        {
            que.pop();
            continue;
        }
        ndis=que.top().dis;
        que.pop();
        for(int i=rebox[now];i!=-1;i=edge[i].front)
        {
            if(vis[edge[i].from]) continue;
            if(dis[edge[i].from]>dis[now]+edge[i].v)
            {
                dis[edge[i].from]=dis[now]+edge[i].v;
                que.push(FSO(edge[i].from,ndis+edge[i].v));
            }
        }
        vis[now]=1;
    }
}

struct FAO
{
    int n,dis,f,c;
    FAO(int nn,int d,int ff,int cc):n(nn),dis(d),f(ff),c(cc){}
    bool operator<(const FAO&a)const
    {
        return f>a.f;
    }
};
priority_queue<FAO> aque;
int A_star()
{
    int now,ndis,nc;
    int res=inf;
    aque.push(FAO(1,0,dis[1],K));
    while(!aque.empty())
    {
        now=aque.top().n;
        ndis=aque.top().dis;
        nc=aque.top().c;
        aque.pop();
        if(res<ndis) continue;
        if(nc<0) continue;
        if(now==N)
        {
            res=ndis;
            return res;
        }
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            aque.push(FAO(edge[i].to,ndis+edge[i].v,ndis+edge[i].v+dis[edge[i].to],nc-edge[i].c));
        }
    }
    return -1;
}

void input()
{
    int s,d,l,t;
    for(int i=0;i<R;i++)
    {
        scanf("%d%d%d%d",&s,&d,&l,&t);
        add(s,d,l,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    memset(rebox,-1,sizeof(rebox));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&K,&N,&R);
    init();
    input();
    dijkstra();
    printf("%d\n",A_star());
    return 0;
}
