#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int maxn=30;
const int maxm=maxn*maxn;
const int inf=0x3f3f3f3f;
int M,D;

map<string,int> mp;
int mpn;

struct ED
{
    int from,to;
    int v;
    bool operator<(const ED &a)const
    {
        return v<a.v;
    }
};
ED eds[maxm];

struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxm];
bool can[maxm];
int box[maxn];
int ent;

void del(int ed)
{
    can[ed]=0;
}

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    can[ent]=1;
    box[f]=ent++;
}

int fa[maxn];

int find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(b<a)
            fa[a]=b;
        else fa[b]=a;
    }
}

int mdis[maxn];
int kdis[maxn];
int mn[maxn];
bool vis[maxn];

int kruskal()
{
    int a,b;
    sort(eds,eds+M);
    int res=0;
    for(int i=0;i<M;i++)
    {
        if(eds[i].from==0||eds[i].to==0)
        {
            if(eds[i].from)
            {
                mdis[eds[i].from]=eds[i].v;
                mn[eds[i].from]=eds[i].from;
            }
            else
            {
                mdis[eds[i].to]=eds[i].v;
                mn[eds[i].to]=eds[i].to;
            }
            continue;
        }
        a=find(eds[i].from);
        b=find(eds[i].to);
        if(a!=b)
        {
            add(eds[i].from,eds[i].to,eds[i].v);
            add(eds[i].to,eds[i].from,eds[i].v);
            Uni(a,b);
            res+=eds[i].v;
        }
    }
    return res;
}
int maxf,med;
void dfs(int now,int fa,int mx)
{
    if(edge[mx].v-mdis[now]>maxf)
    {
        maxf=edge[mx].v-mdis[now];
        med=mx;
    }
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if((i^fa)==1) continue;
        if(!can[i]) continue;
        dfs(edge[i].to,i,edge[mx].v>edge[i].v?mx:i);
    }
}


void work()
{
    for(int i=0;i<mpn;i++)
        mdis[i]=inf;
    int res=kruskal();
    int fa;
    int ndu=0;
    for(int i=1;i<mpn;i++)
    {
        fa=find(i);
        kdis[i]=mdis[i];
        if(kdis[fa]>mdis[i])
        {
            kdis[fa]=kdis[i];
            mn[fa]=i;
        }
    }
    for(int i=1;i<mpn;i++)
    {
        fa=find(i);
        if(!vis[fa])
        {
            add(0,mn[fa],kdis[fa]);
            add(mn[fa],0,kdis[fa]);
            ndu++;
            res+=kdis[fa];
            vis[fa]=1;
        }
    }
    for(int i=ndu;i<D;i++)
    {
        maxf=0;
        for(int j=box[0];j!=-1;j=edge[j].next)
        {
            dfs(edge[j].to,j,j);
        }
        if(maxf>0)
        {
            del(med);
            del(med^1);
            mdis[edge[med].to]=inf;
            res-=maxf;
        }
        else break;
    }
    printf("Total miles driven: %d\n",res);
}

void input()
{
    string a,b;
    mp.insert(make_pair(string("Park"),mpn++));
    for(int i=0;i<M;i++)
    {
        cin>>a>>b>>eds[i].v;
        if(!mp.count(a))
            mp.insert(make_pair(a,mpn++));
        if(!mp.count(b))
            mp.insert(make_pair(b,mpn++));
        eds[i].from=mp[a];
        eds[i].to=mp[b];
    }
    scanf("%d",&D);
}

void init()
{
    mp.clear();
    memset(box,-1,sizeof(box));
    ent=0;
    for(int i=0;i<22;i++)
        fa[i]=i;
    memset(vis,0,sizeof(vis));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
