#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500+10;
const int maxm=10000+1000;
int N,M;
int a[maxm],b[maxm],c[maxm];

struct EDGE
{
    int next,to;
};
EDGE edge[maxm*4];
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
int ti;


void tarjan(int now)
{
    dfn[now]=low[now]=ti++;
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
    ti=1;
    fln=0;
}

bool judge(int m)
{
    initMap();
    for(int i=0; i<m; i++)
    {
        if(a[i]==b[i])
        {
            if(c[i]==0)
                add(a[i]*2,a[i]*2+1);
            else if(c[i]==1)
   //             return false;
                continue;
            else add(a[i]*2+1,a[i]*2);
        }
        else
        {
            if(c[i]==0)
            {
                add(a[i]*2,b[i]*2+1);
                add(b[i]*2,a[i]*2+1);
            }
            else if(c[i]==1)
            {
                add(a[i]*2,b[i]*2);
                add(a[i]*2+1,b[i]*2+1);
                add(b[i]*2,a[i]*2);
                add(b[i]*2+1,a[i]*2+1);
            }
            else
            {
                add(a[i]*2+1,b[i]*2);
                add(b[i]*2+1,a[i]*2);
            }
        }
    }
    initTarjan();
    for(int i=0; i<2*N; i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0; i<N; i++)
        if(fl[i*2]==fl[i*2+1])
            return false;
    return true;
}

int work()
{
    int l=0,r=M,m;
    while(r>=l)
    {
        m=(r+l)>>1;
        if(judge(m))
            l=m+1;
        else r=m-1;
    }
    return r;
}

void input()
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        printf("%d\n",work());
    }
    return 0;
}
