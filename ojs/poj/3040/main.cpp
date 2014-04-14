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
 //   cout<<sum<<endl;
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
    int pre=now-1,pp=1,flag=1;
    while(BOOL[now].b)
    {
        while(BOOL[pre].b==0)
        {
            flag=1;
            pre--;
            if(pre<ki) break;
        }
        if(!flag) break;
        if(pre<ki)
        {
            for(pp=1;sum+pp*BOOL[now].v<=C;pp++)
            {
                used[now]=pp;
                dfs(now+1,pp*BOOL[now].v);
            }
            break;
        }
        for(;pp*BOOL[now].v<BOOL[pre].v;pp++)
        {
            used[now]=pp;
            dfs(now+1,sum+pp*BOOL[now].v);
        }
        flag=0;
    }
    used[now]=0;
    dfs(now+1,sum);
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&C);
    for(int i=1; i<=N; i++)
        scanf("%d%d",&BOOL[i].v,&BOOL[i].b);
    sort(BOOL+1,BOOL+N+1);
    for(ki=1;BOOL[ki].v>=C;ki++)
    {
        res+=BOOL[ki].b;
        BOOL[ki].b=0;
    }
    BOOL[0].v=C+1;
    dfs(ki,0);
    printf("%I64d\n",res);
    return 0;
}
