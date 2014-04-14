#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=220;

struct EDGE
{
    int next,to,f;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void add(int from,int to,int f)
{
    edge[ent].to=to;
    edge[ent].f=f;
    edge[ent].next=box[from];
    box[from]=ent++;
}

int level[maxn];

bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    level[s]=1;
    int que[maxn];
    int iq=0;
    que[iq++]=s;
    int i,k;
    int top;
    for(i=0;i<iq;++i)
    {
        top=que[i];
        if(top==t) return true;
        for(k=box[top];k!=-1;k=edge[k].next)
        {
            if(!level[edge[k].to] && edge[k].f)
            {
                que[iq++]=edge[k].to;
                level[edge[k].to]=level[top]+1;
            }
        }
    }
    return false;
}

int DFS(int now,int maxf,int t)
{
    if(now==t) return maxf;
    int ret=0,f;
    int k;
    for(k=box[now];k!=-1;k=edge[k].next)
    {
        if(edge[k].f && level[edge[k].to]==level[now]+1)
        {
            f=DFS(edge[k].to,min(maxf,edge[k].f),t);
            edge[k].f-=f;
            edge[k^1].f+=f;
            ret+=f;
            if(ret==maxf) return ret;
        }
    }
    return ret;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    int from,to,f;
    int res;
    while(~scanf("%d%d",&n,&m))
    {
        ent=0;
        memset(box,-1,sizeof(box));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&from,&to,&f);
            add(from,to,f);
            add(to,from,0);
        }
        res=0;
        while(makelevel(1,m)) res+=DFS(1,INF,m);
        printf("%d\n",res);
    }
    return 0;
}
