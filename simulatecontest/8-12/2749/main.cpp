#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500+100;
const int inf=0x3f3f3f3f;
int N,A,B;
bool flag;
int mabs(int a)
{
    return a>0?a:-a;
}

struct Point
{
    int x,y;
    int dis1,dis2;
    void getDiss();
};
Point pts[maxn];
Point s1,s2;
int sdis;
int getDis(const Point &a,const Point &b)
{
    return mabs(a.x-b.x)+mabs(a.y-b.y);
}

void Point::getDiss()
{
    dis1=getDis(*this,s1);
    dis2=getDis(*this,s2);
}

struct EDGE
{
    int to,next;
};
EDGE edge[maxn*maxn*2];
int box[maxn],box2[maxn];
int ent,ent2;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add2(int f,int t)
{
    edge[ent2].to=t;
    edge[ent2].next=box2[f];
    box2[f]=ent2++;
}

void initMap()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

void initMap2()
{
    memset(box2,-1,sizeof(box2));
    ent2=ent;
}

int dfn[maxn],low[maxn];
int fl[maxn],fln;
int stack[maxn],top;
bool in[maxn];
int time;

void tarjan(int now)
{
    dfn[now]=low[now]=time++;
    stack[++top]=now;
    in[now]=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
    }
    for(int i=box2[now]; i!=-1; i=edge[i].next)
    {
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
    }

    int nd;
    if(dfn[now]==low[now])
    {
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fl[nd]=fln;
            in[nd]=0;
            if(nd==now) break;
        }
        fln++;
    }
}

void initTarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    top=-1;
    time=1;
    fln=0;
}


bool CHECK(int dis)
{
    initMap2();
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(i==j) break;
            if(pts[i].dis1+pts[j].dis1>dis)
            {
                add2(i*2,j*2+1);
                add2(j*2,i*2+1);
            }
            if(pts[i].dis2+pts[j].dis2>dis)
            {
                add2(i*2+1,j*2);
                add2(j*2+1,i*2);
            }
            if(pts[i].dis1+pts[j].dis2+sdis>dis)
            {
                add2(i*2,j*2);
                add2(j*2,i*2);
            }
        }
    initTarjan();
    for(int i=0;i<2*N;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<N;i++)
        if(fl[i*2]==fl[i*2+1])
            return false;
    return true;
}

int work()
{
    int l=-1,r=inf;
    int m;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(!CHECK(m))
            l=m+1;
        else r=m-1;
    }
    return r+1;
}

void input()
{
    int a,b;
    scanf("%d%d%d%d",&s1.x,&s1.y,&s2.x,&s2.y);
    sdis=getDis(s1,s2);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d",&pts[i].x,&pts[i].y);
        pts[i].getDiss();
    }
    for(int i=0; i<A; i++)
    {
        scanf("%d%d",&a,&b);
        add(a*2,b*2+1);
        add(b*2,a*2+1);
    }
    for(int i=0; i<B; i++)
    {
        scanf("%d%d",&a,&b);
        add(a*2,b*2);
        add(b*2,a*2);
    }
}

void init()
{
    initMap();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&A,&B))
    {
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
