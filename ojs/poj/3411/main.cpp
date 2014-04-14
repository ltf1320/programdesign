#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int maxn=100+10;
const int maxm=100+10;
const int inf=0x3f3f3f3f;
int N,M;
struct EDGE
{
    int to,next,r;
};
EDGE edge[maxm];
int box[maxn];

struct CP
{
    int edge,p;
    CP(int e,int pp):edge(e),p(pp) {}
    CP() {}
};
CP canp[maxn][maxm];
int cpn[maxn];

bool payed[maxm];
int vis[maxm];
int ent;
void add(int a,int b,int c,int p,int r)
{
    edge[ent].to=b;
    edge[ent].r=r;
    edge[ent].next=box[a];
    box[a]=ent;
    canp[c][cpn[c]++]=CP(ent,p);
    ent++;
}

int res;

void dfs(int now,int pay)
{
    if(pay>=res) return;
    if(now==N)
    {
        res=pay;
        return;
    }
    for(int j=0; j<cpn[now]; j++)
    {
        if(!payed[canp[now][j].edge])
        {
            payed[canp[now][j].edge]=1;
            dfs(now,pay+canp[now][j].p);
            payed[canp[now][j].edge]=0;
        }
    }
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(vis[i]>3) continue;
        vis[i]++;
        if(payed[i])
            dfs(edge[i].to,pay);
        else
        {
            payed[i]=1;
            dfs(edge[i].to,pay+edge[i].r);
            payed[i]=0;
        }
        vis[i]--;
    }
}

void init()
{

    memset(box,-1,sizeof(box));
    memset(payed,0,sizeof(payed));
    memset(vis,0,sizeof(vis));
    memset(cpn,0,sizeof(cpn));

//    for(int i=0;i<maxn;i++){box[i]=-1;cpn[i]=0;}
//    for(int i=0;i<maxm;i++){vis[i]=0;payed[i]=0;}
    res=inf;
    ent=0;
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

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        vis[1]=1;
        dfs(1,0);
        if(res!=inf)
            printf("%d\n",res);
        else printf("impossible\n");
    }
    return 0;
}
