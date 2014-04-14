#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200+10;
const int inf=0x3f3f3f3f;
int N;
char table[maxn][maxn];

int dp[maxn][maxn][2];
bool vis[maxn][maxn];

void dfs(int x,int y)
{
    vis[x][y]=1;
    if(x==N&&y==N)
    {
        if(table[x][y]=='a')
            dp[x][y][0]=dp[x][y][1]=1;
        else if(table[x][y]=='b')
            dp[x][y][0]=dp[x][y][1]=-1;
        else dp[x][y][0]=dp[x][y][1]=0;
        return;
    }
    if(x<N&&!vis[x+1][y])
        dfs(x+1,y);
    if(y<N&&!vis[x][y+1])
        dfs(x,y+1);
    dp[x][y][0]=-inf;
    if(x<N)
        dp[x][y][0]=dp[x+1][y][1];
    if(y<N)
        dp[x][y][0]=max(dp[x][y][0],dp[x][y+1][1]);

    dp[x][y][1]=inf;
    if(x<N)
        dp[x][y][1]=dp[x+1][y][0];
    if(y<N)
        dp[x][y][1]=min(dp[x][y][1],dp[x][y+1][0]);
    if(table[x][y]=='a')
    {
        dp[x][y][0]++;
        dp[x][y][1]++;
    }
    else if(table[x][y]=='b')
    {
        dp[x][y][0]--;
        dp[x][y][1]--;
    }
}

void printdp()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            printf("%2d,%2d  ",dp[i][j][0],dp[i][j][1]);
        puts("");
    }
}

int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
            table[i][j]=getchar();
            if(table[i][j]==' '||table[i][j]=='\n')
            {
                j--;
                continue;
            }
        }
    dfs(1,1);
    if(dp[1][1][1]>0)
        printf("FIRST\n");
    else if(dp[1][1][1]<0)
        printf("SECOND\n");
    else printf("DRAW\n");
 //   printdp();
}
