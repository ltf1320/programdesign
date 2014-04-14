#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=105;
const int inf=0x3f3f3f3f;

int m,n;
int lowestLever;
bool exlev[maxn];
int levs[maxn];

struct EDGE
{
    int to,next;
    int v;
};
EDGE edge[maxn];
int box[maxn];
int ctn;
void add(int from,int to,int vv)
{
    edge[ctn].to=to;
    edge[ctn].v=vv;
    edge[ctn].next=box[from];
    box[from]=ctn++;
}
int lowl;
int dfs(int n,int mon)
{
    if(n==1) return mon;
    int res=inf;
    int tmp;
    for(int i=box[n];i!=-1;i=edge[i].next)
    {
        if(levs[edge[i].to]>lowl+m) continue;
        if(levs[edge[i].to]<lowl)
        {
            int tmpl=lowl;
            lowl=levs[edge[i].to];
            tmp=dfs(edge[i].to,mon+edge[i].v);
            lowl=tmpl;
        }
        else tmp=dfs(edge[i].to,mon+edge[i].v);
        if(tmp<res) res=tmp;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(box,-1,sizeof(box));
    memset(exlev,0,sizeof(exlev));
    ctn=0;
    scanf("%d%d",&m,&n);
    int P,L,X;
    int t,yh;
    int maxlever=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&P,&L,&X);
        if(L>maxlever) maxlever=L;
        levs[i]=L;
        exlev[L]=1;
        add(0,i,P);
        for(int j=0;j<X;j++)
        {
            scanf("%d%d",&t,&yh);
            add(t,i,yh);
        }
    }
    lowl=inf;
    printf("%d\n",dfs(0,0));
    return 0;
}
