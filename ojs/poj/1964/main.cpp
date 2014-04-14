#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
bool map[maxn][maxn];
int N,M;
struct Node
{
    int maxx,my;
    int maxy,mx;
    int dx,dy;
    int maxf;
    void reset()
    {
        maxx=my=maxy=mx=dx=dy=maxf=0;
    }
};
Node dp[maxn][maxn];

void input()
{
    memset(map,0,sizeof(map));
    char ch;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            scanf("%c",&ch);
            if(ch=='R')
                map[i][j]=0;
            else if(ch=='F')
                map[i][j]=1;
            else
            {
                j--;
                continue;
            }
        }
}

int work()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=M;j++)
            dp[i][j].reset();
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(!map[i][j]) continue;
            dp[i][j].maxx=dp[i-1][j].maxx+1;
            if(dp[i][j-1].maxx>dp[i-1][j].maxx)
                dp[i][j].my=dp[i][j-1].my+1;
            else dp[i][j].my=1;

            dp[i][j].maxy=dp[i][j-1].maxy+1;
            if(dp[i-1][j].maxy>dp[i][j-1].maxy)
                dp[i][j].mx=dp[i-1][j].mx+1;
            else dp[i][j].mx=1;

            dp[i][j].maxf=dp[i][j].maxx*dp[i][j].my;
            dp[i][j].dx=dp[i][j].maxx;
            dp[i][j].dy=dp[i][j].my;

            if(dp[i][j].maxy*dp[i][j].mx>dp[i][j].maxf)
            {
                dp[i][j].maxf=dp[i][j].maxy*dp[i][j].mx;
                dp[i][j].dx=dp[i][j].maxy;
                dp[i][j].dy=dp[i][j].mx;
            }

            if(dp[i][j].maxx>dp[i-1][j-1].dx&&dp[i][j].maxy>dp[i-1][j-1].dy)
            {
                if((dp[i-1][j-1].dx+1)*(dp[i-1][j-1].dy+1)>dp[i][j].maxf)
                {
                    dp[i][j].maxf=(dp[i-1][j-1].dx+1)*(dp[i-1][j-1].dy+1);
                    dp[i][j].dx=dp[i-1][j-1].dx+1;
                    dp[i][j].dy=dp[i-1][j-1].dy+1;
                }
            }
            /*
            if(dp[i][j].maxx>dp[i-1][j-1].maxx&&dp[i][j-1].maxx>dp[i-1][j-1].maxx)
            {
                if((dp[i][j-1].my+1)*(dp[i-1][j-1].maxx+1)>dp[i][j].maxf)
                {
                    dp[i][j].maxf=(dp[i][j-1].my+1)*(dp[i-1][j-1].maxx+1);
                    dp[i][j].dx=(dp[i-1][j-1].maxx+1);
                    dp[i][j].dy=(dp[i][j-1].my+1);
                }
            }

            if(dp[i][j].maxy>dp[i-1][j-1].maxy&&dp[i-1][j].maxy>dp[i-1][j-1].maxy)
            {
                if((dp[i-1][j].mx+1)*(dp[i-1][j-1].maxy+1)>dp[i][j].maxf)
                {
                    dp[i][j].maxf=(dp[i-1][j].mx+1)*(dp[i-1][j-1].maxy+1);
                    dp[i][j].dx=(dp[i-1][j].mx+1);
                    dp[i][j].dy=(dp[i-1][j-1].maxy+1);
                }
            }
            */
        }
    int res=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(dp[i][j].maxf>res)
                res=dp[i][j].maxf;
    return res*3;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        input();
        printf("%d\n",work());
    }
    return 0;
}
