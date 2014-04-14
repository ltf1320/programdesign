#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,c;
struct node
{
    int x,y;
} den[30];
int cmp(node a,node b)
{
    return a.x > b.x;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d %d",&n,&c))
    {
        int len = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u >= c) sum += v;
            else
            {
                den[len].x = u;
                den[len++].y = v;
            }
        }
        n = len;
        sort(den,den+n,cmp);
        int ok = 1;
        while(ok)
        {
            int a[30]= {0},left = c;
            for(int i = 0; i < n; i++)
            {
                if(den[i].y > 0)
                {
                    a[i] = min(den[i].y,left/den[i].x);
                    left -= a[i]*den[i].x;
                    den[i].y-=a[i];
                }
            }
            if(left!=0)
            {
                for(int i = n-1; i >= 0; i--)
                {
                    while(den[i].y > 0 && left > 0)
                    {
                        left -= den[i].x;
                        den[i].y--;
                        a[i]++;
                    }
                    if(left <= 0) break;
                }
                if(left <= 0) sum++;
                else ok = 0;
            }
            else sum++;
            if(left <= 0)
            {
                int minn=1<<30;
                for(int i = 0; i < n; i++)
                {
                    if(a[i] > 0)
                        minn = min(den[i].y/a[i],minn);
                }
                for(int i = 0; i < n; i++)
                {
                    if(a[i] > 0)
                        den[i].y -= a[i]*minn;
                }
                sum += minn;
            }
        }
        printf("%lld\n",sum);
    }
}
