#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int N,K;

struct Lsh
{
    int num,fcode;
    bool operator<(const Lsh& a)const
    {
        return num<a.num;
    }
};
Lsh lsh[maxn];
int mp[100000+100];
int mpn;

struct EDGE
{
    int to,next,cap,cost,from;
};
EDGE edge[maxn*4];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].cap=cap;
    edge[ent].cost=cost;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap,int cost)
{
    _add(f,t,cap,cost);
    _add(t,f,0,-cost);
}

int dis[maxn];
bool in[maxn];
queue<int> que;
int from[maxn];
bool spfa(int f,int t)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<=mpn;i++)
        dis[i]=inf;
    memset(from,-1,sizeof(from));
    int now;
    que.push(f);
    dis[f]=0;
    in[f]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(edge[i].cap&&dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                dis[edge[i].to]=dis[now]+edge[i].cost;
                from[edge[i].to]=i;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return 0;
    else return 1;
}

int fyl(int s,int t)
{
    int cost=0;
    int mincap;
    while(spfa(s,t))
    {
        mincap=inf;
        for(int i=from[t];i!=-1;i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[t];i!=-1;i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[t]*mincap;
    }
    return cost;
}

void input()
{
    int f,t,c;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&f,&t,&c);
        if(mp[f]==-1)
        {
            mp[f]=mpn;
            lsh[mpn].num=f;
            lsh[mpn].fcode=mpn++;
        }
        if(mp[t]==-1)
        {
            mp[t]=mpn;
            lsh[mpn].num=t;
            lsh[mpn].fcode=mpn++;
        }
        add(mp[f],mp[t],1,-c);
    }
    sort(lsh,lsh+mpn);
    for(int i=0;i<mpn-1;i++)
        add(lsh[i].fcode,lsh[i+1].fcode,K,0);
}

void init()
{
    lsh[0].fcode=0;
    lsh[0].num=-inf;
    mpn=1;
    memset(box,-1,sizeof(box));
    memset(mp,-1,sizeof(mp));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        printf("%d\n",-fyl(0,lsh[mpn-1].fcode));
    }
    return 0;
}
