#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=10000+100;

int N,M;
struct EDGE
{
    int next,to;
};
EDGE edge[maxn*5];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int low[maxn],dfn[maxn];
int fln;
int fl[maxn];
int num[maxn];
int outdu[maxn];
int time;
int stack[maxn],top;
bool in[maxn];

void tarjan(int now)
{
    int nd;
    dfn[now]=low[now]=time++;
    stack[++top]=now;
    in[now]=1;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
      //      low[now]=min(low[now],low[edge[i].to]);
    }
    if(low[now]==dfn[now])
    {
        while(top!=-1)
        {
            nd=stack[top];
            fl[nd]=fln;
            in[nd]=0;
            num[fln]++;
            top--;
            if(nd==now) break;
        }
        fln++;
    }
}

void work()
{
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1;i<=N;i++)
        for(int j=box[i];j!=-1;j=edge[j].next)
            if(fl[i]!=fl[edge[j].to])
                outdu[fl[i]]++;
    int res=0;
    for(int i=0;i<fln;i++)
        if(outdu[i]==0)
        {
            if(res!=0)
            {
                printf("0\n");
                return;
            }
            res=num[i];
        }
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    time=1;
    top=-1;
    memset(in,0,sizeof(in));
    memset(outdu,0,sizeof(outdu));
    memset(num,0,sizeof(num));
    fln=0;

}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    init();
    input();
    work();
    return 0;
}
