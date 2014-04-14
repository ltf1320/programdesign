#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int maxm=1000+10;
double err=1E-7;
double inf=1E9;
double l,r;
int N,M;
struct EDGE
{
    int to,next;
    double v;
};
EDGE edge[maxm*2];
int box[maxn];
int ent;
void add(int f,int  t,double v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct Cable
{
    int f,t,v;
};
Cable cbs[maxm];

int level[maxn];
bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    level[s]=1;
    queue<int> que;
    que.push(s);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(edge[i].v==0) continue;
            if(level[edge[i].to]) continue;
            level[edge[i].to]=level[now]+1;
            que.push(edge[i].to);
            if(edge[i].to==t) return 1;
        }
    }
    return false;
}


int que[maxn*10];

double makeflow(int s,int t,double maxc)
{
    if(s==t) return maxc;
    double rec=0,flow;
    for(int i=box[s];i!=-1;i=edge[i].next)
    {
        if(!edge[i].v)continue;
        if(level[edge[i].to]<=level[s]) continue;
        flow=makeflow(edge[i].to,t,min(edge[i].v,maxc-rec));
        edge[i].v-=flow;
        edge[i^1].v+=flow;
        rec+=flow;
        if(rec==maxc) return maxc;
    }
    return rec;
}

double dinic(int s,int t)
{
    double res=0;
    while(makelevel(s,t))
        res+=makeflow(s,t,inf);
    return res;
}



double judge(double m)
{
    ent=0;
    memset(box,-1,sizeof(box));
    double ans=0;
    for(int i=0;i<M;i++)
    {
        if(cbs[i].v-m>0)
        {
            add(cbs[i].f,cbs[i].t,cbs[i].v-m);
            add(cbs[i].t,cbs[i].f,cbs[i].v-m);
        }
        else ans+=cbs[i].v-m;
    }
    return ans+dinic(1,N);
}
int rst[maxm];
int rstn;
int bel[maxm];
void dfs(int s)
{
    bel[s]=1;
    for(int i=box[s];i!=-1;i=edge[i].next)
        if(!bel[edge[i].to]&&edge[i].v)
            dfs(edge[i].to);
}

void work()
{
    double m;
    while(r-l>err)
    {
        m=(l+r)/2;
        if(judge(m)<0)
            r=m;
        else l=m;
    }
    judge(l);
    memset(bel,0,sizeof(bel));
    dfs(1);
    rstn=0;
    for(int i=0;i<M;i++)
    {
        if(bel[cbs[i].f]!=bel[cbs[i].t])
            rst[rstn++]=i+1;
        else if(cbs[i].v-l<=0)
            rst[rstn++]=i+1;
    }
    printf("%d\n",rstn);
    for(int i=0;i<rstn-1;i++)
        printf("%d ",rst[i]);
    if(rstn) printf("%d\n",rst[rstn-1]);
}

void input()
{
    l=inf,r=0;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&cbs[i].f,&cbs[i].t,&cbs[i].v);
        l=min(l,1.0*cbs[i].v);
        r=max(r,1.0*cbs[i].v);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    bool start=0;
    while(~scanf("%d%d",&N,&M))
    {
        if(start) putchar('\n');
        start=1;
        input();
        work();
    }
    return 0;
}
