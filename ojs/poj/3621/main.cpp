#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxp=5000+10;
const double inf=(double)1000*5000*1000;
const double err=1E-4;
int L,P;
int fs[maxn];
struct EDGE
{
    int next,to;
    int t;
    double v;
};
EDGE edge[maxp];
int box[maxn];
int ent;

void add(int f,int to,int t)
{
    edge[ent].to=to;
    edge[ent].t=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

bool in[maxn];
double dis[maxn];
int cnt[maxn];
queue<int> que;
bool spfa(int s)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<=L;i++)
        dis[i]=inf;
    memset(cnt,0,sizeof(cnt));
    que.push(1);
    in[1]=1;
    cnt[1]++;
    dis[1]=0;
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>L)
                    {
                        while(!que.empty()) que.pop();
                        return true;
                    }
                }
            }
        }
        in[now]=0;
    }
    return false;
}

void input()
{
    int f,to,t;
    for(int i=1;i<=L;i++)
        scanf("%d",&fs[i]);
    for(int i=0;i<P;i++)
    {
        scanf("%d%d%d",&f,&to,&t);
        add(f,to,t);
    }
}

void work()
{
    double l=0,r=1000;
    double m;
    while(r-l>err)
    {
        m=(l+r)/2;
        for(int i=0;i<ent;i++)
            edge[i].v=m*edge[i].t-fs[edge[i].to];
        if(spfa(m))
            l=m;
        else r=m;
    }
    printf("%.2f\n",l);
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&L,&P))
    {
        init();
        input();
        work();
    }
    return 0;
}
