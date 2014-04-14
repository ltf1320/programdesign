#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <queue>
using namespace std;
const int maxn=22;
const int inf=0x3f3f3f3f;

int N;
struct Point
{
    int x,y;
};
Point pns[maxn];

struct Mat
{
    int pt[4];
};
Mat mts[10000];
int mtn;

queue<int> que;
int dis[1<<20];
bool in[1<<20];
int spfa(int s)
{
    memset(in,0,sizeof(in));
    memset(dis,0,sizeof(dis));
    que.push(s);
    dis[s]=0;
    in[s]=1;
    int now,next;
    int res=0;
    bool flag;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        res=max(res,dis[now]);
        for(int i=0; i<mtn; i++)
        {
            flag=1;
            next=now;
            for(int j=0; j<4; j++)
            {
                if(now&(1<<mts[i].pt[j]))
                {
                    flag=0;
                    break;
                }
                next|=(1<<mts[i].pt[j]);
            }
            if(flag)
            {
                dis[next]=max(dis[next],dis[now]+4);
                if(!in[next])
                {
                    in[next]=1;
                    que.push(next);
                }
            }
        }
        in[now]=0;
    }
    return res;
}

void work()
{
    for(int ul=0; ul<N; ul++)
    {
        for(int ur=0; ur<N; ur++)
        {
            if(ul==ur) continue;
            if(pns[ul].y!=pns[ur].y) continue;
            if(pns[ur].x<=pns[ul].x) continue;
            for(int dl=0; dl<N; dl++)
            {
                if(pns[ul].y-pns[dl].y!=pns[ur].x-pns[ul].x) continue;
                if(pns[dl].y>=pns[ul].y) continue;
                if(dl==ul) continue;
                if(pns[dl].x!=pns[ul].x) continue;
                for(int dr=0; dr<N; dr++)
                {
                    if(pns[dr].y!=pns[dl].y) continue;
                    if(pns[dr].x!=pns[ur].x) continue;
                    mts[mtn].pt[0]=ul;
                    mts[mtn].pt[1]=ur;
                    mts[mtn].pt[2]=dl;
                    mts[mtn].pt[3]=dr;
                    mtn++;
                }
            }
        }
    }
    printf("%d\n",spfa(0));
}

void input()
{
    for(int i=0; i<N; i++)
        scanf("%d%d",&pns[i].x,&pns[i].y);
}

void init()
{
    mtn=0;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==-1) break;
        init();
        input();
        work();
    }
}
