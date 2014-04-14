#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=10000+10;
const int maxm=1000000+100;
const int inf=0x3f3f3f3f;
int N,M;
int start,end;
struct EDGE
{
    int to,next,v;
};
EDGE edge[maxm];
int box[maxn];

int ent;
void add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void input()
{
    char tmp;
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%c",&tmp);
        if(tmp=='P')
        {
            scanf("%d%d%d",&f,&t,&v);
            if(f<start) start=f;
            if(t>end) end=t;
            add(f,t,v);
            add(t,f,-v);
        }
        else if(tmp=='V')
        {
            scanf("%d%d",&f,&t);
            if(f<start) start=f;
            if(t>end) end=t;
            add(f,t,1);
        }
        else i--;
    }
    for(int i=1;i<=N;i++)
        add(0,i,0);
}

queue<int> que;
bool in[maxn];
int dis[maxn];
int cnt[maxn];
bool spfa(int start,int end)
{
    for(int i=0;i<maxn;i++) dis[i]=-inf;
    memset(in,0,sizeof(in));
    memset(cnt,0,sizeof(cnt));
    int now;
    que.push(start);
    in[start]=1;
    dis[start]=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        in[now]=0;
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[edge[i].to]<dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>N)
                    {
                        while(!que.empty()) que.pop();
                        return false;
                    }
                    que.push(edge[i].to);
                }
            }
        }
    }
    return true;
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    start=inf;
    end=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        if(spfa(0,1)) printf("Reliable\n");
        else printf("Unreliable\n");
    }
    return 0;
}
