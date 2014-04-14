#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200000+100;
int N;

int num[maxn];
int has[maxn];//²¢²é¼¯
int fa[maxn];
int dp[maxn];

int find(int now)
{
    if(fa[now]==now)
    {
        if(has[now+1])
        {
            fa[now]=find(now+1);
            return fa[now];
        }
        else return now;
    }
    fa[now]=find(fa[now]);
    return fa[now];
}

void work()
{
    int nsum=0;
    int res=0;
    int up;
    for(int i=N; i>0; i--)
    {
        if(dp[num[i]])
        {
            up=find(num[i]);
            dp[up+1]+=dp[num[i]];
            nsum+=(up+1-num[i])*dp[num[i]];
            dp[num[i]]=0;
        }
        if(num[i]==0)
        {
            dp[1]++;
            nsum+=1;
        }
        else dp[0]++;
        has[num[i]]=1;
        res+=nsum;
    }
    printf("%d\n",res);
}

void input()
{
    for(int i=1; i<=N; i++)
        scanf("%d",&num[i]);
}

void init()
{
    memset(num,0,sizeof(num));
    for(int i=0; i<=N; i++)
        fa[i]=i;
    memset(dp,0,sizeof(dp));
    memset(has,0,sizeof(has));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        init();
        input();
        work();
    }
    return 0;
}
