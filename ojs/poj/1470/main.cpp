#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1000;
int N,M;
bool vis[maxn];
int sum[maxn];
vector<int>son[maxn];
vector<int> que[maxn]; //每个点的查询
int indu[maxn];
int fa[maxn];

int find(int a)
{
    if(fa[a]!=a)
        return fa[a]=find(fa[a]);
    return a;
}

void skip()
{
    char ch=getchar();
    while(ch!=')'&&ch!='(')
        ch=getchar();
}

void tarjan(int n)
{
    for(size_t i=0;i<son[n].size();i++)
    {
        tarjan(son[n][i]);
        vis[son[n][i]]=1;
        fa[son[n][i]]=n;
    }
    for(size_t i=0;i<que[n].size();i++)
        if(vis[que[n][i]])
            sum[find(que[n][i])]++;
}

void init()
{
    for(int i=0;i<=N;i++)   fa[i]=i;
    memset(sum,0,sizeof(sum));
    memset(vis,0,sizeof(vis));
    memset(indu,0,sizeof(indu));
    for(int i=0;i<=N;i++)
        que[i].clear();
    for(int i=0;i<=N;i++)
        son[i].clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    int now,a,b,tmp;
    while(~scanf("%d",&N))
    {
        init();
        for(int i=0;i<N;i++)
        {
            scanf("%d",&now);
            skip();
            scanf("%d",&a);
            skip();
            for(int i=0;i<a;i++)
            {
                scanf("%d",&tmp);
                indu[tmp]++;
                son[now].push_back(tmp);
            }
        }
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            skip();
            scanf("%d %d",&a,&b);
            skip();
            que[a].push_back(b);
            que[b].push_back(a);
        }
        for(int i=1;i<=N;i++)
            if(!indu[i])
                tarjan(i);
        for(int i=1;i<=N;i++)
            if(sum[i])
                printf("%d:%d\n",i,sum[i]);
    }
    return 0;
}
