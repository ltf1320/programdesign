#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50000+100;

int N,K;

int fa[maxn];
int ch[maxn];

int find(int now)
{
    if(fa[now]==-1) return now;
    int t=find(fa[now]);
    ch[now]=(ch[now]+ch[fa[now]])%3;
    fa[now]=t;
    return fa[now];
}
int res=0;
void check(int x,int y,int d)
{
    if(x>N||y>N)
    {
        res++;return;
    }
    int xx=find(x),yy=find(y);
    if(xx==yy)
    {
        if((ch[x]-ch[y]+3)%3!=d)
        {
            res++;
        }
    }
    else
    {
        fa[xx]=yy;
        ch[xx]=(ch[y]-ch[x]+d+3)%3;
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    int x,y,d;
    memset(fa,-1,sizeof(fa));
    memset(ch,0,sizeof(ch));
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d%d%d",&d,&x,&y);
        check(x,y,d-1);
    }
    printf("%d\n",res);
    return 0;
}
