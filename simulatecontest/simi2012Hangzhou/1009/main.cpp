#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=50;
int N,M;
char map[maxn][maxn];

int mabs(int a)
{
    return a>0?a:-a;
}

int main()
{
    freopen("in.txt","r",stdin);
    int hx,hy,cx,cy;
    int res;
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        res=inf;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='\n'||map[i][j]==' ')
                {
                    j--;
                    continue;
                }
            }
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(map[i][j]=='H')
                {
                    for(int x=max(0,i-res); x<=min(N-1,i+res); x++)
                        for(int y=max(0,j-res); y<=min(M-1,j+res); y++)
                        {
                            if(map[x][y]=='C')
                            {
                                if(mabs(i-x)+mabs(j-y)<res)
                                {
                                    res=mabs(i-x)+mabs(j-y);
                                    hx=i;hy=j;
                                    cx=x;cy=y;
                                }
                            }
                        }
                }
            }
        printf("%d %d %d %d\n",hx,hy,cx,cy);
    }
    return 0;
}
