#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000+100;
int N,M,A;
int per[maxn];
int cost[maxn];

int judge(int k)
{
    if(k>min(N,M))
        return -1;
    int percost=0,nA=A;
    for(int i=0;i<k;i++)
    {
        if(per[i]<cost[k-i-1])
        {
            nA-=cost[k-i-1]-per[i];
            if(nA<0)
                return -1;
        }
        percost+=min(cost[k-i-1],per[i]);
    }
    percost-=nA;
    return max(percost,0);
}

int main()
{
    scanf("%d%d%d",&N,&M,&A);
    for(int i=0;i<N;i++)
        scanf("%d",&per[i]);
    for(int i=0;i<M;i++)
        scanf("%d",&cost[i]);
    sort(per,per+N,greater<int>());
    sort(cost,cost+M);
    int l=0,r=min(N,M),m,t;
    while(r>=l)
    {
        m=(l+r)/2;
        t=judge(m);
        if(t==-1)
            r=m-1;
        else
            l=m+1;
    }
    if(r==0)
        puts("0 0");
    else
        printf("%d %d\n",r,judge(r));
    return 0;
}
