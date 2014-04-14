#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N,M,K;
//int map[maxn][maxn];
int dis[maxn][maxn];

void floyd()
{
    for(int k=0;k<=N;k++)
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
            {
                if(dis[i][k]!=-1&&dis[k][j]!=-1)
                {
                    if(dis[i][j]==-1||dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
}
int man[26];
int mdis[26];
int dp[maxn];
int work()
{
    dp[0]=0;
    int dj;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<K;j++)
        {
            if(dis[man[j]][i]-dis[man[j]][0]+dis[i][0]<dp[i])
            {
                dp[i]=dis[man[j]][i]-dis[man[j]][0]+dis[i][0];
                dj=j;
            }
        }
        mdis[dj]+=dis[man[dj]][i]-dis[man[dj]][0]+dis[i][0];
        man[dj]=i;
    }
    int res=0;
    for(int i=0;i<K;i++)
        res+=mdis[i];
    return res;
}

void input()
{
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        dis[f][t]=dis[t][f]=v;
    }
}

void init()
{
    memset(dis,-1,sizeof(dis));
    memset(man,0,sizeof(man));
    memset(mdis,0,sizeof(mdis));
    for(int i=0;i<=N;i++)
        dis[i][i]=0;
    for(int i=0;i<=N;i++)
        dp[i]=inf;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        if(N==0&&M==0&&K==0) break;
        init();
        input();
        floyd();
        /*
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
                printf("%d ",dis[i][j]);
            printf("\n");
        }
        */
        printf("%d\n",work());
    }
    return 0;
}
