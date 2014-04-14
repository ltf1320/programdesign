#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=300;
const int inf=0x3f3f3f3f;
int N,cas;
struct Point
{
    int x,y;
}pts[maxn];
double getDis(Point &a,Point &b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dis[maxn][maxn];
double dp[maxn];
bool vis[maxn];
int from[maxn];

struct FSO
{
    int p;
    double dis;
    FSO(int p_,double dis_):p(p_),dis(dis_) {}
    bool operator<(const FSO &a)const
    {
        return dis>a.dis;
    }
};

void prim()
{
    int now;
    for(int i=0; i<N; ++i)
        dp[i]=inf;
    memset(vis,0,sizeof(vis));
    priority_queue<FSO> que;
    que.push(FSO(0,0));
    while(1)
    {
        if(que.empty()) break;
        now=que.top().p;
        if(vis[now])
        {
            que.pop();
            continue;
        }
        que.pop();
        for(int i=0; i<N; ++i)
        {
            if(i==now) continue;
            if(vis[i]) continue;
            if(dis[now][i]<dp[i])
            {
                dp[i]=dis[now][i];
                from[i]=now;
                que.push(FSO(i,dp[i]));
            }
        }
        vis[now]=1;
    }
}

void work()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=getDis(pts[i],pts[j]);
    prim();
    int now=1;
    double mx=0;
    while(now)
    {
        mx=max(dp[now],mx);
        now=from[now];
    }
    printf("Scenario #%d\n",cas);
    printf("Frog Distance = %.3f\n",mx);
    puts("");
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&pts[i].x,&pts[i].y);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        cas++;
        input();
        work();
    }
    return 0;
}
