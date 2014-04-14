#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 5005
#define MAXM 50005
#define INF 1000000000
using namespace std;
struct Edge
{
    int v, next;
}edge[MAXM];
int n, m, e;
int top, scc, index;
int low[MAXN], dfn[MAXN], instack[MAXN];
int head[MAXN], st[MAXN], fa[MAXN];
int a[MAXN], b[MAXN], hash[MAXN];
int x[MAXN], y[MAXN];
void init()
{
    top = scc = index = e = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(instack, 0, sizeof(instack));
}
void insert(int x, int y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++index;
    instack[u] = 1;
    st[++top] = u;
    int v;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        scc++;
        do
        {
            v = st[top--];
            instack[v] = 0;
            fa[v] = scc;
        }while(v != u);
    }
}
bool check(int n)
{
    for(int i = 1; i <= n; i++)
        if(fa[i] == fa[i + n]) return false;
    return true;
}
void build(int bound)
{
    init();
    for(int i = 1; i <= n; i++)
    {
        insert(a[i], b[i] + 2 * n);
        insert(b[i], a[i] + 2 * n);
    }
    for(int i = 1; i <= bound; i++)
    {
        insert(x[i] + 2 * n, y[i]);
        insert(y[i] + 2 * n, x[i]);
    }
    for(int i = 1; i <= 2 * n; i++)
        if(!dfn[i]) tarjan(i);
}
void solve()
{
    int ans = 0;
    int low = 0, high = m;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        build(mid);
        if(check(n * 2)) ans = max(ans, mid), low = mid + 1;
        else high = mid - 1;
    }
    printf("%d\n", ans);
}
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            a[i]++; b[i]++;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            x[i]++; y[i]++;
        }
        solve();
    }
    return 0;
}
