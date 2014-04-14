#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=12;
const int maxm=1000+10;

int dp[maxm][12][12];
int pj[maxm][12][12];
int pk[maxm][12][12];

int M;
bool has[maxn];
int ans[maxm];

int main()
{
    memset(has,0,sizeof(has));
    char ch;
    for(int i=1; i<=10; i++)
    {
        ch=getchar();
        if(ch==' '||ch=='\n')
        {
            i--;
            continue;
        }
        has[i]=ch=='1'?1:0;
    }
    scanf("%d",&M);
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<M;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
            {
                if(dp[i][j][k])
                {
                    for(int p=1;p<=10;p++)
                    {
                        if(has[p])
                        {
                            if(p>k&&p!=j)
                            {
                                dp[i+1][p][p-k]=1;
                                pj[i+1][p][p-k]=j;
                                pk[i+1][p][p-k]=k;
                            }
                        }
                    }
                }
            }
    int nj=0,nk,tj,tk;
    for(int j=1;j<=10;j++)
        for(int k=1;k<=10;k++)
        {
            if(dp[M][j][k])
            {
                nj=j;nk=k;
            }
        }
    if(!nj)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=M;i>0;i--)
    {
        ans[i]=nj;
        tj=pj[i][nj][nk];
        tk=pk[i][nj][nk];
        nj=tj;
        nk=tk;
    }
    printf("YES\n");
    printf("%d",ans[1]);
    for(int i=2;i<=M;i++)
    {
        printf(" %d",ans[i]);
    }
    puts("");
    return 0;
}
