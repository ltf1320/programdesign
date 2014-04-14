#include<cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN=50010;
typedef long long ll;
struct pt
{
    ll x,y;
    pt() {} pt(ll a,ll b):x(a),y(b) {}
    pt operator-(const pt a)const
    {
        return pt(x-a.x,y-a.y);
    }
    ll operator*(const pt a)const
    {
        return x*a.y-y*a.x;
    }
    bool operator<(const pt&a)const
    {
        return (*this)*a>0;
    }
} p[MAXN],lim[MAXN];
int q[MAXN],res[MAXN],bst[MAXN],cnt=0;
int main()
{
    freopen("in.txt","r",stdin);
    int n,i,h,t;
    ll nx=0,ny=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%I64d%I64d",&p[i].y,&p[i].x);
    sort(p+1,p+n+1);
    for(i=1; i<n; i++)
        lim[n-i]=pt(nx+=p[n-i+1].x,ny+=p[n-i+1].y);
    for(t=0,i=1; i<n; bst[i++]=q[t])
    {
        for(; t&&p[q[t]].x>=p[i].x; t--);
        for(; t>1&&(p[i]-p[q[t]])*(p[q[t]]-p[q[t-1]])<=0; t--);
        for(q[++t]=i; t>1&&lim[i]*(p[q[t]]-p[q[t-1]])<=0; t--);
    }
    for(t=0,h=1,i=n-1; i; i--)
    {
        for(; h<=t&&(p[q[t]].x<=p[i+1].x||p[q[t]].y<=p[i+1].y); t--);
        for(; h<t&&(p[i+1]-p[q[t]])*(p[q[t]]-p[q[t-1]])<=0; t--);
        for(q[++t]=i+1; h<t&&lim[i]*(p[q[h]]-p[q[h+1]])>=0; h++);
        if(lim[i]*(p[bst[i]]-p[q[h]])>0)
            res[++cnt]=i;
    }
    for(printf("%d\n",i=cnt); i; i--) printf("%d\n",res[i]);
    return 0;
}
