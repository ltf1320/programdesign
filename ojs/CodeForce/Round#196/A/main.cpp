#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=55;
const int inf=0x3f3f3f3f;
int N,M;
int num[maxn];

int mabs(int a)
{
    return a>0?a:-a;
}

int main()
{
    int res=inf;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d",&num[i]);
    sort(num,num+M);
    for(int i=N-1;i<M;i++)
        res=min(res,mabs(num[i]-num[i-N+1]));
    printf("%d\n",res);
    return 0;
}
