#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=5000+10;
const int maxm=50000+100;
int N,M;
struct EDGE
{
    int from,next,to;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    box[f]=ent++;
}

LL pathf[maxn];
LL patht[maxn];
queue<int> que;
int indu[maxn],outdu[maxn];

void spfa()
{
    for(int i=1; i<=N; i++)
    {
        if(!indu[i])
        {
            que.push(i);
            pathf[i]=1;
        }
    }
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(edge[i].to<edge[i].from) continue;
            pathf[edge[i].to]+=pathf[now];
            indu[edge[i].to]--;
            if(!indu[edge[i].to])
                que.push(edge[i].to);
        }
    }

    for(int i=1; i<=N; i++)
    {
        if(!outdu[i])
        {
            que.push(i);
            patht[i]=1;
        }
    }
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(edge[i].to>edge[i].from) continue;
            patht[edge[i].to]+=patht[now];
            outdu[edge[i].to]--;
            if(!outdu[edge[i].to])
                que.push(edge[i].to);
        }
    }


}

void input()
{
    int f,t;
    int tt;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        if(f>t)
        {
            tt=f;
            f=t;
            t=tt;
        }
        add(f,t);
        add(t,f);
        indu[t]++;
        outdu[f]++;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(indu,0,sizeof(indu));
    memset(outdu,0,sizeof(outdu));
    memset(pathf,0,sizeof(pathf));
    memset(patht,0,sizeof(patht));
}

int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        spfa();
        LL res=0;
        for(int i=0; i<M; i++)
            res=max(res,pathf[edge[i*2].from]*patht[edge[i*2].to]);
        printf("%I64d\n",res);
    }
    return 0;
}
