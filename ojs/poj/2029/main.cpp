#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
int N,W,H,S,T;

bool Tree[maxn][maxn];
int sum[maxn][maxn];


int work()
{
    for(int i=1;i<=W;i++)
    {
        sum[i][0]=0;
        for(int j=1;j<=H;j++)
        {
            if(Tree[i][j]) sum[i][j]=sum[i][j-1]+1;
            else sum[i][j]=sum[i][j-1];
        }
    }
    int res=0;
    int tmp;
    for(int i=1;i<=W-S+1;i++)
        for(int j=0;j<=H-T+1;j++)
        {
            tmp=0;
            for(int k=0;k<S;k++)
                tmp+=sum[i+k][j+T]-sum[i+k][j];
            if(tmp>res)
                res=tmp;
        }
    return res;
}

void input()
{
    memset(Tree,0,sizeof(Tree));
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&W,&H);
    int x,y;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&x,&y);
        Tree[x][y]=1;
    }
    scanf("%d%d",&S,&T);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(!N) break;
        input();
        printf("%d\n",work());
    }
    return 0;
}
