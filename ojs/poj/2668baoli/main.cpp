#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int D,N;
LL res;

int find(int now,int dam)
{
    int l=now,r=N;
    int m;
    while(r>=l)
    {
        m=(l+r)>>1;
        if(ceil(1.0*D/m)>dam)
            l=m+1;
        else r=m-1;
    }
    return l;
}



int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int now;
    while(~scanf("%d%d",&D,&N))
    {
        if(D==0&&N==0) break;
        res=0;
        for(int i=1;i<=N;i++)
        {
            now=ceil(1.0*D/i);
            res+=now;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
