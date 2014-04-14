#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxm=20000;
int N,M;

int map[maxn][maxn];

int res=0;
bool vis[maxn];
void dfs(int now)
{
    vis[now]=1;
    for(int i=1; i<=N; i++)
    {
        if(map[now][i])
        {
            if(!vis[i])
                dfs(i);
            for(int j=1; j<=N; j++)
                if(map[i][j])
                    map[now][j]=1;
        }
    }
}

void printmap()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            printf("%d ",map[i][j]);
        puts("");
    }
}

void work()
{
 //   printmap();
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
            dfs(i);
    }
//    printmap();
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(map[i][j])
                res++;
    res=N*(N-1)/2-res;
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        map[f][t]=1;
    }
}

void init()
{
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    init();
    input();
    work();
    return 0;
}
