#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=510;
const int Inf=0x3f3f3f3f;

int s,p;
double dis[maxn][maxn];
double dp[maxn];
bool vis[maxn];

struct Point
{
    int x,y;
};
Point pnt[maxn];

void add(int a,int b)
{
    dis[a][b]=dis[b][a]=sqrt(0.0+(pnt[a].x-pnt[b].x)*(pnt[a].x-pnt[b].x)+(pnt[a].y-pnt[b].y)*(pnt[a].y-pnt[b].y));
}

struct FSO   //原来的版本没有dis,直接用dp[p]来判断，这导致队列不能有效更新
{
    int p,dis;
    FSO(int p_,int dis_):p(p_),dis(dis_) {}
    bool operator<(const FSO &a)const
    {
        return dis>a.dis;
    }
};

void prim()
{
    int now;
    for(int i=0; i<p; ++i)
        dp[i]=Inf;
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
        for(int i=0; i<p; ++i)
        {
            if(i==now) continue;
            if(vis[i]) continue;
            if(dis[now][i]<dp[i])
            {
                dp[i]=dis[now][i];
                que.push(FSO(i,dp[i]));
            }
        }
        vis[now]=1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&s,&p);
        for(int i=0; i<p; ++i)
        {
            scanf("%d%d",&pnt[i].x,&pnt[i].y);
            for(int j=0; j<i; ++j)
                add(i,j);
        }
        prim();
        sort(dp,dp+p);
        printf("%.2f\n",dp[p-s-1]);
    }
    return 0;
}
