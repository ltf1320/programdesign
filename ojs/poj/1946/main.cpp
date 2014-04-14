#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=20+2;
const int maxd=100+10;
const int inf=0x3f3f3f3f;

int N,D,E;
int dp[maxn][maxd];
int det[maxd][maxd];

inline int getTime(int d,int v)
{
    return (int)ceil(1.0*d/v);
}

void pre()
{
    for(int i=0; i<=D; i++)
        det[0][i]=0;
    for(int d=1; d<=D; d++)
        for(int e=0; e<=E; e++)
        {
            det[d][e]=inf;
            if(d==e)
            {
                det[d][e]=e;
                continue;
            }
            for(int v=1; v*v<=e; v++)
            {
   //             if(getTime(d,v)*v*v<=e&&getTime(d,v)*v<=d)
   //                 det[d][e]=min(det[d][e],getTime(d,v)+det[d-getTime(d,v)*v][e-getTime(d,v)*v*v]);
                if(v*v<=e&&v<=d)
                    det[d][e]=min(det[d][e],1+det[d-v][e-v*v]);

            }
        }
    /*
        for(int d=1;d<=D;d++)
        {
    for(int e=0;e<=E;e++)
    {
        printf("%d ",det[d][e]);
    }
    putchar('\n');
        }
        */
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&E,&D))
    {
        pre();
        for(int d=0; d<=D; d++)
        {
            dp[0][d]=det[d][E];
        }
        for(int i=1; i<N; i++)
        {
            for(int d=0; d<=D; d++)
            {
                dp[i][d]=inf;
                for(int j=0; j<=min(d,E); j++)
                {
                    dp[i][d]=min(dp[i][d],det[d-j][E-j]+dp[i-1][j]);
                }
            }
        }
        /*
        for(int i=0; i<N; i++)
        {
            for(int d=0; d<=D; d++)
            {
                printf("%d ",dp[i][d]);
            }
            putchar('\n');
        }
        */
        if(dp[N-1][D]!=inf)
            printf("%d\n",dp[N-1][D]);
        else printf("-1\n");
    }
    return 0;
}
