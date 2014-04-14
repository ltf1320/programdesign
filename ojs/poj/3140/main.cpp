#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+10;
const int maxm=1000000+100;
int N,M;
int p[maxn];
struct EDGE
{
    int next,to;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;
LL sum;
LL dp[maxm];

LL abs(LL a)
{
    return a>0?a:-a;
}

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

LL dfs(int now,int from)
{
    LL res=p[now];
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        dp[i/2]=dfs(edge[i].to,now);
        res+=dp[i/2];
    }
    return res;
}

LL work()
{
    LL res=sum;
    dfs(1,-1);
    for(int i=0;i<M;i++)
    {
        if(abs(sum-2*dp[i])<res)
            res=abs(sum-2*dp[i]);
    }
    return res;
}
void input()
{
    int f,t;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&p[i]);
        sum+=p[i];
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    sum=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%d%d",&N,&M),N&&M)
    {
        cas++;
        init();
        input();
        printf("Case %d: %I64d\n",cas,work());
    }
    return 0;
}
