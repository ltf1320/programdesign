#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxm=12;
const int maxM=1100000;
int N,M;
int pp;
int dp[maxn][maxM];
int map[maxn][maxm];

int count(int st)
{
    int res=0;
    for(int i=0;i<M;i++)
        if(st&(1<<(i*2)))
            res++;
    return res;
}

void input()
{
    memset(map,0,sizeof(map));
    char ch;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%c",&ch);
            if(ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='P')
                map[i][j]=0;
        }
}

bool judge1(int n,int st)
{
    int nk=-3;
    for(int i=0;i<M;i++)
    {
        if(st&(1<<(i*2+1))) return false;
        if(st&(1<<(i*2)))
        {
            if(i-nk<3) return false;
            nk=i;
            if(st&(1<<(i*2+1)))
                return false;
            if(map[n][i])
                return false;
        }
    }
    return true;
}
int n;
bool judge(int st)
{
    int nk=-3;
    for(int i=0;i<M;i++)
    {
        if(st&(1<<(i*2)))
        {
            if(i-nk<3) return false;
            nk=i;
            if(st&(1<<(i*2+1)))
                return false;
            if(map[n][i])
                return false;
        }
    }
    return true;
}

void dfs(int i,int last,int now)
{
    if(i==M)
    {
        dp[n][now]=max(dp[n][now],dp[n-1][last]+count(now));
        return ;
    }
    if(!map[n][i]&&judge(now|(1<<(i*2))))
        dfs(i+1,last,now|(1<<(i*2)));
    if(!map[n-1][i]&&judge(last|(1<<(i*2)))&&judge(now|(1<<(i*2+1))))
        dfs(i+1,last|(1<<(i*2)),now|(1<<(i*2+1)));
    if(n>1&&!map[n-2][i]&&judge(last|(1<<(i*2+1))))
        dfs(i+1,last|(1<<(i*2+1)),now);
    dfs(i+1,last,now);
}

int work()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<pp;i++)
        if(judge1(0,i))
            dp[0][i]=count(i);
    for(n=1;n<N;n++)
    {
        dfs(n,0,0);
    }
    int res=0;
    for(int i=0;i<pp;i++)
        res=max(res,dp[N-1][i]);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        pp=(1<<(2*M));
        input();
        printf("%d\n",work());
    }
    return 0;
}
