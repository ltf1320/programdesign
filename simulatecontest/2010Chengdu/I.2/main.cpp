#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=50000+100;
int N,K;
LL m[maxn];
LL dp[maxn][];
int que[maxn];
int head,tail;

LL getUp(int i,int j)
{
    return dp[i]+p2[i]-(dp[j]+p2[j]);
}

LL getDown(int i,int j)
{
    return 2*(j-k);
}


int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<maxn;i++)
        p2[i]=i*i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        printf("%d\n",work());
    }
    return 0;
}
