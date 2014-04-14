#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20;
int N;
int dp[1<<maxn];
int map[maxn][maxn];

int goNext(int st)
{
    int tmp=7<<N;
    tmp=tmp&st;
    tmp<<=1;
    tmp&=7<<N;
    for(int i=0; i<3; i++)
        st&=(-1)^(1<<(N+i));
    st^=tmp;
    return st;
}

int out1(int st)
{
    if(st&(1<<(N+3)))
        st^=(1<<(N+3))+(1<<(N+4));
    else st|=(1<<(N+3));
    return st;
}

bool end(int st)
{
    if((st&(1<<(N+3)))&&(st&(1<<(N+4))))
        return 1;
    return 0;
}

int count(int st)
{
    int ct=0;
    for(int i=0;i<N;i++)
    {
        if(st&(1<<i))
            ct++;
    }
    return ct;
}

int main()
{
    freopen("in.txt","r",stdin);
    int nxt,sc,res;
    while(~scanf("%d",&N)&&N)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                scanf("%d",&map[i][j]);
            }
        dp[0]=0;
        for(int j=0; j<1<<(N+5); j++)
        {
            if(dp[j]==-1) continue;
            for(int k=0; k<N; k++)
            {
                if(!(j&(1<<k)))
                {
                    switch(map[k][count(j)])
                    {
                    case 0:
                        nxt=out1(j);
                        if(end(nxt)) continue;
                        nxt|=(1<<k);
                        dp[nxt]=max(dp[j],dp[nxt]);
                        break;
                    case 1:
                        sc=j&(1<<(N+2))?1:0;
                        nxt=out1(j);
                        if(end(nxt)) continue;
                        nxt=goNext(nxt);
                        nxt|=(1<<k);
                        dp[nxt]=max(dp[j]+sc,dp[nxt]);
                        break;
                    case 2:
                        sc=j&(1<<(N+2))?1:0;
                        nxt=goNext(j);
                        nxt|=1<<N;//run to first base
                        nxt|=(1<<k);
                        dp[nxt]=max(dp[j]+sc,dp[nxt]);
                        break;
                    case 3:
                        sc=1;
                        for(int p=0; p<3; p++)
                            if(j&(1<<(N+p)))
                                sc++;
                        nxt=j;
                        for(int p=0; p<3; p++) //all the base are clear
                            nxt&=(-1)^(1<<(N+p));
                        nxt|=(1<<k);
                        dp[nxt]=max(dp[j]+sc,dp[nxt]);
                        break;
                    }
                }
            }
        }
        res=0;
        for(int i=0;i<(1<<(N+5));i++)
            res=max(res,dp[i]);
        printf("%d\n",res);
    }
    return 0;
}
