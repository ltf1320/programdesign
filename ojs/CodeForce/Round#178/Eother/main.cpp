#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = ~0u>>2;
const int mod = 1000000007 ;
const int maxn = 5010;
int  son[maxn] ;
long long dp[maxn];
int n ;
int mp[maxn][maxn];
vector<int> edge[maxn];
int node;
struct Edge
{
    int s,t,w;
    Edge() {}
    Edge(int a,int b,int c)
    {
        s = a;
        t = b;
        w = c;
    }
} in[maxn];
int dep[maxn];
void dfs(int u,int f)  //标出深度和子树节点个数
{
    son[u] = 1;
    dep[u] = dep[f] + 1;
    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v==f) continue;
        dfs(v,u);
        son[u] += son[v];
    }
}
int cen;
int S[maxn];
void DFS(int u,int f) //去掉node点后子树节点个数
{
    S[u] = 1;
    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v == f || v == node) continue;
        DFS(v,u);
        S[u] += S[v];
    }
}
long long sum;
void dfs1(int u,int f,int rt)
{
    dp[u] = 0;
    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v == f || v == node) continue;
        dfs1(v,u,rt);
        sum += (long long ) S[v] * (S[rt]-S[v]) * mp[u][v]; //sum表示总距离和
        dp[u] += dp[v] + (long long)S[v] * mp[u][v]; //dp 表示此点在去边后到子树的距离和
    }
}
long long Mi;
void dfs2(int u,int f,int rt)
{
    if(u==rt)
    {
        Mi = min(dp[u],Mi);
    }
    else
    {
        long long tmp = dp[f] - dp[u] - (long long)S[u] * mp[f][u];
        dp[u] += (long long)mp[f][u] * (S[rt] - S[u]) + tmp; //这里dp表示到这个树其他点距离总和
        Mi = min(dp[u],Mi); //Mi表示到其他点距离总和最小值
    }
    int sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[u][i];
        if(v == f || v == node) continue;
        dfs2(v,u,rt) ;
    }
}
int main()
{
    scanf("%d",&n);
    int a,b,c;
    int tot = 0;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        mp[a][b] = mp[b][a] = c;
        in[tot++] = Edge(a,b,c);
    }
    dfs(1,0);
    long long INF = (long long)1000000000*(long long)1000000000;
    long long ans = INF;
    for(int i=0; i<tot; i++)
    {
        int u = in[i].s , v = in[i].t;
        if(dep[u] > dep[v]) swap(u,v);
        node = v;

        Mi = INF;
        sum = 0;
        DFS(1,0);
        dfs1(1,0,1);
        dfs2(1,0,1);

        long long tmp = (long long)(son[1]-son[node])*(son[node])*in[i].w;//被拆这条边在总距离中算的大小
        tmp += Mi * (son[node]) ;
        tmp += sum;
        Mi = INF;
        sum = 0;
        memset(dp,0,sizeof(dp)); //
        DFS(node,u);
        dfs1(node,u,node);
        dfs2(node,u,node);

        tmp += Mi * (son[1]-son[node]);
        tmp += sum;
        if(tmp < ans) ans = tmp;
    }
    printf("%I64d\n",ans);
    return 0;
}
