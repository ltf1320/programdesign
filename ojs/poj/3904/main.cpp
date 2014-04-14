#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int N;
const int maxn=10000+100;
bool ispri[maxn];
int pri[maxn];
int prn;

int count[maxn];
int facn[maxn];

inline LL c4(LL n)
{
    if(n<4) return 0;
    return n*(n-1)*(n-2)*(n-3)/24;
}

void getPri(int n)
{
    for(int i=2;i<=n;i+=2)
        ispri[i]=1;
    pri[prn++]=2;
    for(int i=3;i<=n;i++)
    {
        if(!ispri[i])
        {
            pri[prn++]=i;
            for(int j=i;j<=n;j+=2*i)
                ispri[j]=1;
        }
        else ispri[i]=0;
    }
}

void getFac(int n)
{
    for(int i=2;i<=n;i++)
    {
        int now=i;
        for(int j=0;j<prn&&now!=1;j++)
        {
            if(now%pri[j]==0) facn[i]++;
            while(now%pri[j]==0)
            {
                now/=pri[j];
            }
        }
    }
}

int npri[maxn];
int nprn;
bool vis[maxn];
void dfs(int n,int now)
{
    if(n==nprn)
        return;
    dfs(n+1,now);
    now*=npri[n];
    if(!vis[now])
    count[now]++;
    vis[now]=1;
    dfs(n+1,now);
}

void getF(int n)
{
    nprn=0;
    for(int j=0;j<prn&&n!=1;j++)
    {
        if(n%pri[j]==0)
            npri[nprn++]=pri[j];
        while(n%pri[j]==0)
        {
            n/=pri[j];
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(0,1);
}

void input()
{
    int t;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&t);
        getF(t);
    }
}

void work()
{
    LL res=0;
    for(int i=2;i<=10000;i++)
    {
        if(facn[i]%2)
            res+=c4(count[i]);
        else res-=c4(count[i]);
    }
    printf("%I64d\n",c4(N)-res);
}

void init()
{
    memset(count,0,sizeof(count));
}

int main()
{
    freopen("in.txt","r",stdin);
    getPri(10000);
    getFac(10000);
    while(~scanf("%d",&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
