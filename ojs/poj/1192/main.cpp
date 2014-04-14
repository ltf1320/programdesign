#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}


struct Node
{
    int x,y,v;
};
Node nds[maxn];

int abs(int a)
{
    return a>0?a:-a;
}
bool vis[maxn];
int dfs(int now)
{
    vis[now]=1;
    int res=nds[now].v;
    int tmp;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(!vis[edge[i].to])
        {
            tmp=dfs(edge[i].to);
            if(tmp>0) res+=tmp;
        }
    }
    if(res>0) return res;
    else return 0;
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d%d%d",&nds[i].x,&nds[i].y,&nds[i].v);
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
            if(abs(nds[i].x-nds[j].x)+abs(nds[i].y-nds[j].y)==1)
            {
                add(i,j);
                add(j,i);
            }
    int res=0,tmp;
    for(int i=0;i<N;i++)
    {
        memset(vis,0,sizeof(vis));
        tmp=dfs(i);
        if(tmp>res  )
            res=tmp;
    }
    printf("%d\n",res);
    return 0;
}
