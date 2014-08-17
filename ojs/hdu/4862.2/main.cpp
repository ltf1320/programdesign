#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxm=20000;
const int maxn=10*10*10;
const int inf=0x3f3f3f3f;
const int ddd=10*10*10;
const int S=0,T=1;
int N,M,K;
int NN;
char arr[11][11];

struct EDGE
{
    int to,next,cap,cost,from;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].cap=cap;
    edge[ent].cost=cost;
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap,int cost)
{
    _add(f,t,cap,cost);
    _add(t,f,0,-cost);
}

int getp(int x,int y)
{
    return (x*M+y)*2+2;
}

int in[maxn];
int dis[maxn];
int from[maxn];
queue<int> que;

bool spfa(int f,int t)
{
    int now;
    for(int i=0; i<NN; i++)
        dis[i]=inf;
    memset(in,0,sizeof(in));
    memset(from,-1,sizeof(from));
    que.push(f);
    in[f]=1;
    dis[f]=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(edge[i].cap&&dis[edge[i].to]>dis[now]+edge[i].cost)
            {
                dis[edge[i].to]=dis[now]+edge[i].cost;
                from[edge[i].to]=i;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return 0;
    return dis[t];
}

int fyl(int f,int t)
{
    int cost=0;
    int mincap;
    while(spfa(f,t))
    {
        mincap=inf;
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
            mincap=min(mincap,edge[i].cap);
        for(int i=from[t]; i!=-1; i=from[edge[i].from])
        {
            edge[i].cap-=mincap;
            edge[i^1].cap+=mincap;
        }
        cost+=dis[t]*mincap;
    }
    return cost;
}




void buildMap()
{
    ent=0;
    memset(box,-1,sizeof(box));
    NN=N*M*2+5;
    int SS=N*M*2+4;
    add(S,SS,K,0);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            add(getp(i,j),getp(i,j)+1,1,-ddd);
            add(SS,getp(i,j),1,0);
            add(getp(i,j)+1,T,1,0);
            for(int k=i+1; k<N; k++)
            {
                add(getp(i,j)+1,getp(k,j),1,(k-i-1)-(arr[i][j]==arr[k][j]?arr[i][j]-'0':0));
            }
            for(int k=j+1; k<M; k++)
            {
                add(getp(i,j)+1,getp(i,k),1,(k-j-1)-(arr[i][j]==arr[i][k]?arr[i][j]-'0':0));
            }
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        printf("Case %d : ",cas);
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin>>arr[i][j];
        if(K<min(N,M))
        {
            printf("-1\n");
            continue;
        }
        buildMap();
        printf("%d\n",-fyl(0,1)-N*M*ddd);
    }
    return 0;
}
