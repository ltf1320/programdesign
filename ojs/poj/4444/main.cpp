#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=120;
bool opyed[maxn][maxn];
int N;
int X1,Y1,X2,Y2;

map<int,int> mpx;
map<int,int> mpy;

int xs[maxn],xsn;
int ys[maxn],ysn;

int find(int *s,int v)
{
    int l=0,r=2*N-1;

}

struct Build
{
    int x1,x2,y1,y2;
    void reset(int xx1,int yy1,int xx2,int yy2)
    {
        x1=min(xx1,xx2);
        x2=max(xx1,xx2);
        y1=min(yy1,yy2);
        y2=max(yy1,yy2);
    }
};
Build bds[maxn];

void init()
{
    xsn=0;
    ysn=0;
    mpx.clear();
    mpy.clear();
    memset(opyed,0,sizeof(opyed));
}

void lisan()
{
    sort(xs,xs+xsn);
    sort(ys,ys+ysn);
    for(int i=0;i<2*N;i++)
    {
        mpx[xs[i]]=i+1;
        mpy[ys[i]]=i+1;
    }
    for(int i=0;i<N;i++)
        for(int j=mpx[bds[i].x1];j<mpx[bds[i].x2];j++)
            for(int k=mpy[bds[i].y1];k<mpy[bds[i].y2];k++)
                opyed[j][k]=1;
}

void input()
{
    scanf("%d",&N);
    int x1,x2,y1,y2;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        bds[i].reset(x1,y1,x2,y2);
        xs[xsn++]=x1;
        xs[xsn++]=x2;
        ys[ysn++]=y1;
        ys[ysn++]=y2;
    }
}


int main()
{
    while(~scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2))
    {
        if(X1==0&&Y1==0&&X2==0&&Y2==0) break;
        input();
    }
    return 0;
}
