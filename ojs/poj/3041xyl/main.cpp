#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=500+10;
int N,M;
bool visit[MAXN];
int mark[MAXN];
bool map[MAXN][MAXN];

bool dfs(int u){
    int i;
    for(i=1;i<=N;i++)
        if(map[u][i] && !visit[i]){
            visit[i]=true;
            if(mark[i]==-1 || dfs(mark[i])){
                mark[i]=u;
                return true;
            }
        }
    return false;
}
int hungary(){
    int i,ans=0;
    for(i=1;i<=N;i++){
        memset(visit,false,sizeof(visit));
        if(dfs(i)) ans++;
    }
    return ans;
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        map[f][t]=1;
    }
}

void init()
{
    memset(map,0,sizeof(map));
    memset(mark,-1,sizeof(mark));
    memset(visit,0,sizeof(visit));
}

int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        printf("%d\n",hungary());
    }
    return 0;
}
