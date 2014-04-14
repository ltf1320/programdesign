#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100000+100;
const int maxk=500+10;

int n,m,k;

int dis[maxk][maxk];

int belong[maxn];

void floyd()
{
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            for(int p=0; p<k; p++)
                dis[j][p]=min(dis[j][p],dis[j][i]+dis[i][p]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int lst=1,c;
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            dis[i][j]=inf;
    for(int i=0; i<k; i++)
    {
        scanf("%d",&c);
        if(c==1)
            dis[i][i]=0;
        for(int j=0; j<c; j++)
            belong[lst++]=i;
    }
    int x,y;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&x,&y,&c);
        x=belong[x];
        y=belong[y];
        dis[y][x]=dis[x][y]=min(dis[x][y],c);
    }
    floyd();
    for(int i=0; i<k; i++)
        if(dis[i][i])
        {
            printf("No\n");
            return 0;
        }
    puts("Yes");
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
            if(dis[i][j]!=inf)
                printf("%d ",dis[i][j]);
            else
                printf("-1 ");
        puts("");
    }
    return 0;
}


