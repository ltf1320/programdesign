#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
const int inf=0x3f3f3f3f;
int pre[maxm];
int N,M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn*maxm];
int box[maxn+maxm];
int ent;
void _add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void add(int from,int to,int v)
{
    _add(from,to,v);
    _add(to,from,0);
}

int level[maxn+maxm];
bool getlevel(int s,int t)
{
    int now;
    memset(level,-1,sizeof(level));
    level[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(level[edge[i].to]!=-1) continue;
            if(edge[i].v==0) continue;
            level[edge[i].to]=level[now]+1;
            que.push(edge[i].to);
        }
    }
    return level[t]!=-1;
}

int makeflow(int s,int t,int maxc)
{
    if(s==t) return maxc;
    int rec=0,flow;
    for(int i=box[s];i!=-1;i=edge[i].next)
    {
        if(edge[i].v==0) continue;
        if(level[edge[i].to]<=level[s]) continue;
        flow=makeflow(edge[i].to,t,min(maxc-rec,edge[i].v));
        rec+=flow;
        edge[i].v-=flow;
        edge[i^1].v+=flow;
        if(rec==maxc) return rec;
    }
    return rec;
}

int dinic(int s,int t)
{
    int res=0;
    while(getlevel(s,t))
        res+=makeflow(s,t,inf);
    return res;
}
int tn;
void input()
{
    int t,k;
    tn=2;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&t);
        add(0,tn++,t);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",&t);
        for(int j=0;j<t;j++)
        {
            scanf("%d",&k);
            if(pre[k]!=-1)
                add(pre[k],tn,inf);
            pre[k]=tn;
            add(k+1,tn,inf);
        }
        scanf("%d",&k);
        add(tn,1,k);
        tn++;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(pre,-1,sizeof(pre));
}

int dfs(int a)
{
    cout<<a++<<endl;
    dfs(a);
}

int main()
{
    dfs(1);
    /*
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&M,&N))
    {
        init();
        input();
        printf("%d\n",dinic(0,1));
    }
    return 0;
    */
}
