#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=10+10;
const int maxm=100+10;
const int inf=0x3f3f3f3f;
int N,M;
int res;
struct EDGE
{
    int to,next,r;
};
EDGE edge[maxm];
int box[maxn];
struct CP
{
    int f,t,p;
    CP(int ff,int tt,int pp):f(ff),t(tt),p(pp) {}
    CP() {}
};
CP canp[maxn][maxm];
int cpn[maxn];
int ent;
void add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].r=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}
void add(int a,int b,int c,int p,int r)
{
    edge[ent].to=b;
    edge[ent].r=r;
    edge[ent].next=box[a];
    box[a]=ent;
    canp[c][cpn[c]++]=CP(a,b,p);
    ent++;
}

//int cnt[maxn];
bool in[maxn];
int dis[maxn];
int vis[maxn];
queue<int> que;

int spfa()
{
//    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    for(int i=0;i<=N;i++) dis[i]=inf;
    int now;
    que.push(1);
    dis[1]=0;
    in[1]=1;
    vis[1]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(!vis[now])
        {
            for(int i=0;i<cpn[now];i++)
                add(canp[now][i].f,canp[now][i].t,canp[now][i].p);
        }
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].r)
            {
                dis[edge[i].to]=dis[now]+edge[i].r;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
        }
        in[now]=0;
    }
    return dis[N];
}

void input()
{
    int a,b,c,p,r;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
        add(a,b,c,p,r);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    memset(cpn,0,sizeof(cpn));
    res=inf;
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        res=spfa();
        if(res!=inf) printf("%d\n",res);
        else printf("impossible\n");
    }
    return 0;
}
