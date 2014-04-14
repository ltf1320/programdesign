#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N,M,S,E,T;
int map[maxn][maxn];
int cost[maxn],sa[maxn];

void floyd()
{
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                if(map[i][k]+map[k][j]<map[i][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
}

struct EDGE
{
    int next,to;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int res,nres;
int nt;
bool vis[maxn];
void dfs(int now,int mins)
{
    if(now==E&&nt<=T)
    {
        res=max(res,nres);
    }
    if(map[now][E]+nt>T)
        return;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==E)
        {
            if(nt+map[now][E]<=T)
            {
                res=max(res,nres);
            }
        }
        if(!vis[edge[i].to]&&sa[edge[i].to]>mins)
        {
            vis[edge[i].to]=1;
            nt+=map[now][edge[i].to];
            nt+=cost[edge[i].to];
            nres+=sa[edge[i].to];
            dfs(edge[i].to,sa[edge[i].to]);
            nt-=map[now][edge[i].to];
            nt-=cost[edge[i].to];
            nres-=sa[edge[i].to];
            vis[edge[i].to]=0;
        }
    }
}

bool aded[maxn][maxn];

void createMap()
{
    for(int i=0;i<N;i++)
    {
        if(S!=i&&!aded[S][i])
        {
            aded[S][i]=1;
            add(S,i);
        }
        if(i!=E&&!aded[i][E])
        {
            aded[i][E]=1;
            add(i,E);
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(sa[i]<sa[j]&&!aded[i][j])
                add(i,j);
        }
}

void work()
{
    floyd();
    createMap();
    res=0;
    nres=0;
    nt=0;
    memset(vis,0,sizeof(vis));
    dfs(S,-1);
    nres=sa[S];
    nt=cost[S];
    vis[S]=1;
    dfs(S,sa[S]);
}

void input()
{
    int f,t,v;
    for(int i=0;i<N;i++)
        scanf("%d",&cost[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&sa[i]);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        map[f][t]=min(map[f][t],v);
        map[t][f]=min(map[t][f],v);
    }
}

void init()
{
    memset(aded,0,sizeof(aded));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            map[i][j]=inf;
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int _,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        cas++;
        scanf("%d%d%d%d%d",&N,&M,&T,&S,&E);
        init();
        input();
        work();
        printf("Case #%d:\n",cas);
        printf("%d\n",res);
    }
    return 0;
}
