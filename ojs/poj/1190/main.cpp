#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>

using namespace std;
const int inf=0x3f3f3f3f;
int N,M;
int res,now;
int q3[22];
int qs[22];

void dfs(int mr,int mh,int s,int lv)
{
    if(s>res) return;
    if(M==0)
    {
        if(lv==0) res=s;
        return;
    }
    if(lv<q3[M]) return;
    for(int nr=M;nr<mr;nr++)
    {
        if(lv*2/nr<qs[M])continue;
        for(int nh=min((lv-q3[M-1])/(nr*nr),mh-1);nh>=M;nh--)
        {
            if(nr*nr*nh*M<lv) continue;
            M--;
            dfs(nr,nh,s+2*nr*nh,lv-nr*nr*nh);
            M++;
        }
    }
}

int main()
{
    q3[0]=0;
    for(int i=1;i<=20;i++)
    {
        q3[i]=i*i*i;
        q3[i]+=q3[i-1];
        qs[i]=2*i*i;
        qs[i]+=qs[i-1];
    }
    scanf("%d%d",&N,&M);
    res=inf;
    dfs(N+1,N+1,0,N);
    if(res==inf)
        printf("0\n");
    else printf("%d\n",res);
    return 0;
}
