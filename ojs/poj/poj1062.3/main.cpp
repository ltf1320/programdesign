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


int map[maxn][maxn];

void add(int from,int to,int v)
{

}

int lowl;
int dfs(int n,int mon)
{
    if(n==1) return mon;
    int res=inf;
    int tmp;
    for(int i=0;i<=n;i++)
    {
        if(!map[n][i]) continue;
        if(levs[i]>lowl+m) continue;
        if(levs[i]<lowl)
        {
            int tmpl=lowl;
            lowl=levs[i];
            tmp=dfs(i,mon+map[n][i]);
            lowl=tmpl;
        }
        else tmp=dfs(i,mon+map[n][i]);
        if(tmp<res) res=tmp;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(exlev,0,sizeof(exlev));
    memset(map,0,sizeof(map));
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
        map[0][i]=P;
        for(int j=0;j<X;j++)
        {
            scanf("%d%d",&t,&yh);
            map[t][i]=yh;
        }
    }
    lowl=inf;
    printf("%d\n",dfs(0,0));
    return 0;
}
