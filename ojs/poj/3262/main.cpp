#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000+100;
int N;
struct Momo
{
    int t,d;
    bool operator<(const Momo &a)const
    {
        return (1.0*t/d)<(1.0*a.t/a.d);
    }
};
Momo BOOL[maxn];
int main()
{
    scanf("%d",&N);
    LL res=0;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&BOOL[i].t,&BOOL[i].d);
        sum+=BOOL[i].d;
    }
    sort(BOOL,BOOL+N);
    for(int i=0;i<N;i++)
    {
        sum-=BOOL[i].d;
        res+=sum*BOOL[i].t*2;
    }
    printf("%I64d\n",res);
    return 0;
}
