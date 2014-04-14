#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2000+10;
const int maxm=20000*2+100;

int N,M;

struct EDGE
{
    int next,to;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

bool chose[maxm];

int in[maxn];
int nextedge[maxn];
int time;

void dfs(int now)
{
    int ce=-1,mintime=inf;
    in[now]=time++;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if((i/2<N-1))
        {
            if(!in[edge[i].to])
            {
                nextedge[now]=i;
                dfs(edge[i].to);
            }
        }
        else if(in[edge[i].to])
        {
            if(in[edge[i].to]<mintime)
            {
                mintime=in[edge[i].to];
                ce=nextedge[edge[i].to];
            }
        }
    }
    int t;
    if(ce!=-1)
    {
        t=ce;
        while(edge[t].to!=now)
        {
            if(chose[t/2])
            {
                t=-1;break;
            }
            t=nextedge[edge[t].to];
        }
        if(t!=-1)
            chose[ce/2]=1;
    }
    in[now]=0;
    time--;
}

void work()
{
    dfs(1);
    int res=0;
    for(int i=0;i<N-1;i++)
    {
        if(chose[i]) res++;
    }
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(chose,0,sizeof(chose));
    time=1;
    memset(in,0,sizeof(in));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        init();
        input();
        work();
    }
    return 0;
}
