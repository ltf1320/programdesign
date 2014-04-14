#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=5000;
int n,d;


struct Point
{
    double l,r;
    void reset(int x,int y)
    {
        double dis=sqrt(1.0*d*d-1.0*y*y);
        l=x*1.0-dis;
        r=x*1.0+dis;
    }
    bool operator<(const Point &a) const
    {
        return l<a.l;
    }
};

Point pnt[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    bool imp;
    int tx,ty;
    int cas=0;
    int t;
    int num;
    while(~scanf("%d%d",&n,&d),n,d)
    {
        if(n==0&& d==0) break;
        cas++;
        imp=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&tx,&ty);
            pnt[i].reset(tx,ty);
            if(ty>d||d<0) imp=1;
        }
        if(imp)
        {
            printf("Case %d: -1\n",cas);
            continue;
        }
        sort(pnt,pnt+n);
        t=pnt[0].r;
        num=1;
        for(int i=1;i<n;++i)
        {
            if(pnt[i].r<t)
            {
                t=pnt[i].r;
            }
            else if(pnt[i].l>t)
            {
                num++;
                t=pnt[i].r;
            }
        }
        printf("Case %d: %d\n",cas,num);
    }
    return 0;
}
