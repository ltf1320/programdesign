#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=4*200+100;
const int maxm=maxn*maxn*4;
const LL inf=(LL)1000000000*maxn;//!
LL end;
int N,M;

LL dis[maxn][maxn];
int has[maxn],can[maxn];

void floyd()
{
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

struct EDGE
{
    int to,next;
    LL v;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void _add(int f,int t,LL v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,LL v)
{
    _add(f,t,v);
    _add(t,f,0);
}

void initMap()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

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
int makeflow(int s,int t,LL maxc)
{
    if(s==t) return maxc;
    LL rec=0,flow;
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

int dinic(int s,int t)
{
    int res=0;
    while(makelevel(s,t))
        res+=makeflow(s,t,inf);
    return res;
}

bool check(LL mdis)
{
    initMap();
    int sum=0;
    for(int i=0; i<N; i++)
    {
        add(0,i*2+2,has[i]);
        sum+=has[i];
        add(i*2+1+2,1,can[i]);
        add(i*2+2,i*2+1+2,inf); //!
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==j) continue;
            if(dis[i][j]<=mdis)
            {
                add(i*2+2,j*2+1+2,inf);
            }
        }
    if(dinic(0,1)==sum)
        return true;
    return false;
}


void work()
{
    floyd();
    end=0;
    for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(dis[i][j]<inf)
                    end=max(end,dis[i][j]);
    LL l=0,r=end;
    LL m;
    while(r>=l)
    {
        m=(l+r)/2;
        if(check(m))
            r=m-1;
        else l=m+1;
    }
    if(l>end)
        puts("-1");
    else
        printf("%I64d\n",l);
}

void input()
{
    int f,t;
    LL v;
    for(int i=0;i<N;i++)
        scanf("%d%d",&has[i],&can[i]);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%I64d",&f,&t,&v);
        f--;t--;
        dis[f][t]=dis[t][f]=min(dis[f][t],v);
    }
}

void init()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=inf+1;
}

int main()
{
   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
