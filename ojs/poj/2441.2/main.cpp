#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=22;
int N,M;
int res;
vector<int> cs[maxn];
int dp[2][1<<20];

int count(int st)
{
    int res=0;
    while(st)
    {
        res+=st&1;
        st>>=1;
    }
    return res;
}

void work()
{
    dp[0][0]=1;
    for(int k=0; k<N; k++)
    {
        memset(dp[(k+1)&1],0,sizeof(dp[0]));
        for(int st=0; st<(1<<M); st++)
        {
            if(dp[k&1][st])
            for(int i=0; i<(int)cs[k].size(); i++)
            {
                if(!(st&(1<<cs[k][i])))
                {
                    dp[(k+1)&1][st|(1<<cs[k][i])]+=dp[k&1][st];
                }
            }
        }
    }
    res=0;
    for(int st=0;st<(1<<M);st++)
    {
        if(count(st)==N)
        {
            res+=dp[N&1][st];
        }
    }
    printf("%d\n",res);
}

void input()
{
    int t,k;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&t);
        for(int j=0; j<t; j++)
        {
            scanf("%d",&k);
            cs[i].push_back(k-1);
        }
    }
}

void init()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++)
        cs[i].clear();
}

int main()
{
  //  freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
