#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110000;

int n;


struct edge
{
    int a,b,c,next;
}e[maxn*2];
struct node
{
    int x,no;
}a[maxn];
int dp[maxn][2][2];

int head[maxn],cnt;
int father[maxn],fa_dis[maxn];
int vis[maxn];

void add(int a,int b,int c)
{
    e[cnt].a=a;
    e[cnt].b=b;
    e[cnt].c=c;
    e[cnt].next=head[a];
    head[a]=cnt++;
}

void init()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    memset(father,0,sizeof(father));
    memset(vis,0,sizeof(vis));

    cnt=0;
}
bool cmp(node a,node b)
{
    return (a.x>b.x);
}

void dfs(int p)
{
    for (int i=head[p];i!=-1;i=e[i].next)
    {
        int v=e[i].b;
        if (father[v]==0)
        {
            father[v]=p;
            fa_dis[v]=e[i].c;
            dfs(v);
        }
    }

}
int work(int p)
{
    int res=dp[p][0][0];
    int dis=0;

    while (p!=1)
    {
        dis+=fa_dis[p];
        if (vis[father[p]]) res=max(res,dis);
        if (dp[father[p]][0][1]!=p&&dp[father[p]][0][1]!=0)
        res=max(res,dis+dp[father[p]][0][0]);
        else if (dp[father[p]][1][1]!=0)
            res=max(res,dis+dp[father[p]][1][0]);


        p=father[p];
    }
    return res;
}
void update(int p)
{
    vis[p]=1;
    int dis=0;
    while (p!=1)
    {
        dis+=fa_dis[p];
        if (dis>dp[father[p]][0][0])
        {
            if (dp[father[p]][0][1]!=0&&dp[father[p]][0][1]!=p)
            {
                dp[father[p]][1][0]=dp[father[p]][0][0];
                dp[father[p]][1][1]=dp[father[p]][0][1];
            }
            dp[father[p]][0][0]=dis;
            dp[father[p]][0][1]=p;
        }
        else
        {
            if (dis>dp[father[p]][1][0]&&dp[father[p]][0][1]!=p
                )
            {
                dp[father[p]][1][0]=dis;
                dp[father[p]][1][1]=p;
            }
        }


        p=father[p];
    }
}
int main()
{
  //  freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    int cas=1;
    while (t--)
    {
        scanf("%d",&n);
        init();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].no=i;
        }
        int u,v,c;
        for (int i=1;i<n;i++)
        {

           scanf("%d%d%d",&u,&v,&c);
           add(u,v,c);
           add(v,u,c);
        }
        int ans=0;

        sort(a+1,a+n+1,cmp);

        father[1]=1;
        dfs(1);
        int yy;
        for (int i=1;i<=n;i++)
        {
            yy=a[i].no;
            int dis=work(yy);
            ans=max(ans,dis*a[i].x);
           // cout<<yy<<" "<<dis<<endl;
            update(yy);
        }


        cout<<"Case "<<cas++<<": "<<ans<<endl;


    }
    return 0;
}
