#include <stdio.h>
#include <cstring>
#include <queue>
#define INF 0x1f1f1f1f
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;

int cap[155][155], flow[155][155];
int p[155], a[155];
int f, n, m;

void EK(int s, int t)
{
    queue<int> q;
    memset(flow, 0, sizeof(flow));
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    f = 0;
    while(1)
    {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v = 1; v <= 2*n; ++v)
            if(!a[v] && cap[u][v] > flow[u][v])
            {
                p[v] = u;
                q.push(v);
                a[v] = a[u] < cap[u][v] - flow[u][v]? a[u]:cap[u][v] - flow[u][v];
            }
        }
        if(a[t] == 0) break;
        for(int u = t; u != s; u = p[u])
        {
            flow[p[u]][u] += a[t];
            flow[u][p[u]] -= a[t];
        }
        f += a[t];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i, j, k;
    int a, b;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0){
            puts("0");
            continue;
        }
        clr(cap);

        for(i = 1; i <= n; ++i)
        cap[i][i+n] = 1;

        while(m--){
            scanf(" (%d,%d)", &a, &b);
            cap[a+1+n][b+1] = cap[b+1+n][a+1] = INF;
        }
        int ans = INF;

        for(i = 2; i <= n; ++i){
            EK(n+1, i);
            if(f < ans) ans = f;
        }

        if(ans == INF)
            printf("%d\n", n);
        else
            printf("%d\n", ans);
    }

    return 0;
}
