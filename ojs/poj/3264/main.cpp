#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=50000+10;
int N,Q;

int dpmx[maxn][20],dpmn[maxn][20];
int num[maxn];
int p2[20];

int find2(int n)
{
    return (int)(log(1.0*n+1)/log(2.0));
}

void RMQ()
{
    for(int i=1;i<=N;i++)
        dpmx[i][0]=dpmn[i][0]=num[i];
    for(int j=1;p2[j-1]<=N;j++)
    {
        for(int i=1;i<=N-p2[j-1];i++)
        {
            dpmx[i][j]=max(dpmx[i][j-1],dpmx[i+p2[j-1]][j-1]);
            dpmn[i][j]=min(dpmn[i][j-1],dpmn[i+p2[j-1]][j-1]);
        }
    }
    /*
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<20;j++)
        {
            printf("%d ",dpmx[i][j]);
        }
        putchar('\n');
    }
    */
}

int query(int a,int b)
{
    int p=find2(b-a);
    int mx=max(dpmx[a][p],dpmx[b-p2[p]+1][p]); //+1
    int mn=min(dpmn[a][p],dpmn[b-p2[p]+1][p]); //fuck dpmx
    return mx-mn;
}

void pre()
{
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++)
        scanf("%d",&num[i]);
    RMQ();
    int a,b;
    for(int i=0;i<Q;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(a,b));
    }
    return 0;
}
