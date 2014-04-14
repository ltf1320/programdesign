#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=100+10;   //用50+10会WA,改为100+10就过了，不理解！！！！
const int maxp=100+10;   //注意A的数目不是50！！最多是2500！！测试数据最多为100
const int inf=30000;

int map[maxn][maxn];
//0 for space,-2 for S,n for An,-1 for wall
int x,y;
int sx,sy;
int an;
int dis[maxp][maxp];

struct Point
{
    int x,y;
};
Point pnt[maxp];

int quex[maxn*maxn];
int quey[maxn*maxn];
int quedp[maxn*maxn];
int now,maxdp;
bool vis[maxn][maxn];
void bfs(int sx,int sy)
{
    int nx,ny,ndp;
    memset(vis,0,sizeof(vis));
    dis[now][now]=0;
    int head=0,tail=1;
    quex[head]=sx;
    quey[head]=sy;
    quedp[head]=0;
    while(head<tail)
    {
        nx=quex[head];
        ny=quey[head];
        ndp=quedp[head];
        if(vis[ny][nx])
        {
            head++;
            continue;
        }
        if(ndp>maxdp) return;
        head++;
        if(map[ny][nx]==-1) continue;
        if(map[ny][nx]>0)
            dis[now][map[ny][nx]]=dis[map[ny][nx]][now]=ndp;
        if(nx>0)
        {
            quex[tail]=nx-1;
            quey[tail]=ny;
            quedp[tail++]=ndp+1;
        }
        if(nx<x-1)
        {
            quex[tail]=nx+1;
            quey[tail]=ny;
            quedp[tail++]=ndp+1;
        }
        if(ny>0)
        {
            quex[tail]=nx;
            quey[tail]=ny-1;
            quedp[tail++]=ndp+1;
        }
        if(ny<y-1)
        {
            quex[tail]=nx;
            quey[tail]=ny+1;
            quedp[tail++]=ndp+1;
        }
        vis[ny][nx]=1;
    }
}



bool pvis[maxp];
int low_dis[maxp];
int prim()
{
    memset(pvis,0,sizeof(pvis));
    pvis[0]=1;
    for(int i=0;i<an;i++) low_dis[i]=inf;
    int res=0;
    int now=0;
    int l,ndis;
    for(int k=0;k<an-1;k++)
    {
        ndis=inf;
        for(int i=0;i<an;i++)
        {
            if(!pvis[i]&&dis[now][i]&&dis[now][i]<low_dis[i])
                low_dis[i]=dis[now][i];
            if(!pvis[i]&&ndis>low_dis[i])
            {
                l=i;
                ndis=low_dis[i];
            }
        }
        now=l;
        pvis[l]=1;
        res+=ndis;
    }
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    int N;
    char tmp[maxp];
    scanf("%d",&N);
    while(N--)
    {
        //input
        scanf("%d%d",&x,&y);
        gets(tmp);    //用getchar就会错
        an=1;
        for(int i=0;i<y;i++)
        {
            gets(tmp);
            for(int j=0;j<x;j++)
            {
                switch(tmp[j])
                {
                    case ' ':map[i][j]=0;break;
                    case 'S':map[i][j]=-2;
                        sx=j,sy=i;break;
                    case 'A':
                        map[i][j]=an;
                        pnt[an].x=j;pnt[an].y=i;
                        an++;
                        break;
                    case '#':map[i][j]=-1;break;
                }
            }
        }
        //calculate the dis
        now=0;
        maxdp=inf;
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        bfs(sx,sy);
        for(now=1;now<an;now++)
        {
            memset(vis,0,sizeof(vis));
            maxdp=dis[0][now];
            bfs(pnt[now].x,pnt[now].y);
        }
        printf("%d\n",prim());
    }
    return 0;
}
