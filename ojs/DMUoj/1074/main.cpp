#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200+10;
const int maxm=2000+100;
const int inf=0x3f3f3f3f;
int N,M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;

void add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

queue<int> que;
int dis[maxn];
int cnt[maxn];
bool in[maxn];

bool spfa(int start,int to)
{
    int now;
    que.push(start);
    for(int i=0;i<=N;i++)
        dis[i]=inf;
    dis[start]=0;
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    in[start]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(dis[now]+edge[i].v<dis[edge[i].to])
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>N)
                    {
                        while(!que.empty()) que.pop();
                        return false;
                    }
                }
            }
        }
        in[now]=0;
    }
    return true;
}

int input()
{
    int f,t,v;
    memset(box,-1,sizeof(box));
    ent=0;
    if(scanf("%d%d",&N,&M)==EOF) return EOF;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
        add(t,f,v);
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int s,d;
    while(~input())
    {
        scanf("%d%d",&s,&d);
        if(spfa(s,d)&&dis[d]!=inf)
            printf("%d\n",dis[d]);
        else printf("-1\n");
    }
    return 0;
}
