#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+100;
const int inf=maxn;  //!!
int N;
int dp[maxn][3]; //0:亮着不选  1：选  2：不亮

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


void dfs(int now,int from)
{
    dp[now][1]=1;
    dp[now][2]=0;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to!=from)
        {
            dfs(edge[i].to,now);
            dp[now][1]+=min(dp[edge[i].to][2],min(dp[edge[i].to][1],dp[edge[i].to][0]));  //!!
            dp[now][2]+=dp[edge[i].to][0];
     //       if(dp[edge[i].to][0]>dp[edge[i].to][1])
     //           printf("wrong: %d\n",now);
     //       dp[now][2]+=min(dp[edge[i].to][0],dp[edge[i].to][1]);
        }
    }
    dp[now][0]=inf;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(edge[i].to!=from)
        dp[now][0]=min(dp[now][2]-dp[edge[i].to][0]+dp[edge[i].to][1],dp[now][0]);
         //   dp[now][0]=min(dp[now][2]+max(0,-dp[edge[i].to][0]+dp[edge[i].to][1]),dp[now][0]);
    }
}

int input()
{
    int a,b;
    memset(box,-1,sizeof(box));
    if(scanf("%d",&N)==EOF) return EOF;
    ent=0;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    return 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~input())
    {
        dfs(1,1);
        printf("%d\n",min(dp[1][0],dp[1][1]));
    }
    return 0;
}
