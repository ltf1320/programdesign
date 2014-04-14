#include <stdio.h>
#include <cstring>
#define MAX 19931117
#define QR 1001000
typedef struct str_a
{
    int x, y;
} point;
int map[31][31], r, c;
int dist[31][31];
__int64 method[31][31];
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
point queue[QR];
int now, add;
point route[31][31][901];
int crte[31][31];
char sch[31][31];
int isvalid (point a)
{
    if (a.x >= 0 && a.x < r && a.y >= 0 && a.y < c) return 1;
    else return 0;
}
int maptile (point a)
{
    return map[a.x][a.y];
}
void find (point a)
{
    int i;
    point b, cur;
    memset(sch, 0, sizeof(sch));
    add = now = 0;
    queue[add++] = a;
    sch[a.x][a.y] = 1;
    while (now != add)
    {
        cur = queue[now++];
        for (i = 0; i < 8; i++)
        {
            b.x = cur.x + dx[i];
            b.y = cur.y + dy[i];
            if (isvalid(b))
            {
                if (maptile(b) == 2) continue;
                else if (sch[b.x][b.y]) continue;
                else if (maptile(b) == 1)
                {
                    queue[add++] = b;
                    sch[b.x][b.y] = 1;
                }
                else
                {
                    route[a.x][a.y][crte[a.x][a.y]++] = b;
                    sch[b.x][b.y] = 1;
                }
            }
        }
    }
    return;
}
void spfa (point a)
{
    int i, j;
    point cur, b;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            dist[i][j] = MAX;
    }
    memset(method, 0, sizeof(method));
    memset(sch, 0, sizeof(sch));
    dist[a.x][a.y] = 0;
    method[a.x][a.y] = 1;
    now = add = 0;
    queue[add++] = a;
    sch[a.x][a.y] = 1;
    while (now != add)
    {
        cur = queue[(now++) % QR];
        if (map[cur.x][cur.y] == 4) continue;
        for (i = 0; i < crte[cur.x][cur.y]; i++)
        {
            b = route[cur.x][cur.y][i];
            if (dist[cur.x][cur.y] + 1 < dist[b.x][b.y])
            {
                dist[b.x][b.y] = dist[cur.x][cur.y] + 1;
                method[b.x][b.y] = method[cur.x][cur.y];
                if (sch[b.x][b.y] == 0)
                {
                    queue[(add++) % QR] = b;
                    sch[b.x][b.y] = 1;
                }
            }
            else if (dist[cur.x][cur.y] + 1 == dist[b.x][b.y])
            {
                method[b.x][b.y] += method[cur.x][cur.y];
                if (sch[b.x][b.y] == 0)
                {
                    queue[(add++) % QR] = b;
                    sch[b.x][b.y] = 1;
                }
            }
        }
        // method 清零是 SPFA 求最短路数量正确性的基础，把这个搞明白就行了。
        // 实际上，method 表示的是“能够再更新多少种放法”。
        method[cur.x][cur.y] = 0;
        sch[cur.x][cur.y] = 0;
    }
    return;
}
int main ()
{
    freopen("in.txt","r",stdin);
    int i, j;
    point st, ed, t;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 3) st.x = i, st.y = j;
            else if (map[i][j] == 4) ed.x = i, ed.y = j;
        }
    }
    memset(crte, 0, sizeof(crte));
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (map[i][j] == 0 || map[i][j] == 3 || map[i][j] == 4)
            {
                t.x = i, t.y = j;
                find(t);
            }
        }
    }
    spfa(st);
    if (dist[ed.x][ed.y] == MAX) printf("-1\n");
    else printf("%d\n%I64d\n", dist[ed.x][ed.y] - 1, method[ed.x][ed.y]);
    return 0;
}
