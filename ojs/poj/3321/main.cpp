#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
int N,M;
int num[maxn];
bool has[maxn];
int father[maxn];
bool changed[maxn];

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

int dfs(int now)
{
    int n=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to==father[now]) continue;
        father[edge[i].to]=now;
        n+=dfs(edge[i].to);
    }
    num[now]=n;
    return n;
}

void change(int des)
{
    int c,now;
    if(has[des]) c=-1;
    else c=1;
    has[des]^=1;
    for(now=des; now!=1; now=father[now])
    {
        if(changed[now]) break;
        changed[now]=1;
    }
    changed[1]=1;
}

int query(int now)
{
    if(!changed[now]) return num[now];
    int n=has[now]?1:0;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to==father[now]) continue;
        n+=query(edge[i].to);
    }
    num[now]=n;
    changed[now]=0;
    return n;
}

void init()
{
    memset(box,-1,sizeof(box));
    memset(changed,0,sizeof(changed));
    ent=0;
    for(int i=0;i<=N;i++)
        has[i]=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    int f,t;
    char ch;
    scanf("%d",&N);
    init();
    for(int i=1; i<N; i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
    father[1]=1;
    dfs(1);
    scanf("%d",&M);
    ch=getchar();
    for(int i=0; i<M; i++)
    {
        scanf("%c%d",&ch,&t);
        if(ch=='Q') printf("%d\n",query(t));
        else change(t);
        ch=getchar();
    }
    return 0;
}
