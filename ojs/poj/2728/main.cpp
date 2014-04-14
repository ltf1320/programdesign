#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1000+10;
const double inf=10000*100000;
const double err=1E-7;
const double resErr=0.0001;
int N;
struct Node
{
    int x,y,h;
};
Node nds[maxn];

double cost[maxn][maxn];
double kdis[maxn][maxn];
double dis[maxn][maxn];
double dp[maxn];
bool vis[maxn];
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

double prim()
{
    int now;
    double res=0;
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
        res+=que.top().dis;
        que.pop();
        for(int i=0; i<N; ++i)
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
    return res;
}


double work()
{
    double l=0,r=10000000,m;
    double res;
    while(r-l>resErr)
    {
        m=(l+r)/2;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                dis[i][j]=dis[j][i]=cost[i][j]-m*kdis[i][j];
        res=prim();
        if(res<0)
            r=m;
        else l=m;
    }
    return l;
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&nds[i].x,&nds[i].y,&nds[i].h);
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            kdis[i][j]=kdis[j][i]=sqrt((nds[i].x-nds[j].x)*(nds[i].x-nds[j].x)+(nds[i].y-nds[j].y)*(nds[i].y-nds[j].y));
            cost[i][j]=cost[j][i]=abs(1.0*nds[i].h-nds[j].h);
        }
}



int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        input();
        printf("%.3f\n",work());
    }
    return 0;
}
