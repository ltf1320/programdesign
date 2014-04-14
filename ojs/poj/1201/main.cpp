#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int N;
const int inf=0x3f3f3f3f;
const int maxn=500000+100;
struct EDGE
{
    int to,next,v;
};
EDGE edge[maxn];
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
bool in[maxn];
int dis[maxn];
int spfa(int start,int end)
{
    for(int i=start;i<=end;i++) dis[i]=-inf;
    int now;
    que.push(start);
    dis[start]=0;
    in[start]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(dis[edge[i].to]<dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
        }
        in[now]=0;
    }
    return dis[end];
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        int f,t,v;
        int start=inf,end=0;
        memset(box,-1,sizeof(box));
        end=0;
        while(N--)
        {
            scanf("%d%d%d",&f,&t,&v);
            add(f,t+1,v);
            if(start>f) start=f;
            if(t+1>end) end=t+1;
        }
        for(int i=start; i<end; i++)
        {
            add(i,i+1,0);
            add(i+1,i,-1);
        }
        printf("%d\n",spfa(start,end));
    }
    return 0;
}
