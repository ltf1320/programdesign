#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=400+10;
char tab[maxn][maxn];
int sum[maxn][maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,M,K;
    int now,res=0;
    scanf("%d%d%d",&N,&M,&K);
    getchar();
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
            scanf("%c",&tab[i][j]);
        getchar();
    }
    memset(sum,0,sizeof(sum));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(tab[i][j]=='a')
                sum[i][j]=sum[i][j-1]+1;
            else sum[i][j]=sum[i][j-1];
        }
    }
    for(int k=1; k<=N; k++)
        for(int p=1; p<=M; p++)
        {
            for(int j=1;j<=M-p;j++)
            {
                now=0;
                for(int s=1;s<=k;s++)
                    now+=sum[s][j+p]-sum[s][j-1];
                for(int i=1;i<=N-k;i++)
                {
                    now+=sum[i+k][j+p]-sum[i+k][j-1];
                    now-=sum[i-1][j+p]-sum[i-1][j-1];
                    if(now<=K&&tab[i][j]==tab[i][j+p]&&tab[i][j]==tab[i+k][j]&&tab[i][j]==tab[i+k][j+p])
                        res++;
                }
            }
        }
    printf("%d\n",res);
    return 0;
}
