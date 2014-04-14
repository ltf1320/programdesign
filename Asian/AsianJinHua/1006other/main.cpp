//1006
#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int MAXN=100020;

struct Node
{
    int from,to;
    int next;
}edge[MAXN];
int head[MAXN];
int tol;
void add(int u,int v)
{
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].next=head[u];
    head[u]=tol++;
}

double  dp[MAXN];
bool vis[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
   // freopen("F.out","w",stdout);
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        memset(vis,false,sizeof(vis));
        tol=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            add(v,u);
        }
        dp[n]=-1;
        //printf("%d  %.4lf\n",n,dp[n]);
        for(int i=n;i>=0;i--)
        {
            if(!vis[i])
            {
                dp[i]+=1;
                for(int j=i+1;j<=i+6;j++)
                  dp[i]+=(dp[j]/6.0);
                vis[i]=true;
            }
            for(int j=head[i];j!=-1;j=edge[j].next)
            {
                int v=edge[j].to;
                dp[v]=dp[i];
                vis[v]=true;
            }
          //  printf("%d  %.4lf\n",i,dp[i]);
        }
        printf("%.4lf\n",dp[0]);

    }
    return 0;
}
