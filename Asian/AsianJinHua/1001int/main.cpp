#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int N,cas;
struct Point
{
    int x,y,r,num;
};
Point pnt[maxn];
bool used[maxn];
map<int,int> X[maxn];

void input()
{
    int x,y,r;
    for(int i=0; i<maxn; i++) X[i].clear();
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d",&x,&y,&r);
        pnt[i].x=x;
        pnt[i].y=y;
        pnt[i].r=r;
        pnt[i].num=1;
        if(X[x].count(y)==1)
        {
            int s=X[x][y];
            if(pnt[s].r>r)
            {
                pnt[s].num++;
                pnt[i].num=0;
            }
            else
            {
                X[x].erase(y);
                X[x][y]=i;
                pnt[i].num+=pnt[s].num;
                pnt[s].num=0;
            }
        }
        else X[x][y]=i;
    }
    /*
    for(int i=0;i<N;i++)
        for(map<int,int>::iterator iter=X[i].begin();iter!=X[i].end();iter++)
            printf("%d %d %d\n",i,iter->first,iter->second);
    */
}
int abs(int a)
{
    return a>0?a:-a;
}
int que[maxn];

int explore(int f)
{
    int res=0;
    int n;
    int head=0,tail=1;
    int start,end;
    int fir,sec;
    que[head]=f;
    while(head<tail)
    {
        n=que[head];
        head++;
        res+=pnt[n].num;
        start=max((int)0,pnt[n].x-pnt[n].r);
        end=min(100000,pnt[n].x+pnt[n].r);
        map<int,int>::iterator iter;
        for(int i=start; i<=end; i++)
        {
            iter=X[i].lower_bound(pnt[n].y-pnt[n].r+abs(pnt[n].x-i));
            for(;iter!=X[i].end()&&iter->first<=pnt[n].y+pnt[n].r-abs(pnt[n].x-i); iter++)
            {
                fir=iter->first;
                sec=iter->second;
                if(!used[iter->second])
                {
                    used[sec]=1;
                    que[tail++]=sec;
                }
            }
        }
    }
    return res;
}

void work()
{
    memset(used,0,sizeof(used));
    printf("Case #%d:\n",cas++);
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
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        input();
        work();
    }
    return 0;
}
