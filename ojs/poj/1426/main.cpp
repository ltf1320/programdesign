#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const __int64 inf =(__int64)1<<60;
using namespace std;

const int maxn=100+10;
const int end=20;
int n;
/*
queue<__int64> que;

void bfs()
{
    __int64 nx;
    while(!que.empty())
    {
        nx=que.front();
        que.pop();
        if(nx%n)
        {
            que.push(nx*10+1);
            que.push(nx*10);
        }
        else
        {
            printf("%lld\n",nx);
            return;
        }
    }
    return ;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        while(!que.empty()) que.pop();
        que.push(1);
        bfs();
    }
    return 0;
}
*/

__int64 now;
void plusOne()
{
    __int64 tmp=10;
    while(true)
    {
        if((__int64)now%tmp>=tmp/10)
        {
            now-=tmp/10;
        }
        else break;
        tmp*=10;
    }
    now+=tmp/10;
}

int main()
{
 //   freopen("in.txt","r",stdin);
 //   while(~scanf("%d",&n))
 //   {
  //      if(!n) break;
        now=1;
       while(now<inf)
            plusOne();
        printf("%I64d\n",now);
        printf("%I64d\n",inf);
//    }
    return 0;
}
