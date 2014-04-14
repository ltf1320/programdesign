#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
#define N 5050
#define M 50050

struct node
{
    int to,next,w;
} edge[M*2]; // 逆向建下图...


int n,m,cnt,num;
__int64 tmax;
int pre[N],d[N],mark[N],d1[N],mark1[N];
__int64 cost[N],cost1[N];
int tx[M],ty[M];


void init()
{
    cnt=0;
    num=0;
    tmax=0;
    memset(pre,-1,sizeof(pre));
    memset(d,0,sizeof(d));
    memset(d1,0,sizeof(d1));
    memset(mark,0,sizeof(mark));
    memset(tx,0,sizeof(tx));
    memset(ty,0,sizeof(ty));
    memset(cost,0,sizeof(cost));
    memset(mark1,0,sizeof(mark1));
    memset(cost1,0,sizeof(cost1));
}

void add_edge(int u,int v)
{
    edge[cnt].w=1;
    edge[cnt].to=v;
    edge[cnt].next=pre[u];
    pre[u]=cnt++;
}

void topsort()
{
    int cur,p,v;
    queue<int > k;
    for(int i=1; i<=n; i++)
    {
        if(d[i]==0)
        {
            mark[i]=1;
            k.push(i);
            cost[i]=1;
        }
    }
    while(!k.empty())
    {
        cur=k.front();
        k.pop();
        for(p=pre[cur]; p!=-1; p=edge[p].next)
        {
            if(mark[v=edge[p].to]==0)
            {
                d[v]--;
                cost[v]+=cost[cur]*edge[p].w;
                if(d[v]==0)
                {
                    mark[v]=1;
                    k.push(v);
                }
            }
        }
    }
}


void topsort1()
{
    int cur,p,v;
    queue<int > k;
    for(int i=1; i<=n; i++)
    {
        if(d1[i]==0)
        {
            mark1[i]=1;
            if(i==n)
                k.push(i);
            cost1[i]=1;
        }
    }
    while(!k.empty())
    {
        cur=k.front();
        k.pop();
        for(p=pre[cur]; p!=-1; p=edge[p].next) // 这种扯蛋的方法过了也会觉得扯蛋
        {
            if(mark1[v=edge[p].to]==0)
            {
                d1[v]--;
                cost1[v]+=cost1[cur]*edge[p].w;
                if(d1[v]==0)
                {
                    mark1[v]=1;
                    k.push(v);
                }
            }
        }
    }
}

int main()
{
    int u,v,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            tx[i]=u,ty[i]=v;
            flag=0;
            for(int p=pre[u]; p!=-1; p=edge[p].next)
            {
                if(edge[p].to==v)
                {
                    edge[p].w++;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                add_edge(u,v);
                d[v]++;
            }
            flag=0;
            for(int p=pre[v]; p!=-1; p=edge[p].next)
            {
                if(edge[p].to==u)
                {
                    edge[p].w++;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue ;
            add_edge(v,u);
            d1[u]++;
        }
        topsort();
        topsort1();
        for(int i=0; i<m; i++)
        {
            int x,y;
            x=tx[i],y=ty[i];
            if(cost[x]*cost1[y]>tmax)
                tmax=cost[x]*cost1[y];
        }
        printf("%I64d\n",tmax);
    }
    return 0;
}
