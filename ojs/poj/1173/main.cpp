#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30+10;

int dp[maxn][maxn];
int N,M,K;
char ss[maxn];
void pre()
{
    memset(dp,0,sizeof(dp));
    for(int n=1; n<=M; n++)
        dp[n][1]=1;
    for(int k=2; k<=K; k++)
    {
        for(int n=1; n<=N; n++)
        {
            dp[n][k]=0;
            for(int i=1;i<=M&&i<n;i++)
                dp[n][k]+=dp[n-i][k-1];
        }
    }
    /*
    for(int n=1; n<=N; n++)
    {
        for(int k=1; k<=K; k++)
        {
            printf("%d ",dp[n][k]);
        }
        puts("");
    }
    */
}
int vec[maxn];
void getvecs(char *s)
{
    int now;
    int p=0;
    memset(vec,0,sizeof(vec));
    for(int i=0;i<N;)
    {
        now=s[i++];
        vec[p]=1;
        while(now==s[i])
        {
            i++;
            vec[p]++;
        }
        p++;
    }
}

int getC(char *s)
{
    getvecs(s);
    int res=0;
    int last=N;
    for(int i=0; i<K; i++)
    {
        if(i%2==0)
        {
            for(int j=1;j<vec[i];j++)
            {
                if(last>=j)
                {
                    res+=dp[last-j][K-i-1];
                }
            }
        }
        else
        {
            for(int j=vec[i]+1;j<=M;j++)
            {
                if(last>=j)
                    res+=dp[last-j][K-i-1];
            }
        }
        last-=vec[i];
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&K,&M);
    pre();
    int q;
    printf("%d\n",dp[N][K]);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%s",ss);
        printf("%d\n",getC(ss));
    }
    return 0;
}
