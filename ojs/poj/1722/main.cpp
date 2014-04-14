#include <iostream>
#include <cstdio>
#include <cstring>
#define MID N*100
using namespace std;
const int maxn=100+10;
const int maxk=10000*2+100;
int dp[maxn][maxk];
int sq[maxn];
int path[maxn];
int N,T;

int main()
{
    freopen("in.txt","r",stdin);
    int state;
    scanf("%d%d",&N,&T);
    for(int i=1;i<=N;i++)
        scanf("%d",&sq[i]);
    memset(dp,0,sizeof(dp));
    dp[1][sq[1]+MID]=1;
    dp[2][sq[1]-sq[2]+MID]=1;
    for(int i=2;i<N;i++)
    {
        for(int j=MID-i*100;j<=MID+i*100;j++)
        {
            if(dp[i][j])
            {
                dp[i+1][j-sq[i+1]]=1;
                dp[i+1][j+sq[i+1]]=2;
            }
        }
    }
    state=MID+T;
    for(int i=N;i>1;i--)
    {
        path[i]=dp[i][state];
        if(dp[i][state]==1)
            state+=sq[i];
        else state-=sq[i];
    }
    int k=0;
    for(int i=2;i<=N;i++)
        if(path[i]==2)
        {
            printf("%d\n",i-1-k);
            k++;
        }
    for(int i=2;i<=N;i++)
        if(path[i]==1)
            printf("%d\n",1);
    return 0;
}
