#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxc=15+2;
const int inf=0x3f3f3f3f;
int M;
struct Rec
{
    int x1,x2,y1,y2,col;
};
Rec recs[maxc];

int up[maxc][maxc];
int upn[maxc];
int down[maxc][maxc];
int dn[maxc];
int mc;
int dp[1<<maxc][maxc];

bool canp(int state,int k)
{
    for(int i=0;i<upn[k];i++)
        if(!(state&(1<<up[k][i]))) return false;
    for(int i=0;i<dn[k];i++)
        if(state&(1<<down[k][i])) return false;
    return true;
}

int work()
{
    for(int i=0;i<(1<<M)-1;i++)
        for(int j=0;j<=mc;j++)
            dp[i][j]=inf;
    memset(dp[0],0,sizeof(dp[0]));
    int t;
    for(int i=0;i<(1<<M)-1;i++)
        for(int j=1;j<=mc;j++)
        {
            for(int k=0;k<M;k++)
            {
                if(canp(i,k))
                {
                    t=i|(1<<k);
                    if(t==31)
                        t=31;
                    if(recs[k].col==j)
                        dp[t][recs[k].col]=min(dp[t][recs[k].col],dp[i][j]);
                    else dp[t][recs[k].col]=min(dp[t][recs[k].col],dp[i][j]+1);
                }
            }
        }
    int res=inf;
    for(int i=0;i<mc;i++)
        if(dp[(1<<M)-1][i]<res) res=dp[(1<<M)-1][i];
    return res+1;
}

void input()
{
    mc=0;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d%d%d",&recs[i].y1,&recs[i].x1,&recs[i].y2,&recs[i].x2,&recs[i].col);
        if(recs[i].col>mc) mc=recs[i].col;
    }
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
        {
            if(i==j) continue;
            if(recs[i].x1<recs[j].x2&&recs[i].x2>recs[j].x1&&recs[i].y2<=recs[j].y1)
            {
                down[i][dn[i]++]=j;
                up[j][upn[j]++]=i;
            }
        }
}

void init()
{
    memset(dn,0,sizeof(upn));
    memset(upn,0,sizeof(upn));
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
