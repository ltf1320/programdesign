#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=120;
bool opyed[maxn][maxn];
bool vis[maxn][maxn];
int N;
int X1,Y1,X2,Y2;

map<int,int> mpx;
map<int,int> mpy;

int xs[maxn],xn;
int ys[maxn],yn;

int find(const map<int,int> &mp,int *s,int v)
{
    int l=0,r=4*N-1;
    int m;
    while(r-l>1)
    {
        m=(r+l)>>1;
        if(s[m]==v)
        {
            if(m&1)
            {
                if(mp.count(m+1))
                    return m;
                else return m-1;
            }
            else
            {
                if(mp.count(m+1))
                    return m;
                else return m-1;
            }
        }
        if(s[m]<v)
            l=m;
        else r=m;
    }
    return l;
}

struct Build
{
    int x1,x2,y1,y2;
    void insert(int xx1,int yy1,int xx2,int yy2)
    {
        x1=min(xx1,xx2);
        x2=max(xx1,xx2);
        y1=min(yy1,yy2);
        y2=max(yy1,yy2);
        xs[xn++]=x1;
        xs[xn++]=x1-1;
        xs[xn++]=x2;
        xs[xn++]=x2+1;

        ys[yn++]=y1;
        ys[xn++]=y1-1;
        ys[xn++]=y2;
        ys[xn++]=y2+1;
    }
};
Build bds[maxn];

struct FBS
{
    int x,y,d;
    FBS(int xx,int yy,int dd):x(xx),y(yy),d(dd) {}
    FBS() {}
};

void lisan()
{
    sort(xs,xs+xn);
    sort(ys,ys+yn);
    for(int i=0; i<4*N; i++)
    {
        mpx[xs[i]]=i+1;
        mpy[ys[i]]=i+1;
    }
    for(int i=0; i<N; i++)
        for(int j=mpx[bds[i].x1-1]; j<mpx[bds[i].x2+1]; j++)
            for(int k=mpy[bds[i].y1-1]; k<mpy[bds[i].y2+1]; k++)
                opyed[j][k]=1;
    X1=find(mpx,xs,X1);
    X2=find(mpx,xs,X2);
    Y1=find(mpy,ys,Y1);
    Y2=find(mpy,ys,Y2);
}

int work()
{
    lisan();
    queue<FBS> que;
    FBS now;
    que.push(FBS(X1,Y1,-1));
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.x==X2&&now.y==Y2)
        {
            while(!que.empty()) que.pop();
            return now.d;
        }
        for(int i=now.x+1; i<4*N; i++)
            if(!opyed[i][now.y])
            {
                if(!vis[i][now.y])
                {
                    que.push(FBS(i,now.y,now.d+1));
                    vis[i][now.y]=1;
                }
            }
            else break;
        for(int i=now.x-1; i>=0; i--)
            if(!opyed[i][now.y])
            {
                if(!vis[i][now.y])
                {
                    que.push(FBS(i,now.y,now.d+1));
                    vis[i][now.y]=1;
                }
            }
            else break;
        for(int i=now.y+1; i<4*N; i++)
            if(!opyed[now.x][i])
            {
                if(!vis[now.x][i])
                {
                    que.push(FBS(now.x,i,now.d+1));
                    vis[now.x][i]=1;
                }
            }
            else break;
        for(int i=now.y-1; i>=0; i--)
            if(!opyed[now.x][i])
            {
                if(!vis[now.x][i])
                {
                    que.push(FBS(now.x,i,now.d+1));
                    vis[now.x][i]=1;
                }
            }
            else break;
    }
    return -1;
}

void init()
{
    xn=0;
    yn=0;
    mpx.clear();
    mpy.clear();
    memset(opyed,0,sizeof(opyed));
    memset(vis,0,sizeof(vis));
}

void input()
{
    scanf("%d",&N);
    int x1,x2,y1,y2;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1<<=1;
        y1<<=1;
        x2<<=1;
        y2<<=1;
        bds[i].insert(x1,y1,x2,y2);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2))
    {
        if(X1==0&&Y1==0&&X2==0&&Y2==0) break;
        X1<<=1;
        Y1<<=1;
        X2<<=1;
        Y2<<=1;
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
