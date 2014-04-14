#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50000+100;
int T,N;
int mabs(int a)
{
    return a>0?a:-a;
}

struct lM
{
    int x;
    bool operator<(const lM &a) const
    {
        return mabs(x)<mabs(a.x);
    }
};
lM ls[maxn];


int main()
{
    scanf("%d%d",&T,&N);
    ls[0].x=0;
    for(int i=1;i<=N;i++)
        scanf("%d",&ls[i].x);
    sort(ls,ls+N);
    for(int i=1;i<=N;i++)
    {
        T-=mabs(ls[i].x-ls[i-1].x);
        if(T<0)
        {
            printf("%d\n",i-1);
            break;
        }
    }
    return 0;
}
