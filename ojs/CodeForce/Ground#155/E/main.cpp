#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=400+1;
int N,V,M;
int a[maxn];
int dp[maxn][2*maxn];
int pre[maxn][2*maxn];
int restk[maxn][maxn];
struct FRE
{
    int l,r,f,code;
    bool operator<(const FRE &a) const
    {
        return f<a.f;
    }
};
FRE fres[maxn];

void input()
{
    scanf("%d%d",&N,&V);
    for(int i=1; i<=N; i++)
        scanf("%d",&a[i]);
    scanf("%d",&M);
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d%d",&fres[i].l,&fres[i].r,&fres[i].f);
        fres[i].code=i;
    }
    sort(fres+1,fres+M+1); //!!
}

void work()
{
    int now,mx,d,nm;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<=a[i-1]; j++)
        {
            if(dp[i-1][j]!=-1)
            {
                now=j+a[i]-V;
                nm=dp[i-1][j];
                if(nm>dp[i][now])
                {
                    dp[i][now]=nm;
                    pre[i][now]=j;
                }
                for(int k=1; k<=M; k++)
                {
                    if(fres[k].f>now) break;
                    if(fres[k].l<=i&&fres[k].r>=i)
                    {
                        nm++;
                        if(dp[i][now-fres[k].f]<nm)
                        {
                            dp[i][now-fres[k].f]=nm;
                            pre[i][now-fres[k].f]=j;
                        }
                        now=now-fres[k].f;
                    }
                }
            }
        }
        for(int k=a[i]+1;k<=a[i]+a[i-1];k++)
        {
            if(dp[i][k]!=-1)
            {
                if(dp[i][a[i]]<dp[i][k])
                {
                    dp[i][a[i]]=dp[i][k];
                    pre[i][a[i]]=pre[i][k];//!!!
                }
                dp[i][k]=-1;
            }
        }
    }
    /*
    for(int i=1;i<=N;i++)
    {
        printf("%d ",dp[i][a[i]]);
        putchar('\n');
    }
    */
    now=0;
    mx=0;
    for(int i=0; i<maxn; i++)
        if(dp[N][i]>now)
        {
            mx=i;
            now=dp[N][i];
        }
    printf("%d\n",now);
    now=mx;
    for(int i=N; i; i--)
    {
        d=dp[i][now]-dp[i-1][pre[i][now]];
        for(int k=1; k<=M; k++)
        {
            if(d==restk[i][0]) break;
            if(fres[k].l<=i&&fres[k].r>=i)
                restk[i][++restk[i][0]]=fres[k].code;
        }
        now=pre[i][now];
    }
    for(int i=1; i<=N; i++)
    {
 //       if(restk[i][0])  //!!!
        {
            printf("%d",restk[i][0]);
            for(int j=1; j<=restk[i][0]; j++)
                printf(" %d",restk[i][j]);
            putchar('\n');
        }
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    work();
    return 0;
}
