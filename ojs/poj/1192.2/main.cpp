#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}


struct Node
{
    int x,y,v;
};
Node nds[maxn];

int abs(int a)
{
    return a>0?a:-a;
}

int dp[maxn][2];
void dfs(int now,int father)
{
    dp[now][1]=nds[now].v;
    dp[now][0]=0;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to!=father)
        {
            dfs(edge[i].to,now);
            dp[now][0]=max(dp[now][0],dp[edge[i].to][0]);
            dp[now][0]=max(dp[now][0],dp[edge[i].to][1]);
            if(dp[edge[i].to][1]>0)
                dp[now][1]+=dp[edge[i].to][1];
        }
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d%d%d",&nds[i].x,&nds[i].y,&nds[i].v);
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
            if(abs(nds[i].x-nds[j].x)+abs(nds[i].y-nds[j].y)==1)
            {
                add(i,j);
                add(j,i);
            }
    dfs(0,0);
    printf("%d\n",max(dp[0][0],dp[0][1]));
    return 0;
}
