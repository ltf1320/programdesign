#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define MAXN 5005
#define MAXM 50005
#define INF 1000000000
using namespace std;
vector<int>g[MAXN], dag[MAXN];
int n, m;
int dfn[MAXN], low[MAXN], instack[MAXN];
int scc, index, fa[MAXN], ha[MAXN], ind[MAXN];
int color[MAXN];
stack<int>st;
queue<int>q;
void init()
{
    scc = index = 0;
    for(int i = 0; i < 2 * n; i++)
        g[i].clear(), dag[i].clear();
    memset(instack, 0, sizeof(instack));
    memset(dfn, 0, sizeof(dfn));
    while(!st.empty()) st.pop();
    while(!q.empty()) q.pop();
    memset(ind, 0, sizeof(ind));
    memset(color, 0, sizeof(color));
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    instack[u] = 1;
    st.push(u);
    int size = g[u].size(), v;
    for(int i = 0; i < size; i++)
    {
        v = g[u][i];
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
            v = st.top();
            st.pop();
            instack[v] = 0;
            fa[v] = scc;
        }while(v != u);
    }
}
void buildDag()
{
    for(int u = 0; u < 2 * n; u++)
    {
        int size = g[u].size();
        for(int i = 0; i < size; i++)
        {
            int v = g[u][i];
            if(fa[u] != fa[v]) dag[fa[v]].push_back(fa[u]), ind[fa[u]]++;
        }
    }
}
void topsort()
{
    for(int i = 1; i <= scc; i++)
        if(ind[i] == 0) q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int size = dag[u].size();
        if(!color[u]) color[u] = 1, color[ha[u]] = 2;
        for(int i = 0; i < size; i++)
        {
            int v = dag[u][i];
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    }
}
void solve()
{
    for(int i = 0; i < 2 * n; i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 0; i < n; i++)
        if(fa[2 * i] == fa[2 * i + 1])
        {
            puts("bad luck");
            return;
        }
        else ha[fa[2 * i]] = fa[2 * i + 1], ha[fa[2 * i + 1]] = fa[2 * i];
    buildDag();
    topsort();
    for(int i = 2; i < 2 * n; i += 2)
        if(color[fa[i]] == color[fa[0]]) printf("%d%c ", i / 2, 'w');
        else printf("%d%c ", i / 2, 'h');
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    char c1, c2;
    int x, y, a0, b0, a1, b1;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0) break;
        init();
        while(m--)
        {
            scanf("%d%c %d%c", &x, &c1, &y, &c2);
            if(c1 == 'h') a0 = 2 * x, a1 = 2 * x + 1;
            else a0 = 2 * x + 1, a1 = 2 * x;
            if(c2 == 'h') b0 = 2 * y, b1 = 2 * y + 1;
            else b0 = 2 * y + 1, b1 = 2 * y;
            g[a1].push_back(b0);
            g[b1].push_back(a0);
        }
        g[0].push_back(1);
        solve();
    }
    return 0;
}
