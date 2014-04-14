#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20+10;
int N;double p;
double dp[1<<21];
double pp[maxn];

void pre()
{
    double kp=1;
    for(int i=0;i<=N;i++)
    {
        pp[i]=1-kp;
        kp*=(1-p);
    }
}

int count(int st)
{
    int res=0;
    for(int i=0;i<N;i++)
        if(st&(1<<i))
            res++;
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int cnt,nxt;
    while(~scanf("%d%lf",&N,&p))
    {
        pre();
        memset(dp,0,sizeof(dp));
        dp[1]=1.0;
        for(int i=1;i<(1<<N);i++)
        {
            cnt=count(i);
            for(int j=0;j<N;j++)
            {
                if(!(i&(1<<j)))
                {
                    nxt=i|(1<<j);
                    dp[nxt]+=pp[cnt]*dp[i];
                }
            }
        }
        printf("%.5f\n",dp[(1<<N)-1]);
    }
    return 0;
}
