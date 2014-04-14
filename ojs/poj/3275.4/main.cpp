#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxm=20000;
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


int map[maxn][maxn];

int res=0;
bool vis[maxn];
int dfs(int now)
{
    vis[now]=1;
    int ans=0;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(!vis[edge[i].to])
            ans+=dfs(edge[i].to)+1;
    }
    return ans;
}


void work()
{
    for(int i=1; i<=N; i++)
    {
        memset(vis,0,sizeof(vis));
        res+=dfs(i);
    }
    res=N*(N-1)/2-res;
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        map[f][t]=1;
        add(f,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    init();
    input();
    work();
    return 0;
}
