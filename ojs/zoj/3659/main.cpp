#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn= 200000+100;
const int inf=0x3f3f3f3f;
int N;

struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void add(int from,int to ,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

int Res;
int res;
bool vis[maxn];



int dfs(int sv,int maxp,int from)
{

}

void init()
{
    memset(box,-1,sizeof(box));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<maxn;i++)
    {
        du[i].i=i;
        du[i].cap=0;
    }
    ent=0;
    Res=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int f,t,v;
    while(~scanf("%d",&N))
    {
        init();
        for(int i=0; i<N-1; i++)
        {
            scanf("%d%d%d",&f,&t,&v);
            add(f,t,v);
            add(t,f,v);
        }
        dfs(maxi);
        printf("%d\n",Res);
    }
    return 0;
}
