#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, k;
int mp[10][10];
bool v2[10][10];
int xx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int yy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int cnt, ans, sum;
bool in(int x, int y)
{
    if(x <= n && x >= 1 && y <= m && y >= 1)
        return true;
    return false;
}
void dfs(int x, int y, int tt[10][10], int p, bool vv[10][10])
{
    vv[x][y] = 1;
    cnt++;
    for(int i = 0; i < 8; i++)
    {
        if(in(x + xx[i], y + yy[i]) && !vv[x + xx[i]][y + yy[i]] && tt[x + xx[i]][y + yy[i]] == p)
        {
            dfs(x + xx[i], y + yy[i], tt, p, vv);
        }
    }
}
void dfs2(int x, int y, int tt[10][10], int p)
{
    v2[x][y] = 1;
    tt[x][y] = 0;
    for(int i = 0; i < 8; i++)
    {
        if(in(x + xx[i], y + yy[i]) && !v2[x + xx[i]][y + yy[i]] && tt[x + xx[i]][y + yy[i]] == p)
        {
            dfs2(x + xx[i], y + yy[i], tt, p);
        }
    }
}
void move(int tt[10][10])
{
    int i, j, a[10], cc;
    for(i = 1; i <= 8; i++)
        a[i] = 0;
    for(i = 1; i <= m; i++)
    {
        cc = 0;
        for(j = 1; j <= n; j++)
            if(tt[j][i] > 0)
            {
                a[++cc] = tt[j][i];
            }
        for(j = 1; j <= n - cc; j++)
            tt[j][i] = 0;
        for(j = 1; j <= cc; j++)
        {
            tt[j + n - cc][i] = a[j];
        }
    }
    for(j = 1; j <= m; j++)
    {
        cc = 0;
        for(i = 1; i <= n; i++)
            if(tt[i][j] > 0) cc++;
        a[j] = cc;
    }
    int tp[10];
    for(i = 1; i <= n; i++)
    {
        int tc = 0;
        for(j = 1; j <= m; j++)
            if(a[j] == 0)
            {
                continue;
            }
            else
            {
                tp[++tc] = tt[i][j];
            }
        for(j = 1; j <= tc; j++)
            tt[i][j] = tp[j];
        for(j = tc + 1; j <= m; j++)
            tt[i][j] = 0;
    }
}
void click(int tt[10][10], int s, int *a, int x, int y)
{
    int i, j;
    int  ta[7], tmp[10][10];
    bool vv[10][10];
    int ts = s;
    for(i = 1; i <= k; i++)
    {
        if(a[i] >= 3)
            ts += a[i] * a[i];
    }
    if(ts < ans) return;
    for(int ii = 1; ii <= n; ii++)
    {
        for(int jj = 1; jj <= m; jj++)
        {
            vv[ii][jj] = 0;
            v2[ii][jj] = 0;
            tmp[ii][jj] = tt[ii][jj];
        }
    }
    if(x != 0 && y != 0)
        dfs2(x, y, tmp, tmp[x][y]);
    move(tmp);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(!vv[i][j] && tmp[i][j] > 0)
            {
                for(int ii = 1; ii <= k; ii++)
                    ta[ii] = a[ii];
                cnt = 0;
                dfs(i, j, tmp, tmp[i][j], vv);
                if(cnt >= 3)
                {
                    ta[tmp[i][j]] -= cnt;
                    click(tmp, s + cnt * cnt, ta, i, j);
                }
            }
        }
    }
    ans = max(ans, s);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i, j, a[7];
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(v2, 0, sizeof(v2));
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf("%d", &mp[i][j]);
                if(mp[i][j] > 0)
                    a[mp[i][j]]++;
            }
        }
        ans = 0;
        click(mp, 0, a, 0 , 0);
        printf("%d\n", ans);
    }
    return 0;
}
