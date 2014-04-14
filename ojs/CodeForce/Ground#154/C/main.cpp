#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100+10;
int num[maxn];
int N;

inline int abs(int a)
{
    return a>0?a:-a;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int c1,r1,c2,r2;
    int res,now;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        num[i]++;
    }
    scanf("%d%d%d%d",&c1,&r1,&c2,&r2);
    res=abs(c1-c2)+abs(r1-r2);
    for(int i=1;i<=N;i++)
    {
        now=abs(c1-i)+abs(r2-num[i])+abs(c2-i);
        if(res>now) res=now;
    }
    printf("%d\n",res);
    return 0;
}
