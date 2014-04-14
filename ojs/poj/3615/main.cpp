#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=300+10;
const int inf=0x3f3f3f3f;
int N,M,T;
int map[maxn][maxn];

int mx(int a,int b)
{
    return a>b?a:b;
}

void floyd()
{
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                if(mx(map[i][k],map[k][j])<map[i][j])
                {
                    map[i][j]=mx(map[i][k],map[k][j]);
                }
            }
}

void input()
{
    int f,t,h;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&h);
        map[f][t]=min(map[f][t],h);
    }
}

void init()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            map[i][j]=inf;
}


void work()
{
    floyd();
    int f,t;
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&f,&t);
        if(map[f][t]==inf)
            printf("-1\n");
        else printf("%d\n",map[f][t]);
    }
}

int main()
{
    scanf("%d%d%d",&N,&M,&T);
    init();
    input();
    work();
    return 0;
}
