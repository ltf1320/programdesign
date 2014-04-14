#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=1000;
int N,M;
vector<int>son[maxn];
int sum[maxn];
int indu[maxn];
int path[2*maxn];
int deep[2*maxn];
int dp[2*maxn][20];
int dpn[2*maxn][20];
int first[maxn];
int p2[maxn];

int find2(int n)
{
    return log(1.0*n+1)/log(2.0);
}

void pre()
{
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
}
int p;
void dfs(int n,int dep)
{
    first[n]=p;
    path[p]=n;
    deep[p++]=dep;
    for(size_t i=0;i<son[n].size();i++)
    {
        dfs(son[n][i],dep+1);
        path[p]=n;
        deep[p++]=dep;
    }
}

void RMQ()
{
    for(int i=0;i<=p;i++)
    {
        dp[i][0]=deep[i];
        dpn[i][0]=i;
    }
    for(int j=1;p2[j]<=p;j++)
        for(int i=0;i<p-p2[j-1];i++)
            if(dp[i][j-1]<dp[i+p2[j-1]][j-1])
            {
                dp[i][j]=dp[i][j-1];
                dpn[i][j]=dpn[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i+p2[j-1]][j-1];
                dpn[i][j]=dpn[i+p2[j-1]][j-1];
            }
}

int query(int a,int b)
{
    int pp=find2(b-a);
    if(dp[a][pp]<dp[b-p2[pp]+1][pp])
        return path[dpn[a][pp]];
    else return path[dpn[b-p2[pp]+1][pp]];
}

void init()
{
    memset(sum,0,sizeof(sum));
    memset(indu,0,sizeof(indu));
    for(int i=0;i<=N;i++)
        son[i].clear();
    p=0;
}

void skip()
{
    char ch=getchar();
    while(ch!=')'&&ch!='(')
        ch=getchar();
}

int main()
{
    freopen("in.txt","r",stdin);
    int now,a,b,tmp;
    pre();
    while(~scanf("%d",&N))
    {
        init();
        for(int i=0;i<N;i++)
        {
            scanf("%d",&now);
            skip();
            scanf("%d",&a);
            skip();
            for(int i=0;i<a;i++)
            {
                scanf("%d",&tmp);
                indu[tmp]++;
                son[now].push_back(tmp);
            }
        }
        for(int i=1;i<=N;i++)
            if(!indu[i])
                {dfs(i,1);break;}
        RMQ();
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            skip();
            scanf("%d %d",&a,&b);
            skip();
            a=first[a];
            b=first[b];
            if(a>b)
            {
                int t=a;
                a=b;
                b=t;
            }
            sum[query(a,b)]++;
        }
        for(int i=1;i<=N;i++)
            if(sum[i])
                printf("%d:%d\n",i,sum[i]);
    }
    return 0;
}
