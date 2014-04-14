#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,x,y,ans,o;
int three[15],q[15],p[15],map[160][15],f[2][60000];

void pre()
{
    three[0] = 1;
    for (int i = 1; i <= 11; i ++) three[i] = three[i - 1] * 3;
}

int update(int* p,int* q,int i,int j)
{
    int cnt = 0,res = 0;
    memset(q,0,sizeof q);
    memset(p,0,sizeof p);
    for (int k = 1; k <= m; k ++)
    {
        p[k] = j % 3;
        j /= 3;
    }
    for (int k = 0; k < m; k ++)
    {
        if (map[i][k + 1]) q[k + 1] = 2,res += three[k] * 2;
        else if (p[k + 1] == 2) q[k + 1] = 1,res += three[k];
        else if (p[k + 1] < 2) q[k + 1] = 0;
    }
    return res;
}

void dfs(int now,int y,int r)
{
    if (now > ans) ans = now;
    if (y + 1 <= m && p[y] == 0 && p[y + 1] == 0 && q[y] == 0 && q[y + 1] == 0)
    {
        q[y] = 2;
        q[y + 1] = 2;
        int i = r + three[y - 1] * 2 + three[y] * 2;
        if (now + 1 > f[o][i]) f[o][i] = now + 1;
        dfs(now + 1,y + 2,i);
        q[y] = 0;
        q[y + 1] = 0;
    }
    if (y + 2 <= m && q[y] == 0 && q[y + 1] == 0 && q[y + 2] == 0)
    {
        q[y] = q[y + 1] = q[y + 2] = 2;
        int i = r + three[y - 1] * 2 + three[y] * 2 + three[y + 1] * 2;
        if (now + 1 > f[o][i]) f[o][i] = now + 1;
        dfs(now + 1,y + 3,i);
        q[y] = q[y + 1] = q[y + 2] = 0;
    }
    if (now > f[o][r]) f[o][r] = now;
    if (y + 1 <= m) dfs(now,y + 1,r);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    pre();
    while (T --)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(map,0,sizeof map);
        for (int i = 1; i <= k; i ++)
        {
            scanf("%d%d",&x,&y);
            map[x][y] = 1;
        }

        x = 0;
        for (int i = 1; i <= m; i ++)
        {
            if (map[1][i]) x += 2 * three[i - 1];
            else x += three[i - 1];
        }

        o = 0;
        memset(f,-1,sizeof f);
        f[o][x] = 0;
        ans = 0;
        for (int i = 2; i <= n; i ++)
        {
            o = 1 - o;
            memset(f[o],-1,sizeof f[o]);
            for (int j = 0; j < three[m]; j ++) if (f[1 - o][j] != -1)
                {
                    int r = update(p,q,i,j);
                    dfs(f[1 - o][j],1,r);
                }
        }
        cout << ans << endl;
    }

    return 0;
}
