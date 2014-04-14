#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define p2(x) ((x)*(x))

using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int N;

struct Point
{
    int x,y,p;
};
Point pts[maxn];
double getDis(const Point &a,const Point &b)
{
    return sqrt(1.0*p2(a.x-b.x)+p2(a.y-b.y));
}

struct EDGE
{
    int next,to;
    double v;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;

void add(int f,int t,double v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

//bool used[maxn][maxn];
double map[maxn][maxn];

double low_dis[maxn];
int from[maxn];
bool vis[maxn];
double prim()
{
    for(int i=0;i<N;i++)
        low_dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    double res=0;
    int now=0;
    int l;
    double ndis;
    for(int k=1;k<N;k++)
    {
        ndis=inf;
        for(int i=1;i<N;i++)
        {
            if(i==now) continue;
            if(!vis[i]&&map[now][i]<low_dis[i])
            {
                low_dis[i]=map[now][i];
                from[i]=now;
            }
            if(!vis[i]&&ndis>low_dis[i])
            {
                ndis=low_dis[i];
                l=i;
            }
        }
 //       used[from[l]][l]=used[l][from[l]]=1;
        add(from[l],l,ndis);
        add(l,from[l],ndis);
        vis[l]=1;
        now=l;
        res+=ndis;
    }
    return res;
}

double dp[maxn][maxn];

void dfs(int start,int now,double mx,int fa)
{
    dp[start][now]=mx;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==fa) continue;
        dfs(start,edge[i].to,max(mx,edge[i].v),now);
    }
}


void work()
{
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            map[i][j]=map[j][i]=getDis(pts[i],pts[j]);
        }
    double len=prim();
    for(int i=0;i<N;i++)
        dfs(i,i,0,-1);
    double res=0,nres;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            nres=(pts[i].p+pts[j].p)/(len-dp[i][j]);
            res=max(res,nres);
        }
    printf("%.2f\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&pts[i].x,&pts[i].y,&pts[i].p);
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
        input();
        work();
    }
    return 0;
}
