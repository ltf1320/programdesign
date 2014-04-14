#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=10;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int N,M;
int map[maxn][maxn];
LL res;
bool judge()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(!map[i][j]) return false;
    return true;
}

void dfs(int x,int y)
{
    map[x][y]=1;
    if(x==N-1&&y==M-1)
    {
        if(judge()) res++;
        map[x][y]=0;
        return;
    }
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M)
        {
            if(!map[nx][ny])
            {
                dfs(nx,ny);
            }
        }
    }
    map[x][y]=0;
}

void input()
{
    char ch;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%c",&ch);
            if(ch==' '||ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='#')
                map[i][j]=1;
            else map[i][j]=0;
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        input();
        res=0;
        dfs(N-1,0);
        printf("%I64d\n",res);
    }
    return 0;
}
