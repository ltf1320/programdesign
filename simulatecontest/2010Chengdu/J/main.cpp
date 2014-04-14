#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=10000+100;
const int inf=0x3f3f3f3f;
const int maxm=100+10;
int N,K,M;
char res[maxn];
char nan[maxn];
int map[maxm][maxm];

struct EDGE
{
    int next,to,from,cap,cost;
};
EDGE edge[maxm*maxm];///
int box[maxm];
int ent;

void _add(int f,int t,int cap,int cost)
{
    edge[ent].from=f;
    edge[ent].to=t;
    edge[ent].cap=cap;
    edge[ent].cost=cost;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap,int cost)
{
    _add(f,t,cap,cost);
    _add(t,f,0,-cost);
}

int in[maxm];
int dis[maxm];
int from[maxm];
queue<int> que;

bool spfa(int f,int t)
{
    int now;
    for(int i=0; i<maxm; i++)
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
                    in[edge[i].to]=1;
                    que.push(edge[i].to);
                }
            }
        }
        in[now]=0;
    }
    if(dis[t]==inf) return 0;
    return dis[t];
}

int fyl(int s,int t)
{
    int cost=0;
    int mincap;
    while(spfa(s,t))
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

void initMap()
{
    memset(map,0,sizeof(map));
    memset(box,-1,sizeof(box));
    ent=0;
}

void printMap()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            printf("%d ",map[i][j]);
        }
        puts("");
    }
    puts("");
}

void work()
{
    int nres;
    for(int i=0; i<M; i++)
    {
        initMap();
        for(int i=0; i<N; i++)
        {
            scanf("%c",&nan[i]);
            if(nan[i]==' '||nan[i]=='\n')
            {
                i--;
                continue;
            }
            map[nan[i]-'A'][res[i]-'A']++;
        }
        for(int i=0; i<26; i++)
            for(int j=0; j<26; j++)
            {
                if(map[i][j])
                {
                    add(i+2,j+2+26,1,-map[i][j]);
                }
            }
 //       printMap();
        for(int i=0; i<26; i++)
        {
            add(0,i+2,1,0);
            add(i+2+26,1,1,0);
        }
        nres=fyl(0,1);
        printf("%.4f\n",-1.0*nres/N);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&K,&M);
        //input
        for(int i=0; i<N; i++)
        {
            scanf("%c",&res[i]);
            if(res[i]==' '||res[i]=='\n')
            {
                i--;
                continue;
            }
        }
  //      printf("%s",res);
        work();
    }
    return 0;
}

/*
int main()
{
    freopen("out.txt","w",stdout);
    printf("1\n10000 26 1\n");
    for(int i=0;i<10000;i++)
        printf("%c ",'A');
    puts("");
    for(int i=0;i<10000;i++)
        printf("%c ",'B');
}
*/
