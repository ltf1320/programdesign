#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn=1000+10;
LL num[maxn];
int pn;

bool judge(LL n)
{
    LL re=0,kn=n;
    while(kn)
    {
        re=re*10+kn%10;
        kn/=10;
    }
    if(re!=n) return false;
    return true;
}

int find(LL n)
{
    int l=0,r=pn;
    int m;
    while(true)
    {
        m=(r+l)/2;
        if(num[m]==n) return m+1;
        if(r-l<=1) return l;
        if(num[m]<n) l=m;
        else r=m;
    }
    return -1;
}

int main()
{
    freopen("out.txt","w",stdout);
    for(LL i=1;i*i<=1E16L;i++)
    {
        if(judge(i)&&judge(i*i))
        {
            num[pn++]=i;
        }
    }
    printf("%d\n",pn);
    for(int i=0;i<pn;i++)
        printf("%I64d,\n",num[i]);
    return 0;
}
