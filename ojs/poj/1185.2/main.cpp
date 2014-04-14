#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxm=70;
int N,M;
int dp[maxn][maxm][maxm];

int state[maxm];
int stp;
int map[maxn];


bool judge(int x)
{
    if(x&(x<<1)) return false;
    if(x&(x<<2)) return false;
    return true;
}

void pre()
{
    stp=0;
    for(int i=0;i<(1<<M);i++)
    {
        if(judge(i))
            state[stp++]=i;
    }
}

void input()
{
    char ch;
    memset(map,0,sizeof(map));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%c",&ch);
            if(ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='H')
                map[i]+=(1<<j);
        }
}

int count(int st)
{
    int res=0;
    for(int i=0;i<M;i++)
    {
        if(st&(1<<i))
            res++;
    }
    return res;
}

int work()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<stp;i++)
    {
        if(!(map[0]&state[i]))
            dp[0][i][0]=count(state[i]);
    }
    for(int n=1;n<N;n++)
        for(int i=0;i<stp;i++)
        {
            if(map[n]&state[i]) continue;
            for(int j=0;j<stp;j++)
            {
                if(map[n-1]&state[j]) continue;
                if(n==1)
                {
                    if(!(state[i]&state[j]))
                        dp[n][i][j]=max(dp[n][i][j],dp[n-1][j][0]+count(state[i]));
                }
                for(int k=0;k<stp;k++)
                {
                    if(!(state[i]&state[j])&&!(state[i]&state[k]))
                        dp[n][i][j]=max(dp[n][i][j],dp[n-1][j][k]+count(state[i]));
                }
                i++;
                i--;
            }
        }
    /*
    for(int i=0;i<stp;i++)
        printf("%d ",state[i]);
    putchar('\n');
    for(int n=0;n<N;n++)
    {
        for(int i=0;i<stp;i++)
        {
            for(int j=0;j<stp;j++)
            {
                printf("%d ",dp[n][i][j]);
            }
            putchar(' ');
        }
        putchar('\n');
    }

    */
    int res=0;
    for(int i=0;i<stp;i++)
        for(int j=0;j<stp;j++)
            res=max(res,dp[N-1][i][j]);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        pre();
        input();
        printf("%d\n",work());
    }
    return 0;
}
