#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int maxn=400;
int opyed[maxn][maxn];
bool vis[maxn][maxn];
int N;
int X1,Y1,X2,Y2;

map<int,int> mpx;
map<int,int> mpy;

int xs[maxn],xn;
int ys[maxn],yn;
set<int> xset,yset;

bool judgeud(int a)
{
    if((a&(1<<1))&&(a&(1<<3))) return false;
    return true;
}

bool judgelr(int a)
{
    if((a&(1<<0))&&(a&(1<<2))) return false;
    return true;
}

int find(const map<int,int> &mp,int *s,int v,int max)
{
    int l=0,r=max;
    int m;
    do
    {
        m=(r+l)>>1;
        if(s[m]==v)
        {
            return m-1;
        }
        if(s[m]<v)
            l=m;
        else r=m;
    }
    while(r-l>1);
    return l;
}


void printOqp()
{
    printf("%4d ",0);
    for(int i=0;i<xn;i++)
        printf("%4d ",xs[i]);
    putchar('\n');
    for(int i=0;i<yn;i++)
    {
        printf("%4d ",ys[i]);
        for(int j=0;j<xn;j++)
            printf("%4d ",opyed[j][i]);
        putchar('\n');
    }
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
        xset.insert(x1);
        xset.insert(x1-1);
        xset.insert(x2);
        xset.insert(x2-1);
        xset.insert(x2+1);
        yset.insert(y1);
        yset.insert(y1-1);
        yset.insert(y2);
        yset.insert(y2-1);
        yset.insert(y2+1);
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
    for(set<int>::iterator iter=xset.begin();iter!=xset.end();iter++)
        xs[xn++]=*iter;
    for(set<int>::iterator iter=yset.begin();iter!=yset.end();iter++)
        ys[yn++]=*iter;
    for(int i=0; i<xn; i++)
    {
        mpx[xs[i]]=i;
        mpy[ys[i]]=i;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=mpx[bds[i].x1]; j<mpx[bds[i].x2]-1; j++) //!!!
            for(int k=mpy[bds[i].y1]; k<mpy[bds[i].y2]-1; k++)
                opyed[j][k]=15;
        for(int j=mpx[bds[i].x1-1]; j<mpx[bds[i].x2]; j++)
        {
            opyed[j][mpy[bds[i].y1-1]]|=1<<2;
            opyed[j][mpy[bds[i].y2-1]]|=1<<0;
        }
        for(int k=mpy[bds[i].y1-1]; k<mpy[bds[i].y2]; k++)
        {
            opyed[mpx[bds[i].x1-1]][k]|=1<<1;
            opyed[mpx[bds[i].x2-1]][k]|=1<<3;
        }
    }
    X1=find(mpx,xs,X1,xn);
    X2=find(mpx,xs,X2,xn);
    Y1=find(mpy,ys,Y1,yn);
    Y2=find(mpy,ys,Y2,yn);
}

int work()
{
    lisan();
    queue<FBS> que;
    FBS now;
    que.push(FBS(X1,Y1,-1));
 //   cout<<xs[X2]<<" "<<ys[Y2]<<endl;
    printOqp();
    while(!que.empty())
    {
        now=que.front();
        cout<<xs[now.x]<<" "<<ys[now.y]<<" "<<now.d<<endl;
        que.pop();
        if(now.x==X2&&now.y==Y2)
        {
            while(!que.empty()) que.pop();
            return now.d;
        }
        for(int i=now.x+1; i<xn; i++)
            if(judgelr(opyed[i][now.y]))
            {
                if(!vis[i][now.y])
                {
                    que.push(FBS(i,now.y,now.d+1));
                    vis[i][now.y]=1;
                }
            }
            else break;
        for(int i=now.x-1; i>=0; i--)
            if(judgelr(opyed[i][now.y]))
            {
                if(!vis[i][now.y])
                {
                    que.push(FBS(i,now.y,now.d+1));
                    vis[i][now.y]=1;
                }
            }
            else break;
        for(int i=now.y+1; i<yn; i++)
            if(judgeud(opyed[now.x][i]))
            {
                if(!vis[now.x][i])
                {
                    que.push(FBS(now.x,i,now.d+1));
                    vis[now.x][i]=1;
                }
            }
            else break;
        for(int i=now.y-1; i>=0; i--)
            if(judgeud(opyed[now.x][i]))
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
    xset.clear();
    yset.clear();
    mpx.clear();
    mpy.clear();
    memset(opyed,0,sizeof(opyed));
    memset(vis,0,sizeof(vis));
}

void input()
{
    scanf("%d",&N);
    int x1,x2,y1,y2;
    xset.insert(2E9);
    xset.insert(-2E9);
    yset.insert(2E9);
    yset.insert(-2E9);
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
