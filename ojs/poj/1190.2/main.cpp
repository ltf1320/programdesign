#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#include <set>


using namespace std;

const int maxn=10000+10;
const int inf=0x3f3f3f3f;
int N,M;
int res;
void dfs(int m,int lr,int lh,int s,int ln)
{
    //
    int sn=0,ss=0;
    for(int i=0;i<M;i++)
    {
        if(i==M-1)
            ss+=sqrt(1.0*ln-sn);
        sn+=(lh+i+1)*(lr+i+1)*(lr+i+1);
        ss+=2*(lr+i+1)*(lh+i+1);
    }
    if(sn>ln) return;
    if(ss>=res) return;
    //
    int mr=sqrt(1.0*ln/(lh+1)/m)+1;
    int mh;
    if(m==M)
    {
        for(int r=lr+1;r<=mr;r++)
        {
            if(ln%(r*r)==0)
            {
                mh=ln/r/r;
                res=min(res,s+2*r*mh+r*r);
            }
        }
        return;
    }
    for(int r=lr+1;r<=mr;r++)
    {
        mh=1.0*ln/r/r;
        for(int h=lh+1;h<=mh;h++)
        {
            dfs(m+1,r,h,s+2*r*h,ln-r*r*h);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    res=inf;
    dfs(1,0,0,0,N);
    if(res==inf)
        printf("0\n");
    else printf("%d\n",res);
    return 0;
}
