#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int maxn=100000+100;
__int64 N,cas;
struct Point
{
    __int64 x,y,r;
};
Point pnt[maxn];
bool used[maxn];
map<__int64,int> X[maxn];

void input()
{
    __int64 x,y,r;
    for(int i=0;i<maxn;i++) X[i].clear();
    for(int i=0;i<N;i++)
    {
        scanf("%I64d%I64d%I64d",&x,&y,&r);
        pnt[i].x=x;
        pnt[i].y=y;
        pnt[i].r=r;
        X[x][y]=i;
    }
    /*
    for(int i=0;i<N;i++)
        for(map<int,int>::iterator iter=X[i].begin();iter!=X[i].end();iter++)
            printf("%d %d %d\n",i,iter->first,iter->second);
    */
}
int abs(int a){return a>0?a:-a;}
__int64 abs(__int64 a){return a>0?a:-a;}
__int64 max(__int64 a,__int64 b){return a>b?a:b;}
__int64 min(__int64 a,__int64 b){return a<b?a:b;}

int explore(int n)
{
    int res=1;
    int start,end;
    start=max((__int64)0,pnt[n].x-pnt[n].r);
    end=min(N-1,pnt[n].x+pnt[n].r);
    map<__int64,int>::iterator iter;
    for(int i=start;i<=end;i++)
    {
        iter=X[i].lower_bound(pnt[n].y-pnt[n].r+abs(pnt[n].x-i));
        for(;iter!=X[i].end()&&iter->first<=pnt[n].y+pnt[n].r-abs(pnt[n].x-i);iter++)
        {
            if(!used[iter->second])
            {
                used[iter->second]=1;
                res+=explore(iter->second);
            }
        }
    }
    return res;
}

void work()
{
    memset(used,0,sizeof(used));
    printf("Case #%I64d:\n",cas++);
    int n,now;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&now);
        if(!used[now-1])
        {
            used[now-1]=1;
            printf("%d\n",explore(now-1));
        }
        else printf("0\n");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    cas=1;
    while(~scanf("%I64d",&N))
    {
        if(N==0) break;
        input();
        work();
    }
    return 0;
}
