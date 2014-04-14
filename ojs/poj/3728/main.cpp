#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=50000+10;
int N,M;

struct EDGE
{
    int next,to;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}
int pri[maxn];
int path[2*maxn];
int deep[2*maxn];
int dpmx[2*maxn][20];
int dpmn[2*maxn][20];
int first[maxn];
int p2[maxn];

int find2(int n)
{
    return log(1.0*n+1)/log(2.0);
}

void pre()
{
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
}
int p;
void dfs(int n,int from)
{
    first[n]=p;
    path[p]=n;
    deep[p++]=pri[n];
    for(int i=box[n];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        dfs(edge[i].to,n);
        path[p]=n;
        deep[p++]=pri[n];
    }
}

void RMQ()
{
    for(int i=0;i<=p;i++)
    {
        dpmx[i][0]=deep[i];
        dpmn[i][0]=deep[i];
    }
    for(int j=1;p2[j]<=p;j++)
        for(int i=0;i<p-p2[j-1];i++)
        {
            dpmn[i][j]=min(dpmn[i][j-1],dpmn[i+p2[j-1]][j-1]);
            dpmx[i][j]=max(dpmn[i][j-1],dpmx[i+p2[j-1]][j-1]);
        }
}

int query(int a,int b)
{
    int pp=find2(b-a);
    int mn=min(dpmn[a][pp],dpmn[b-p2[pp]+1][pp]);
    int mx=max(dpmx[a][pp],dpmx[b-p2[pp]+1][pp]);
    return mx-mn;
}

void input()
{
    memset(box,-1,sizeof(box));
    ent=0;
    p=0;
    int f,t;
    for(int i=1;i<=N;i++)
        scanf("%d",&pri[i]);
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int M;
    int a,b;
    pre();
    while(~scanf("%d",&N))
    {
        input();
        dfs(1,-1);
        RMQ();
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&a,&b);
            a=first[a];
            b=first[b];
            if(a>b)
            {
                int t=a;
                a=b;
                b=t;
            }
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}
