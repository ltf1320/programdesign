#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+100;
const int inf=0x3f3f3f3f;
int map[maxn][maxn];
bool vis[maxn][maxn];
int N,M;
const int dx[]= {0,0,1,-1};
const int dy[]= {1,-1,0,0};
int dp[maxn][maxn];

bool check(int x,int y)
{
    if(x<0||x>=N||y<0||y>=M)
        return false;
    return true;
}

int find(int i,int j)
{
    if(i==6&&j==6)
    {
        i++;
        i--;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    vis[i][j]=1;
    int nx,ny;
    int res=0;
    for(int k=0; k<4; k++)
    {
        nx=i+dx[k];
        ny=j+dy[k];
        if(check(nx,ny)&&(map[i][j]+1)%4==map[nx][ny])
        {
            if(vis[nx][ny])
                return inf;
            res=max(res,find(nx,ny));
            if(res==inf)
                return inf;
        }
    }
    if(map[i][j]==3)
        res++;
    dp[i][j]=res;
    vis[i][j]=0;
    return res;
}

void input()
{
    char ch;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            ch=getchar();
            if(ch==' '||ch=='\n')
            {
                j--;
                continue;
            }
            switch(ch)
            {
            case 'D':
                map[i][j]=0;
                break;
            case 'I':
                map[i][j]=1;
                break;
            case 'M':
                map[i][j]=2;
                break;
            case 'A':
                map[i][j]=3;
                break;
            }
        }
}

int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    input();
    int res=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(map[i][j]==0)
            {
                res=max(res,find(i,j));
                if(res==inf)
                    break;
            }
    if(res==0)
        puts("Poor Dima!");
    else if(res==inf)
        puts("Poor Inna!");
    else
        printf("%d\n",res);
    return 0;
}
