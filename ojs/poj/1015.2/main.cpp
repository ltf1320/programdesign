#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MID M*maxm
using namespace std;
const int maxn=200+10;
const int maxm=20+5;
int N,M;
int cas=1;
int ps[maxn];
int ds[maxn];

int abs(int a){return a>0?a:-a;}

struct Node
{
    bool chosed[maxn];
    int p,d;
    bool vis;
    void reset()
    {
        for(int i=0;i<=N;i++) chosed[i]=0;
        p=d=0;
        vis=0;
    }
    void update(const Node &from,int next)
    {
        if((p+d<from.p+from.d+ps[next]+ds[next])||!vis)
        {
            vis=1;
            for(int i=1;i<=N;i++)
                chosed[i]=from.chosed[i];
            chosed[next]=1;
            p=from.p+ps[next];
            d=from.d+ds[next];
        }
    }
};

Node dp[maxm][2*maxm*maxm];

void work()
{
    int state;
    dp[0][MID].vis=1;
    for(int i=0;i<M;i++)
    {
        for(int j=MID-i*maxm;j<=MID+i*maxm;j++)
        {
            if(dp[i][j].vis)
            {
                for(int k=1;k<=N;k++)
                {
                    if(!dp[i][j].chosed[k])
                    {
                        state=dp[i][j].p+ps[k]-dp[i][j].d-ds[k]+MID;
                        dp[i+1][state].update(dp[i][j],k);
                    }
                }
            }
        }
    }
    int res=-1;
    for(int i=0;i<=MID;i++) //!
        if(dp[M][MID+i].vis||dp[M][MID-i].vis)
        {
            if(!dp[M][MID-i].vis)
                res=MID+i;
            else if(!dp[M][MID+i].vis)
                res=MID-i;
            else
            {
                if(dp[M][MID+i].p+dp[M][MID+i].d>dp[M][MID-i].p+dp[M][MID-i].d)
                    res=MID+i;
                else res=MID-i;

            }
            break;
        }
    printf("Jury #%d\n",cas++);
    printf("Best jury has value %d for prosecution and value %d for defence:\n",dp[M][res].p,dp[M][res].d);
    for(int i=1;i<=N;i++)
    {
        if(dp[M][res].chosed[i])
        {
            printf(" %d",i);
        }
    }
    printf("\n\n");
}

void init()
{
    for(int i=0; i<=M; i++)
        for(int j=0; j<=2*maxm*maxm; j++)
            dp[i][j].reset();
}
void input()
{
    char tmp[maxn];
    gets(tmp);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d",&ps[i],&ds[i]);
        gets(tmp);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        init();
        input();
        work();
    }
    return 0;
}
