#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000;
int N;
int num[maxn];
int s[maxn];
int res[maxn];
int vis[maxn];
int lowbit(int a)
{
    return a&(-a);
}

int sum(int end)
{
    int res=0;
    for(;end>0;end-=lowbit(end))
        res+=s[end];
    return res;
}

void add(int n,int a)
{
    for(;n<=N;n+=lowbit(n))
        s[n]+=a;
}

int bsch(int a)
{
    int l=0,r=N+1;
    int m,tmp;
    while(l<r)
    {
        m=(l+r)>>1;
        tmp=m-sum(m);
        if(tmp==a&&!vis[m]) return m;
        if(tmp<a)
            l=m+1;
        else r=m;
    }
    return l;
}

int main()
{
    int now;
    scanf("%d",&N);
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<N;i++)
        scanf("%d",&num[i]);
    for(int i=N-1;i>=0;i--)
    {
        now=bsch(num[i]+1);
        res[i]=now;
        add(now,1);
        vis[now]=1;
    }
    for(int i=0;i<N;i++)
        printf("%d\n",res[i]);
    return 0;
}
