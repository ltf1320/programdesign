#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
const int inf=0x3f3f3f3f;
int L,M,N;

int door[maxn];
int peo[maxn];

int res,rd;

int mabs(int a)
{
    return a>0?a:-a;
}

void check(int start)
{
    int ndoor=0;
    int now=0;
    for(int i=0;i<M;i++)
    {
        while(mabs(door[ndoor+1]+start-peo[i])<mabs(door[ndoor]+start-peo[i]))
            ndoor++;
        now+=mabs(door[ndoor]+start-peo[i]);
    }
    if(now>res)
    {
        res=now;
        rd=start;
    }
}

void work()
{
    L*=2;
    for(int i=0;i<M;i++)
        peo[i]*=2;
    for(int i=0;i<=N;i++)
        door[i]*=2;
    res=0;
    for(int i=0;i<=L-door[N-1];i++)
        check(i);
    printf("%.2f %.2f\n",1.0*rd/2,1.0*res/2);
}

void input()
{
    scanf("%d",&M);
    for(int i=0;i<M;i++)
        scanf("%d",&peo[i]);
    scanf("%d",&N);
    door[0]=0;
    for(int i=1;i<N;i++)
        scanf("%d",&door[i]);
    door[N]=inf;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&L))
    {
        input();
        work();
    }
    return 0;
}
