#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=200+10;
const int maxm=4000+100;

struct EDGE
{
    int next,to;
};
EDGE edge[2*maxm];
bool used[maxm];
bool select[maxm];
int box[maxn];
int ent;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}

int fa[maxn];
int N,M;

int find(int n)
{
    if(fa[n]!=n)
    {
        fa[n]=find(fa[n]);
    }
    return fa[n];
}

void uni(int a,int b)
{
    int Fa=find(a),Fb=find(b);
    if(Fa!=Fb)
    {
        fa[Fa]=Fb;
    }
}

bool kruscal()
{
    for(int i=0;i<M;i++)
    {
        if(find(edge[2*i].to)!=find(edge[2*i+1].to))
        {
            uni(edge[2*i].to,edge[2*i+1].to);
            used[i]=1;
        }
        if(find(1)==find(2)&&find(1)==find(N)) return 1;
    }
    return 0;
}

bool dfs(int now,int from)
{
    bool rev=0;
    int ed;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(!used[i/2]) continue;
        select[i/2]=1;
        if(edge[i].to!=from)
        {
            rev|=dfs(edge[i].to,now);
        }
        else ed=i;
    }
    if(now==2||now==N) return 1;
    if(!rev)
    {
        used[ed/2]=0;
        select[ed/2]=0;
        return 0;
    }
    return 1;
}

void init()
{
    ent=0;
    memset(used,0,sizeof(used));
    memset(box,-1,sizeof(box));
    memset(select,0,sizeof(select));
    for(int i=0;i<=N;i++)
        fa[i]=i;
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

void print()
{
    int i=M-1;
    for(;i>=0;i--)
        if(select[i]) break;
    for(;i>=0;i--)
        if(select[i]) printf("1");
        else printf("0");
    putchar('\n');
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        if(kruscal())
        {
            dfs(1,1);
            print();
        }
        else printf("%d\n",-1);
    }
}
