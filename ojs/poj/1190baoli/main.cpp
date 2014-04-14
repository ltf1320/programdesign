#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=10000+100;
const int inf=0x3f3f3f3f;
int N,M;
int res;

void dfs(int m,int lv,int mr,int mh,int s)
{
    if(m==0)
    {
        if(lv==0)
            res=min(res,s);
        return;
    }
    if(lv<0) return;
    for(int r=m;r<mr;r++)
        for(int h=m;h<mh;h++)
        {
            if(m==M) s=r*r;
            dfs(m-1,lv-r*r*h,r,h,s+2*r*h);
        }
}


int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    res=inf;
    dfs(M,N,sqrt(1.0*N)+1,N+1,0);
    if(res==inf)
        printf("0\n");
    else printf("%d\n",res);
    return 0;
}
