#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=20000+10;
const int inf=0x3f3f3f3f;

int N;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int R[2*maxn];
int box[maxn];
int ent;
int res,resn;
void add(int a,int b)
{
    edge[ent].to=b;
    edge[ent].next=box[a];
    box[a]=ent++;
}

int dfs(int now,int from)
{
    int b=1,fe=-1;
    int rr=0;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from)
        {
            fe=i;
            continue;
        }
        R[i]=dfs(edge[i].to,now);
        b+=R[i];
        rr=max(rr,R[i]);
    }
    if(~fe)
    {
        R[fe]=N-b;
        rr=max(rr,R[fe]);
    }
    if(rr<res)
    {
        res=rr;
        resn=now;
    }
    if(res==rr)
        resn=min(resn,now);
    return b;
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    res=inf;
}

int main()
{
    int T,f,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
        for(int i=0;i<N-1;i++)
        {
            scanf("%d%d",&f,&t);
            add(f,t);
            add(t,f);
        }
        dfs(1,-1);
        printf("%d %d\n",resn,res);
    }
    return 0;
}
