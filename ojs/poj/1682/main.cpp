//∫√Ã‚∞°
#include <iostream>
#include <cstdio>
#include <Cstring>
using namespace std;
const int maxn=100+10;
const int inf=0x1f3f3f3f;
int xn,yn,zn;
int XY[maxn][maxn],YZ[maxn][maxn],ZX[maxn][maxn];
int X[maxn],Y[maxn],Z[maxn];
int abs(int a){return a>0?a:-a;}
int work()
{
    for(int i=xn;i>0;i--)
        for(int j=1;j<=yn;j++)
            XY[i][j]=min(XY[i+1][j-1],min(XY[i][j-1],XY[i+1][j]))+abs(X[i]-Y[j]);
    for(int i=yn;i>0;i--)
        for(int j=1;j<=zn;j++)
            YZ[i][j]=min(YZ[i+1][j-1],min(YZ[i][j-1],YZ[i+1][j]))+abs(Y[i]-Z[j]);
    for(int i=zn;i>0;i--)
        for(int j=1;j<=xn;j++)
            ZX[i][j]=min(ZX[i+1][j-1],min(ZX[i][j-1],ZX[i+1][j]))+abs(Z[i]-X[j]);
    int ans=inf;
    for(int i=0;i<=xn;i++)
        for(int j=0;j<=yn;j++)
            for(int k=0;k<=zn;k++)
            {
                ans=min(ans,XY[i][j]+YZ[j][k]+ZX[k][i]);
                ans=min(ans,XY[i][j]+YZ[j][k]+ZX[k+1][i]);
                ans=min(ans,XY[i][j]+YZ[j+1][k]+ZX[k][i]);
                ans=min(ans,XY[i+1][j]+YZ[j][k]+ZX[k][i]);
                ans=min(ans,XY[i+1][j]+YZ[j+1][k]+ZX[k][i]);
                ans=min(ans,XY[i][j]+YZ[j+1][k]+ZX[k+1][i]);
                ans=min(ans,XY[i+1][j]+YZ[j][k]+ZX[k+1][i]);
                ans=min(ans,XY[i+1][j]+YZ[j+1][k]+ZX[k+1][i]); //!
            }
    return ans;
}

void init()
{
    for(int i=0;i<=xn+1;i++)
        for(int j=0;j<=yn;j++)
            XY[i][j]=inf;
    XY[xn+1][0]=0;
    for(int i=0;i<=yn+1;i++)
        for(int j=0;j<=zn;j++)
            YZ[i][j]=inf;
    YZ[yn+1][0]=0;
    for(int i=0;i<=zn+1;i++)
        for(int j=0;j<=xn;j++)
            ZX[i][j]=inf;
    ZX[zn+1][0]=0;
}

void input()
{
    for(int i=1;i<=xn;i++)
        scanf("%d",&X[i]);
    for(int i=1;i<=yn;i++)
        scanf("%d",&Y[i]);
    for(int i=1;i<=zn;i++)
        scanf("%d",&Z[i]);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&xn,&yn,&zn);
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
