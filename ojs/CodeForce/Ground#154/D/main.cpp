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
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
            scanf("%c",&tab[i][j]);
        getchar();
    }
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(tab[i][j]=='a')
                sum[i][j]=sum[i][j-1]+1;
            else sum[i][j]=sum[i][j-1];
        }
    }
    for(int i=1;i<N;i++)
        for(int j=1;j<M;j++)
            for(int k=1;k<=N-i;k++)
                for(int p=1;p<=M-j;p++)
                {
                    if(tab[i][j]==tab[i][j+p]&&tab[i][j]==tab[i+k][j]&&tab[i][j]==tab[i+k][j+p])
                    {
                        now=0;
                        for(int l=i;l<=i+k;l++)
                            now+=sum[l][j+p]-sum[l][j-1];  //!!!
                        if(now<=K)
                            res++;
                    }
                }
    printf("%d\n",res);
    return 0;
}
