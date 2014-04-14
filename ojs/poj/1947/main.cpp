#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=150+10;
const int inf=0x3f3f3f3f;
int dp[maxn][2][maxn];

struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
int N,P;
void add(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}

int dfs(int now,int father)
{
    dp[now][0][0]=0;
    dp[now][1][1]=0;
    int n=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==father) continue;
        n+=dfs(edge[i].to,now);
        for(int j=P;j>0;j--)
        {
            dp[now][1][j]++; //!
            for(int k=1;k<j;k++)
            {
                dp[now][1][j]=min(dp[edge[i].to][1][j-k]+dp[now][1][k],dp[now][1][j]);
      //          dp[now][0][j]=min(dp[edge[i],to][1][j-k]+dp[now][0][k],dp[now][0][j]);
            }
            dp[now][0][j]=min(dp[now][0][j],dp[edge[i].to][0][j]);
            dp[now][0][j]=min(dp[now][0][j],dp[edge[i].to][1][j]+1);
        }
    }
    dp[now][1][n]=0;
    return n;
}

void input()
{
    int f,t;
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    for(int i=0;i<=N;i++)
        for(int j=0;j<=P;j++)
            dp[i][0][j]=dp[i][1][j]=inf;
}

void print0()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=P;j++)
            printf("%d ",dp[i][0][j]);
        putchar('\n');
    }
}


void print1()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=P;j++)
            printf("%d ",dp[i][1][j]);
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    scanf("%d%d",&N,&P);
    init();
    input();
    dfs(1,1);
 //   print0();
 //   putchar('\n');
 //   print1();
    printf("%d\n",min(dp[1][0][P],dp[1][1][P]));
    return 0;
}
