#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

// For Ideone
//typedef long long __int64;

const double eps = 1e-08;
const double mi = 1e+20;
inline int fi (double a)
{
    if (a > eps) return 1;
    else if (a >= -eps) return 0;
    else return -1;
}
typedef pair<int, int> point;
inline bool mislead (bool convex, point a, point b, point c)
{
    int x1 = b.first - a.first, y1 = b.second - a.second;
    int x2 = c.first - b.first, y2 = c.second - b.second;
    __int64 m = (__int64)x1 * y2 - (__int64)x2 * y1;
    if (m == 0) return true;
    else if (convex ^ (m < 0)) return true;
    else return false;
}
class sbt_node;
typedef sbt_node* sbt_node_ptr;
class sbt_node
{
public:
    int d, n, s;
    sbt_node_ptr ch[2];
    sbt_node (void) : s(0) {}
    point topoint (void) { return make_pair(d, n); }
};
sbt_node_ptr nil = new sbt_node();
void rotate (sbt_node_ptr& x, int dir)
{
    sbt_node_ptr k = x->ch[dir ^ 1];
    x->ch[dir ^ 1] = k->ch[dir];
    k->ch[dir] = x;
    k->s = x->s;
    x->s = x->ch[0]->s + x->ch[1]->s + 1;
    x = k;
}
void maintain (sbt_node_ptr& x, int dir)
{
    if (x->ch[dir] == nil) return;
    else if (x->ch[dir]->ch[dir]->s > x->ch[dir ^ 1]->s) rotate(x, dir ^ 1);
    else if (x->ch[dir]->ch[dir ^ 1]->s > x->ch[dir ^ 1]->s)
    {
        rotate(x->ch[dir], dir);
        rotate(x, dir ^ 1);
    }
    else return;
    maintain(x->ch[0], 0), maintain(x->ch[1], 1);
    maintain(x, 0), maintain(x, 1);
}
const int maxn = 200100;
sbt_node arr[maxn]; int arrmr;
void initialize (void) { arrmr = 0; }
sbt_node_ptr new_node (int d, int n)
{
    arr[arrmr].d = d, arr[arrmr].n = n, arr[arrmr].s = 1;
    arr[arrmr].ch[0] = arr[arrmr].ch[1] = nil;
    return &arr[arrmr++];
}
class convex_sbt
{
private:
    sbt_node_ptr root;
    sbt_node_ptr _search (sbt_node_ptr x, int d)
    {
        if (x->d == d || x == nil) return x;
        else if (d < x->d) return _search(x->ch[0], d);
        else return _search(x->ch[1], d);
    }
    sbt_node_ptr _most (sbt_node_ptr x, int dir)
    {
        sbt_node_ptr ans = x;
        while (ans != nil && ans->ch[dir] != nil) ans = ans->ch[dir];
        return ans;
    }
    sbt_node_ptr _shift (sbt_node_ptr x, int d, int dir)
    {
        if (x->d == d) return _most(x->ch[dir], dir ^ 1);
        int td = d < x->d ? 0 : 1;
        sbt_node_ptr ans = _shift(x->ch[td], d, dir);
        if (ans != nil) return ans;
        else return (dir ^ td) ? x : nil;
    }
    sbt_node_ptr _query (sbt_node_ptr x, double k)
    {
        sbt_node_ptr t1 = _shift(x, x->d, 0), t2 = _shift(x, x->d, 1);
        double k1 = (t1 == nil) ? (convex ? mi : -mi) : (double)(x->n - t1->n) / (x->d - t1->d),
               k2 = (t2 == nil) ? (convex ? -mi : mi) : (double)(t2->n - x->n) / (t2->d - x->d);
        if (convex)
        {
            if (fi(k1 - k) >= 0 && fi(k - k2) >= 0) return x;
            else if (fi(k1 - k) == -1) return _query(x->ch[0], k);
            else return _query(x->ch[1], k);
        }
        else
        {
            if (fi(k1 - k) <= 0 && fi(k - k2) <= 0) return x;
            else if (fi(k1 - k) == 1) return _query(x->ch[0], k);
            else return _query(x->ch[1], k);
        }
    }
    void _insert (sbt_node_ptr& x, int d, int n)
    {
        if (x == nil) x = new_node(d, n);
        else
        {
            x->s++;
            if (d < x->d) _insert(x->ch[0], d, n);
            else _insert(x->ch[1], d, n);
            maintain(x, (d < x->d) ? 0 : 1);
        }
    }
    point _delete (sbt_node_ptr& x, int d)
    {
        point rs; x->s--;
        if (d == x->d || (d < x->d && x->ch[0] == nil) || (d > x->d && x->ch[1] == nil))
        {
            rs = x->topoint();
            if (x->ch[0] == nil) x = x->ch[1];
            else if (x->ch[1] == nil) x = x->ch[0];
            else
            {
                point tt = _delete(x->ch[0], x->d + 1);
                x->d = tt.first, x->n = tt.second;
            }
            return rs;
        }
        else
        {
            if (d < x->d) return _delete(x->ch[0], d);
            else return _delete(x->ch[1], d);
        }
    }
public:
    bool convex;
    convex_sbt (void) : root(nil) {}
    convex_sbt (bool c0) : root(nil), convex(c0) {}
    void ins (int d, int n)
    {
        sbt_node_ptr t = _search(root, d), t2;
        point p = make_pair(d, n);
        if (t != nil)
        {
            if ((t->n <= n) ^ convex) return;
            _delete(root, d);
        }
        _insert(root, d, n);
        t = _shift(root, d, 0);
        t2 = _shift(root, d, 1);
        if (t != nil && t2 != nil && mislead(convex, t->topoint(), p, t2->topoint()))
        {
            _delete(root, d);
            return;
        }
        while (1)
        {
            t = _shift(root, d, 0); if (t == nil) break;
            t2 = _shift(root, t->d, 0); if (t2 == nil) break;
            if (mislead(convex, t2->topoint(), t->topoint(), p)) _delete(root, t->d);
            else break;
        }
        while (1)
        {
            t = _shift(root, d, 1); if (t == nil) break;
            t2 = _shift(root, t->d, 1); if (t2 == nil) break;
            if (mislead(convex, p, t->topoint(), t2->topoint())) _delete(root, t->d);
            else break;
        }
    }
    double query (double k)
    {
        sbt_node_ptr ans = _query(root, k);
        return ans->n - k * ans->d;
    }
};
point subject[50010];
bool comp (const point& a, const point& b) { return (double)a.second / a.first > (double)b.second / b.first; }
double sav[50010], disp[50010];
int ans[50010], ansmr;
int main ()
{
    freopen("in.txt","r",stdin);
    int n, sumn = 0, sumd = 0, tn, td, tp; double k;
    initialize();
    convex_sbt save(false), discard(true);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tn, &td);
        subject[i] = make_pair(td, tn);
    }
    sort(subject, subject + n, comp);
    for (int i = 0; i < n; i++)
    {
        sumn += subject[i].second, sumd += subject[i].first;
        save.ins(subject[i].first, subject[i].second);
        k = (double)sumn / sumd;
        sav[n - 1 - i] = save.query(k);
    }
    tp = n - 1, ansmr = 0;
    for (int i = 1; i < n; i++, tp--)
    {
        sumn -= subject[tp].second, sumd -= subject[tp].first;
        discard.ins(subject[tp].first, subject[tp].second);
        k = (double)sumn / sumd;
        disp[i] = discard.query(k);
        if (sav[i] < disp[i]) ans[ansmr++] = i;
    }
    printf("%d\n", ansmr);
    for (int i = 0; i < ansmr; i++) printf("%d\n", ans[i]);
    return 0;
}
