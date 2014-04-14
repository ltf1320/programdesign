#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=20000+100;
LL N,B;
LL hs[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    LL sum,res;
    while(~scanf("%I64d%I64d",&N,&B))
    {
        for(int i=0;i<N;i++)
            scanf("%I64d",&hs[i]);
        sort(hs,hs+N);
        sum=0;
        for(int i=N-1;i>=0;i--)
        {
            sum+=hs[i];
            if(sum>=B)
            {
                res=N-i;
                break;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
