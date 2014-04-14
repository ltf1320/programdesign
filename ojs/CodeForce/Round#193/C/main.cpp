#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
const int inf=0x3f3f3f3f;
int N,P,K;

struct CP
{
    int a,b;
    int id,bx;
    bool ced;
};
CP cps[maxn];

bool cmpb(const CP &a,const CP &b)
{
    if(a.b==b.b)
        return a.a<b.a;
    return a.b<b.b;
}

bool cmpa(const CP &a,const CP &b)
{
    if(a.a==b.a)
        return a.b>b.b;
    return a.a>b.a;
}

int ans[maxn],ansn;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&P,&K);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&cps[i].a,&cps[i].b);
        cps[i].id=i;
    }
    sort(cps+1,cps+N+1,cmpb);
    for(int i=1;i<=N;i++)
    {
        cps[i].bx=i;
    }
    sort(cps+1,cps+N+1,cmpa);
    int paohui=P-K,chose=K;
    int maxd=-inf;
    for(int i=1;i<=N;i++)
    {
        if(!chose) break;
        if(cps[i].bx<=P-K)
        {
            chose--;
            ans[ansn++]=cps[i].id;
            cps[i].ced=1;
            maxd=max(maxd,cps[i].b);
        }
    }
    sort(cps+1,cps+1+N,cmpb);
    for(int i=N;i>0;i--)
    {
        if(cps[i].b<maxd) continue;
        if(!paohui) break;
        if(!cps[i].ced)
        {
            paohui--;
            ans[ansn++]=cps[i].id;
            cps[i].ced=1;
        }
    }
    for(int i=0;i<ansn-1;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[ansn-1]);
    return 0;
}
