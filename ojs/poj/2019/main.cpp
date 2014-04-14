#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=250+10;
const int inf=0x3f3f3f3f;
int N,B,K;

int corn[maxn][maxn];
int dpmx[maxn][maxn][20];
int dpmn[maxn][maxn][20];
int p2[20];
int res[maxn][maxn];

int find2(int n)
{
    return log(1.0*n)/log(2.0);
}

void RMQ()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            dpmn[i][j][0]=dpmx[i][j][0]=corn[i][j];
        for(int j=1;p2[j]<=N;j++)
            for(int k=1;k<=N-p2[j-1];k++)
            {
                dpmx[i][k][j]=max(dpmx[i][k][j-1],dpmx[i][k+p2[j-1]][j-1]);
                dpmn[i][k][j]=min(dpmn[i][k][j-1],dpmn[i][k+p2[j-1]][j-1]);
            }
    }
}

int query(int r,int c)
{
    if(res[r][c]!=-1) return res[r][c];
    int pp;
    int mx=0,mn=inf;
    for(int i=r;i<r+B;i++)
    {
        pp=find2(B);
        mx=max(mx,max(dpmx[i][c][pp],dpmx[i][c+B-p2[pp]][pp]));
        mn=min(mn,min(dpmn[i][c][pp],dpmn[i][c+B-p2[pp]][pp]));
    }
    res[r][c]=mx-mn;
    return res[r][c];
}

void input()
{
    memset(res,-1,sizeof(res));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&corn[i][j]);
}


int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
    while(~scanf("%d%d%d",&N,&B,&K))
    {
        input();
        RMQ();
        for(int i=0;i<K;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}
