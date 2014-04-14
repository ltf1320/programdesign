#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn=200+20;
const int inf=0x3f3f3f3f;
float map[maxn][maxn];

float dis[maxn];
bool vis[maxn];

int n;


struct Point
{
    int x,y;
};
Point pnt[maxn];

float getDis(Point &a,Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

struct FSO
{
    int from,dis;
    FSO(int f,int d){from=f;dis=d;}
    bool operator<(const FSO& a) const
    {
        return dis>a.dis;
    }
};

float dijkstra()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++) dis[i]=inf;
    dis[1]=0;
    priority_queue<FSO> que;
    que.push(FSO(1,0));
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
        for(int i=1;i<=n;i++)
        {
            if(i==mx) continue;
            if(dis[i]>max(dis[mx],map[mx][i]))
            {
                dis[i]=max(dis[mx],map[mx][i]);
                que.push(FSO(i,dis[i]));
            }
        }
        vis[mx]=1;
    }
    return dis[2];
}



int main()
{
    freopen("in.txt","r",stdin);
    int x,y;
    int cas=0;
    while(~scanf("%d",&n))
    {
        cas++;
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            pnt[i].x=x;
            pnt[i].y=y;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=map[j][i]=getDis(pnt[i],pnt[j]);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",cas,dijkstra());
    }
    return 0;
}
