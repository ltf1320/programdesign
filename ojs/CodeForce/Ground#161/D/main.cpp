#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;

struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int N,M,K;
int fa[maxn];
int num[maxn];
int ent;
void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int find(int a)
{
    int now=a;
    while(fa[now]!=now)
    {
        now=fa[now];
    }
    fa[a]=now;
    num[a]++;
    return now;
}

void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(num[a]<num[b])
    {
        fa[a]=b;
        num[b]+=num[a];
    }
    else
    {
        fa[b]=a;
        num[a]+=num[b];
    }
}
bool vis[maxn];
void dfs(int now)
{
    vis[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(!vis[edge[i].to])
        {
            printf(" %d",edge[i].to);
            dfs(edge[i].to);
            break;
        }
    }
}

void init()
{
    for(int i=0;i<=N;i++) fa[i]=i;
    memset(box,-1,sizeof(box));
}

int main()
{
    int a,b;
    int f;
    init();
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
        Uni(a,b);
    }
    for(int i=1;i<=N;i++)
        if(num[i]>=K)
        {
            f=i;
            break;
        }
    printf("%d",f);
    dfs(f);
    putchar('\n');
    return 0;
}
