#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=10000+100;
const int inf=0x3f3f3f3f;
int N;
int num[maxn];
struct PP
{
    int num,i;
    bool operator<(const PP &a)const
    {
        return num<a.num;
    }
};
PP ps[maxn];
int MIN;
bool vis[maxn];
void work()
{
    LL res(0),sum;
    int mm;
    sort(ps,ps+N);
    int now,ct;
    for(int i=0;i<N;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        now=ps[i].i;
        mm=sum=num[i];
        ct=1;
        while(now!=i)
        {
            vis[now]=1;
            ct++;
            mm=min(num[now],mm);
            sum+=num[now];
            now=ps[now].i;
        }
        res+=min(sum+(ct-2)*mm,sum+mm+(ct+1)*MIN);
    }
    printf("%I64d\n",res);
}

void input()
{
    MIN=inf;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        ps[i].num=num[i];
        ps[i].i=i;
        MIN=min(MIN,num[i]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        input();
        work();
    }
    return 0;
}
