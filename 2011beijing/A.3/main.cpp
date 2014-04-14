#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1000+100;
const int inf=0x3f3f3f3f;
int N;
float map[maxn][maxn];
bool vis[maxn];
float maxl;
struct City
{
    int x,y,p;
};
City cities[maxn];


struct FSO
{
    int i;
    float dis;
    bool ded;
    int P;
    FSO(int ii,float d,bool de,int p):i(ii),dis(d),ded(de),P(p) {}
    FSO() {}
    bool operator<(const FSO& a)const
    {
        return dis>a.dis;
    }
};



float prim()
{
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //!!!!!不要漏
    int res=0;
    priority_queue<FSO> que;
    que.push(FSO(1,0,0,0));
    FSO now;
    while(!que.empty())
    {
        for(int i=1; i<=N; i++)
        {
            if(!vis[i]) break;
            if(i==N)
            {
                float res=0;
                while(!que.empty())
                {
                    now=que.top();
                    if(now.ded)
                    {
                        if(now.dis/now.P>res)
                            res=now.dis/now.P;
                    }
                    que.pop();
                }
                return res;
            }
        }
        now=que.top();
        if(now.ded&&vis[now.i])
        {
            que.pop();
            continue;
        }
        que.pop();
        for(int i=2; i<=N; i++)
        {
            if(!vis[i]&&map[now.i][i]!=-1)
            {
                que.push(FSO(i,now.dis+map[now.i][i],now.ded,now.P));
            }
            if(!now.ded&&map[now.i][i]!=-1)
            {
                que.push(FSO(i,now.dis,1,cities[now.i].p+cities[i].p));
            }
        }
        if(!now.ded)
            vis[now.i]=1;
    }
    return res;
}


void init()
{
    memset(map,-1,sizeof(map));
    maxl=0;
}


void input()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        scanf("%d%d%d",&cities[i].x,&cities[i].y,&cities[i].p);
    for(int i=1; i<=N; i++)
        for(int j=i+1; j<=N; j++)
            map[i][j]=map[j][i]=sqrt(1.0*(cities[i].x-cities[j].x)*(cities[i].x-cities[j].x)+1.0*(cities[i].y-cities[j].y)*(cities[i].y-cities[j].y));
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        printf("%.2f\n",prim());
    }
    return 0;
}
