#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1010;
const int maxm=6000;
int N,M;
struct EDGE
{
    int next,to;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int fln;
int fl[maxn];
int time;
int low[maxn],dfn[maxn];
int stack[maxn],top;
bool in[maxn];
int indu[maxn];
vector<int> fls[maxn];

void tarjan(int now)
{
    int nd;
    low[now]=dfn[now]=time++;
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
        //    low[now]=min(low[now],dfn[edge[i].to]);
                low[now]=min(low[now],low[edge[i].to]);
    }
    if(dfn[now]==low[now])
    {
        fls[fln].clear();
        while(top!=-1)
        {
            nd=stack[top];
            in[nd]=0;
            fl[nd]=fln;
            fls[fln].push_back(nd);
            top--;
            if(nd==now) break;
        }
        fln++;
    }
}

void work()
{
    for(int i=1; i<=N; i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1; i<=N; i++)
        for(int j=box[i]; j!=-1; j=edge[j].next)
            if(fl[i]!=fl[edge[j].to])
            {
                indu[fl[edge[j].to]]++;//Ð´³Éedge[i].toÁË..
            }

    memset(in,0,sizeof(in));
    int now;
    bool flag=0; //fuck fogot to set it to 0
    for(int n=0; n<fln; n++)
    {
        now=-1;
        for(int i=0; i<fln; i++)
        {
            if(in[i]) continue;
            if(indu[i]==0)
            {
                if(now!=-1)
                {
                    flag=1;
                    break;
                }
                now=i;
            }
        }
        in[now]=1;
        for(int i=0;i<(int)fls[now].size();i++)
        {
            for(int j=box[fls[now][i]];j!=-1;j=edge[j].next)
                if(fl[edge[j].to]!=now)
                    indu[fl[edge[j].to]]--;
        }
    }
    if(flag)
        printf("No\n");
    else printf("Yes\n");
}

void input()
{
    int f,t;
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    fln=0;
    time=1;
    top=-1;
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    memset(indu,0,sizeof(indu));  //Â©ÁË
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        work();
    }
    return 0;
}
