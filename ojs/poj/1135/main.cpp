#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=500+10;

int fabs(int a)
{
    return a>0?a:-a;
}

int N,M;
struct Res
{
    bool type;
    int l,r;
    double time;
};
Res res;

struct EDGE
{
    int to,next,t;
};
EDGE edge[2*maxn*maxn];
int box[maxn];
int ent;

void add(int f,int t,int ti)
{
    edge[ent].to=t;
    edge[ent].t=ti;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int dis[maxn];
//bool in[maxn];
struct FSO
{
    int n,dis;
    FSO(int nn,int d):n(nn),dis(d) {}
    bool operator<(const FSO& a) const
    {
        return dis>a.dis;
    }
};
priority_queue<FSO> que;
void spfa()
{
    que.push(FSO(1,0));
    int now;
//    memset(in,0,sizeof(in));
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
//    in[1]=1;
    double kk;
    while(!que.empty())
    {
        now=que.top().n;
        if(que.top().dis>dis[now])
        {
            que.pop();
            continue;
        }
        if(dis[now]>res.time)
        {
            res.type=0;
            res.l=now;
            res.time=dis[now];
        }
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(dis[now]+edge[i].t<dis[edge[i].to]||dis[edge[i].to]==-1)
            {
                dis[edge[i].to]=dis[now]+edge[i].t;
//               if(!in[edge[i].to])
                {
                    que.push(FSO(edge[i].to,dis[edge[i].to]));
                    //                  in[edge[i].to]=1;
                }
            }
            else
            {
                if(fabs(dis[now]-dis[edge[i].to])<edge[i].t)
                {
                    kk=(1.0*edge[i].t-fabs(dis[now]-dis[edge[i].to]))/2+max(dis[now],dis[edge[i].to]);
                    if(kk>res.time)
                    {
                        res.type=1;
                        res.time=kk;
                        res.l=now;
                        res.r=edge[i].to;
                    }
                }
            }
        }
        //      in[now]=0;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    res.time=0;
    res.type=0;
    res.l=1;
}

void input()
{
    int f,t,ti;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d",&f,&t,&ti);
        add(f,t,ti);
        add(t,f,ti);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        if(cas) putchar('\n');
        cas++;
        init();
        input();
        spfa();
        if(res.type)
            printf("System #%d\nThe last domino falls after %.1f seconds, between key dominoes %d and %d.\n",cas,res.time,min(res.l,res.r),max(res.l,res.r));
        else printf("System #%d\nThe last domino falls after %.1f seconds, at key domino %d.\n",cas,res.time,res.l);
    }
    return 0;
}
