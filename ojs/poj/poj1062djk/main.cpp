#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=120;
const int inf=0x7fffffff;

int m,n;
int maxLever;
bool exlev[maxn];
int levs[maxn];

int map[maxn][maxn];
int ctn;
void add(int from,int to,int vv)
{
    map[from][to]=vv;
}

bool vis[maxn];
int dis[maxn];

struct FSO
{
    int from,dis;
    FSO(int f,int d)
    {
        from=f;
        dis=d;
    }
    bool operator<(const FSO &a) const
    {
        return dis>a.dis;
    }
};

void dijkstra(int start)
{
    for(int i=0; i<=n; i++)
        dis[i]=inf;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        if(levs[i]>maxLever || levs[i]<maxLever-m)
            vis[i]=1;
    }
    priority_queue<FSO> que;
    que.push(FSO(start,0));
    dis[start]=0;
    int mx;
    while(!que.empty())
    {
        mx=que.top().from;
        if(vis[mx])
        {
            que.pop();
            continue;
        }
        que.pop();
        for(int i=0; i<=n; i++)
        {
            if(map[mx][i]&&dis[i]>dis[mx]+map[mx][i])
            {
                dis[i]=dis[mx]+map[mx][i];
                que.push(FSO(i,dis[i]));
            }
        }
        vis[mx]=1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(exlev,0,sizeof(exlev));
    memset(map,0,sizeof(map));
    ctn=0;
    scanf("%d%d",&m,&n);
    int P,L,X;
    int t,yh;
    int maxlever=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&P,&L,&X);
        if(L>maxlever) maxlever=L;
        levs[i]=L;
        exlev[L]=1;
        add(0,i,P);
        for(int j=0; j<X; j++)
        {
            scanf("%d%d",&t,&yh);
            add(t,i,yh);
        }
    }
    int res=inf;
    for(int i=0; i<=maxlever; i++)
    {
        if(exlev[i])
        {
            maxLever=i;
            dijkstra(0);
            if(dis[1]<res) res=dis[1];
        }
    }
    printf("%d\n",res);
    return 0;
}
