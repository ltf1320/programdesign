#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000;
int N,M;
int map[maxn][maxn];
int pr[maxn][maxn];
int pc[maxn][maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int res,dmax,dn;
    while(~scanf("%d%d",&N,&M))
    {
        memset(map,-1,sizeof(map));
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                if(map[i][j]==map[i][j-1])
                    pr[i][j]=pr[i][j-1]+1;
                else pr[i][j]=1;
        for(int j=1; j<=M; j++)
            for(int i=1; i<=N; i++)
                if(map[i][j]==map[i-1][j])
                    pc[i][j]=pc[i-1][j]+1;
                else pc[i][j]=1;
        res=0;
        for(int i=1; i<=N; i++)
        {
            dmax=maxn;
            for(int j=1; j<=M; j++)
            {
                if(map[i][j]==map[i][j-1])
                {
                    dmax=min(dmax,pc[i][j]);
                    dn++;
                }
                else
                {
                    dmax=pc[i][j];
                    dn=1;
                }
                res=max(res,dmax*dn);
            }
        }
        for(int j=1; j<=M; j++)
        {
            dmax=maxn;
            for(int i=1; i<=N; i++)
            {
                if(map[i][j]==map[i-1][j])
                {
                    dmax=min(dmax,pr[i][j]);
                    dn++;
                }
                else
                {
                    dmax=pr[i][j];
                    dn=1;
                }
                res=max(res,dmax*dn);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
