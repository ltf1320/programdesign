#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=10000000+100;
int N;
struct Node
{
    int x,w;
    bool operator<(const Node &a) const
    {
        return x<a.x;
    }
};
Node nds[maxn];



int main()
{
   // freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        LL S=0;
        for(int i=0;i<N;i++)
            scanf("%d",&nds[i].x);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&nds[i].w);
            S+=nds[i].w;
        }
        sort(nds,nds+N);
        LL ns=0;
        for(int i=0;i<N;i++)
        {
            ns+=nds[i].w;
            if(ns>=S/2)
            {
                printf("%d\n",nds[i].x);
                break;
            }
        }
    }

    return 0;
}
