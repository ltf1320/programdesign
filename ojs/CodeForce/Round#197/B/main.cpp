#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
typedef long long LL;
int N,M;

int getDis(int f,int t)
{
    if(t>=f) return t-f;
    else return t+N-f;
}


int main()
{
    scanf("%d%d",&N,&M);
    int now,nxt;
    now=1;
    LL res=0;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&nxt);
        res+=getDis(now,nxt);
        now=nxt;
    }
    printf("%I64d\n",res);
    return 0;
}
