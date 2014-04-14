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
};
Point pts[maxn];
Point s1,s2;
int sdis;
int getDis(const Point &a,const Point &b)
{
    return mabs(a.x-b.x)+mabs(a.y-b.y);
}

struct EDGE
{
    int to,next;
};
EDGE edge[maxn*maxn*2];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void initMap()
{
    memset(box,-1,sizeof(box));
    ent=0;
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


int fa[maxn];
int check[maxn]; //0:≈Û”—,1Œ™µ–»À

int find(int a)
{
    if(fa[a]==a) return a;
    int t=find(fa[a]);
    check[a]=check[a]^check[fa[a]];
    fa[a]=t;
    return fa[a];
}

bool Uni(int a,int b,int gx)
{
    int xa=find(a);
    int xb=find(b);
    if(xa==xb)
    {
        if((check[a]^check[b])!=gx)
            return false;
    }
    else
    {
        fa[xa]=fa[xb];
        check[xa]=gx^check[b];
    }
    return true;
}

int maxDis[maxn][2][2];
int jg[maxn];
int jgn;

int callDis()
{
    memset(jg,-1,sizeof(jg));
    memset(maxDis,-1,sizeof(maxDis));
    jgn=0;
    int f;
    for(int i=1; i<=N; i++)
    {
        f=find(i);
        if(jg[f]==-1)
            jg[f]=jgn++;
        if(check[i])
        {
            maxDis[jg[f]][0][1]=max(maxDis[jg[f]][0][1],getDis(pts[i],s2));
            maxDis[jg[f]][1][0]=max(maxDis[jg[f]][0][1],getDis(pts[i],s1));
        }
        else
        {
            maxDis[jg[f]][0][0]=max(maxDis[jg[f]][0][0],getDis(pts[i],s1));
            maxDis[jg[f]][1][1]=max(maxDis[jg[f]][1][1],getDis(pts[i],s2));
        }
    }
}


int chose[maxn];
bool CHECK(int dis)
{
    memset(chose,-1,sizeof(chose));
    initMap();
    initTarjan();
    for(int i=0; i<jgn; i++)
        for(int j=0; j<jgn; j++)
        {
            if(i==j) break;
            for(int p=0; p<2; p++) //0:s1,1:s2
                for(int q=0; q<2; q++)
                    for(int k=0; k<2; k++)
                        for(int l=0; l<2; l++)
                        {
                            if(maxDis[i][p][k]==-1) continue;
                            if(maxDis[j][q][l]==-1) continue;
                            if(maxDis[i][p][k]+maxDis[j][q][l]+(!(k==l))*(sdis)>dis)
                            {
                                add(i*2+p,j*2+(q^1));
                                add(j*2+q,i*2+(p^1));
                            }
                        }


        }
    for(int i=0; i<jgn*2; i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0; i<jgn; i++)
        if(fl[i*2]==fl[i*2+1])
            return false;
    return true;
}

int work()
{
    if(flag) return -1;
    callDis();
    int l=0,r=inf;
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
        scanf("%d%d",&pts[i].x,&pts[i].y);
    for(int i=0; i<A; i++)
    {
        scanf("%d%d",&a,&b);
        if(!Uni(a,b,1))
            flag=1;
    }
    for(int i=0; i<B; i++)
    {
        scanf("%d%d",&a,&b);
        if(!Uni(a,b,0))
            flag=1;
    }
}

void init()
{
    for(int i=1; i<=N; i++)
        fa[i]=i;
    memset(check,0,sizeof(check));
    flag=0;
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
