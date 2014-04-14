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
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
            if(tab[i][j]=='a') su[i][j]++;
        }
    }
    for(int i=1;i<=N;i++)
    printf("%d\n",res);
    return 0;
}
