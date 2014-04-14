#include<iostream>
#include<cstdio>
#include<cmath>
#include <cstring>
using namespace std;
const int INT_MAX=0x3f3f3f3f;
#define MAXN 102
#define max(x,y) ((x)>(y)?(x):(y))
int n,m,slack[MAXN],lx[MAXN],ly[MAXN],maty[MAXN],lenx,leny;
bool vx[MAXN],vy[MAXN];//S集合、Y集合
char map[MAXN][MAXN];
int a[MAXN][MAXN];
//网络流邻接表构图要用双向边(反向边流值初始为0，可用于增广流)，二分图单向边即可(二分图的邻接矩阵边也是单向边)

int mabs(int a)
{
    return a>0?a:-a;
}
bool search(int u)
{
    int i,t;
    vx[u]=1;
    for(i=0; i<leny; ++i)
        if(!vy[i])
        {
            t=lx[u]+ly[i]-a[u][i];
            if(t==0/*相等子图*/)
            {
                vy[i]=1;
                if(maty[i]==-1||search(maty[i]))
                {
                    maty[i]=u;
                    return 1;
                }
            }
            else if(slack[i]>t)
                slack[i]=t;
        }
    return 0;
}
int KM()
{
    int i,j,ans=0;
    for(i=0; i<lenx; ++i)
        for(lx[i]=-INT_MAX,j=0; j<leny; ++j)
            lx[i]=max(lx[i],a[i][j]);
    memset(maty,-1,sizeof(maty));
    memset(ly,0,sizeof(ly));
    for(i=0; i<lenx; ++i)
    {
        //找增广路
        for(j=0; j<leny; ++j)
            slack[j]=INT_MAX;
        while(1)
        {
            memset(vx,0,sizeof(vx)); //vx,vy表示已经访问过
            memset(vy,0,sizeof(vy));
            if(search(i))//找到i对应的增广路，不再找
                break;
            //没找到增广路，修正

            int d=INT_MAX;
            for(j=0; j<leny; ++j)
                if(!vy[j]&&d>slack[j])
                    d=slack[j];
            for(j=0; j<lenx; ++j)
                if(vx[j])
                    lx[j]-=d;
            for(j=0; j<leny; ++j)
                if(vy[j])
                    ly[j]+=d;

        }
    }
    for(i=0; i<leny; ++i)
        if(maty[i]!=-1)
            ans+=a[maty[i]][i];
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d%d",&n,&m)&&n+m)
    {
        lenx=leny=0;
        for(i=0; i<n; ++i)
        {
            scanf("%s",map[i]);
            for(j=0; j<m; ++j)
                if(map[i][j]=='H')
                    lx[lenx]=i,slack[lenx++]=j;
                else if(map[i][j]=='m')
                    ly[leny]=i,maty[leny++]=j;
        }
        for(i=0; i<lenx; ++i)
            for(j=0; j<leny; ++j)
                a[i][j]=-mabs(lx[i]-ly[j])-mabs(slack[i]-maty[j]);
        printf("%d\n",KM());
    }
    return 0;
}
