#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int N,M,K;
bool map[maxn][maxn];
bool bel[maxn][maxn];



int find(int x,int y)
{
    bel[x][y]=1;
    int kx,ky;
    int res=1;
    for(int i=0;i<4;i++)
    {
        kx=x+dx[i];
        ky=y+dy[i];
        if(kx>=1&&kx<=N&&ky>=1&&ky<=M)
        {
            if(map[kx][ky]&&!bel[kx][ky])
            {
                res+=find(kx,ky);
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    int x,y;
    for(int i=0;i<K;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
    }
    int res=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(map[i][j]&&!bel[i][j])
            {
                res=max(res,find(i,j));
            }
        }
    printf("%d\n",res);
    return 0;
}
