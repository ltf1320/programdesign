#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=2*10000+100;
const int maxm=100000*4+1000;
int N,M;
struct EDGE
{
    int next,to;
}edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f*2,t*2+1);
        add(f*2+1,t*2);
        add(t*2,f*2+1);
        add(t*2+1,f*2);
    }
}
int dfn[maxn],low[maxn];
int fl[maxn],fln;
vector<int> fls[maxn];
int stack[maxn],top;
bool in[maxn];
int ti;

void tarjan(int now)
{
    dfn[now]=low[now]=ti++;
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
    }
    int nd;
    if(dfn[now]==low[now])
    {
        fls[fln].clear();
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fls[fln].push_back(nd);
            fl[nd]=fln;
            in[nd]=0;
            if(nd==now) break;
        }
        fln++;
    }
}

bool vis[maxn];

void initTarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    top=-1;
    fln=0;
}



void work()
{
    initTarjan();
    for(int i=2;i<=2*N+1;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=N;i++)
        if(fl[i*2]==fl[i*2+1])
        {
            printf("Fault\n");
            return;
        }
    int resa=0,resb=0;
    int ra,rb;
    for(int i=0;i<fln;i++)
    {
        ra=rb=0;
        if(vis[fls[i][0]/2]) continue;
        for(int j=0;j<(int)fls[i].size();j++)
        {
            if(fls[i][j]%2)
                ra++;
            else rb++;
            vis[fls[i][j]/2]=1;
        }
        if(ra<rb)
        {
            int t=ra;
            ra=rb;
            rb=t;
        }
        if(resa<resb)
        {
            resa+=ra;
            resb+=rb;
        }
        else
        {
            resa+=rb;
            resb+=ra;
        }

    }
    printf("%d\n",max(resa,resb));
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(vis,0,sizeof(vis));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
