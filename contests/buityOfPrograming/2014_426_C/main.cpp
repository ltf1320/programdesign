#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+100;
int w[maxn];
struct EDGE
{
    int next,to,c;
};
EDGE edge[maxn*10];
int box[maxn];
int ent;

void _add(int f,int t,int c)
{
    edge[ent].to=t;
    edge[ent].c=c;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int c)
{
    _add(f,t,c);
    _add(t,f,c);
}

LL maxdis;
int kfrom;
int dfs(int now,int from,LL dis)
{
    maxdis=min(w[kfrom],w[now])*dis;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=from)
        {
            dfs(edge[i].to,now,dis+edge[i].c);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&w[i]);
        for(int i=1;i<N;i++)
        {
            int f,t,c;
            scanf("%d%d%d",&f,&t,&c);
        }
    }
    return 0;
}
