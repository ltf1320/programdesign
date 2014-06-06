#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=500+20;
const int maxm=2500+20;
const int inf=0x7fffffff;

int n,m,w;


struct EDGE
{
    int to,next;
    int v;
};
EDGE edge[maxm*2];
int box[maxn];

int ctn;
void add(int from,int to,int v)
{
    edge[ctn].to=to;
    edge[ctn].next=box[from];
    edge[ctn].v=v;
    box[from]=ctn++;
}

int cnt[maxn];
int dis[maxn];
bool in[maxn];
bool vis[maxn];
deque<int> que;

bool spfa(int start)
{
    memset(in,0,sizeof(in));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    for(int i=0; i<=n; i++) dis[i]=inf;
    que.push_back(start);
    in[start]=1;
    dis[start]=0;
    int tmp;
    while(!que.empty())
    {
        tmp=que.front();
        que.pop_front();
        for(int i=box[tmp]; i!=-1; i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[tmp]+edge[i].v)
            {
                dis[edge[i].to]=dis[tmp]+edge[i].v;
                if(!in[edge[i].to])
                {
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>n)
                    {
                        while(!que.empty()) que.pop_back();
                        return true;
                    }
                    in[edge[i].to]=1;

                    if(vis[edge[i].to])
                        que.push_front(edge[i].to);
                    que.push_back(edge[i].to);
                    vis[edge[i].to]=1;
                }
            }
        }
        in[tmp]=0;
    }
    return false;
}

void init()
{
    memset(box,-1,sizeof(box));
    ctn=0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int F;
    int S,E,T;
    scanf("%d",&F);
    while(F--)
    {
        init();
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&S,&E,&T);
            add(S,E,T);
            add(E,S,T);
        }
        for(int i=0; i<w; i++)
        {
            scanf("%d%d%d",&S,&E,&T);
            add(S,E,-T);
        }
        if(spfa(1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
