#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+100;
const int inf=0x3f3f3f3f;
int N;
int c;

struct EDGE
{
    int next,to,v;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void input()
{
    scanf("%d",&N);
    int t;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            scanf("%d",&t);
            add(i,j,t+c);
        }
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int dis[maxn];
bool in[maxn];
queue<int> que;
int spfa()
{
    int now;
    for(int i=0; i<=N; i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    que.push(0);
    dis[0]=0;
    in[0]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[now]+edge[i].v)
            {
                dis[edge[i].to]=dis[now]+edge[i].v;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    return dis[N];
}



int main()
{
    freopen("n.txt","r",stdin);
    while(~scanf("%d",&c))
    {
        init();
        input();
        printf("%d\n",spfa());
    }
    return 0;
}
