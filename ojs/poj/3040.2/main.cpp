#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=20+5;
const int inf=0x3fffffff;
int N,C;
int ki;
struct Momo
{
    int v,b;
    bool operator<(const Momo &a)const
    {
        return v>a.v;
    }
};
Momo BOOL[maxn];
LL res=0;
int used[maxn];
void dfs(int now,int sum)
{
    if(sum>=C)
    {
        int minc=inf;
        for(int i=ki; i<now; i++)
            if(used[i])
                minc=min(minc,BOOL[i].b/used[i]);
        for(int i=ki; i<now; i++)
            BOOL[i].b-=minc*used[i];
        res+=minc;
        return;
    }
    if(now>N) return;
    for(int i=ki;i<now;i++)
        if(used[i]&&!BOOL[i].b)
            return;
    int pre=now-1;
    for(int i=0; i<=BOOL[now].b; i++)  //=
    {
        while(BOOL[pre].b==0) pre--;
        if(i*BOOL[now].v>=BOOL[pre].v) break;
        used[now]=i;
        dfs(now+1,sum+BOOL[now].v*i);
    }
}

void dfsp(int now,int sum)
{
    if(sum>C) return;
    if(sum==C)
    {
        int minc=inf;
        for(int i=ki; i<now; i++)
            if(used[i])
                minc=min(minc,BOOL[i].b/used[i]);
        for(int i=ki; i<now; i++)
            BOOL[i].b-=minc*used[i];
        res+=minc;
        return;
    }
    if(now>N) return;
    for(int i=C/BOOL[now].v; i>=0; i--)
    {
        if(i>BOOL[now].b) i=BOOL[now].b;
        used[now]=i;
        dfsp(now+1,sum+BOOL[now].v*i);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&C))
    {
        res=0;
        for(int i=1; i<=N; i++)
            scanf("%d%d",&BOOL[i].v,&BOOL[i].b);
        sort(BOOL+1,BOOL+N+1);
        for(ki=1; BOOL[ki].v>=C; ki++)
        {
            res+=BOOL[ki].b;
            BOOL[ki].b=0;
        }
        dfsp(ki,0);
        BOOL[ki-1].v=inf;
        BOOL[ki-1].b=inf;
        for(; ki<=N; ki++)
        {
            BOOL[ki-1].v=inf;
            BOOL[ki-1].b=inf;
            dfs(ki,0);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
