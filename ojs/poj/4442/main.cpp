#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn=100000+100;
const LL MOD=365*24*60*60;
int N;
struct Node
{
    LL a,b;
    bool operator<(const Node &s)const
    {
        return a*s.b<b*s.a;
    }
};
Node nds[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    LL T;
    while(~scanf("%d",&N))
    {
        if(!N) break;
        for(int i=0;i<N;i++)
            scanf("%I64d%I64d",&nds[i].a,&nds[i].b);
        sort(nds,nds+N);
        T=0;
        for(int i=0;i<N;i++)
        {
            T+=nds[i].a+nds[i].b*T;
            if(T>=MOD) T%=MOD;
        }
        printf("%I64d\n",T);
    }
    return 0;
}
