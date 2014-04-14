#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200+10;
const int inf=0x3f3f3f3f;
bool map[maxn][maxn];
int res;
int N,M;

bool now[maxn][maxn];

bool judge()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(map[i][j]&&!now[i][j])
                return false;
        }
    return true;
}

void dfs(int x,int y,int nres,int kk)
{
    if(nres>=res)
        return;
    bool a,b,c;
    if(y==M+1)
    {
        y=1;
        x++;
    }
    if(x==N+1)
    {
        if(judge())
            res=nres;
        return;
    }
    dfs(x,y+1,nres,kk);
 //   if(x>0&&y<M+1)
    {
        if(map[x-1][y]&&map[x][y]&&map[x][y+1])
        {
            if(!now[x-1][y]||!now[x][y]||!now[x][y+1])
            {
                a=now[x-1][y];
                b=now[x][y];
                c=now[x][y+1];
                now[x-1][y]=now[x][y]=now[x][y+1]=true;
                dfs(x,y+1,nres+1,kk);
                now[x-1][y]=a;
                now[x][y]=b;
                now[x][y+1]=c;
            }
        }
    }
  //  if(x<N&&y<M)
    if(!kk)
    {
        if(map[x+1][y]&&map[x][y]&&map[x][y+1])
        {
            if(!now[x+1][y]||!now[x][y]||!now[x][y+1])
            {
                a=now[x+1][y];
                b=now[x][y];
                c=now[x][y+1];
                now[x+1][y]=now[x][y]=now[x][y+1]=true;
                dfs(x,y+1,nres+1,1);
                now[x+1][y]=a;
                now[x][y]=b;
                now[x][y+1]=c;
            }
        }

 //   if(x<N&&y>1)
        if(map[x+1][y]&&map[x][y]&&map[x][y-1])
        {
            if(!now[x+1][y]||!now[x][y]||!now[x][y-1])
            {
                a=now[x+1][y];
                b=now[x][y];
                c=now[x][y-1];
                now[x+1][y]=now[x][y]=now[x][y-1]=true;
                dfs(x,y+1,nres+1,1);
                now[x+1][y]=a;
                now[x][y]=b;
                now[x][y-1]=c;
            }
        }

  //  if(x>1&&y>1)
        if(map[x-1][y]&&map[x][y]&&map[x][y-1])
        {
            if(!now[x-1][y]||!now[x][y]||!now[x][y-1])
            {
                a=now[x-1][y];
                b=now[x][y];
                c=now[x][y-1];
                now[x-1][y]=now[x][y]=now[x][y-1]=true;
                dfs(x,y+1,nres+1,1);
                now[x-1][y]=a;
                now[x][y]=b;
                now[x][y-1]=c;
            }
        }
    }
}

void work()
{
    res=inf;
    dfs(1,1,0,0);
    if(res==inf)
        puts("-1");
    else
        printf("%d\n",res);
}

void input()
{
    char ch;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            ch=getchar();
            if(ch==' '||ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='#')
                map[i][j]=0;
            else map[i][j]=1;
        }
    for(int i=0;i<=N+1;i++)
        map[i][0]=map[i][M+1]=1;
    for(int i=0;i<=M+1;i++)
        map[0][i]=map[N+1][i]=1;
}

void init()
{
    memset(now,0,sizeof(now));
    memset(map,0,sizeof(map));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)
            break;
        init();
        input();
        work();
    }
    return 0;
}
