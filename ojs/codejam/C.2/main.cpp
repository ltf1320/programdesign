#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=40;
const int pn=39;
LL num[maxn]={1,
1,
2,
3,
11,
22,
101,
111,
121,
202,
212,
1001,
1111,
2002,
10001,
10101,
10201,
11011,
11111,
11211,
20002,
20102,
100001,
101101,
110011,
111111,
200002,
1000001,
1001001,
1002001,
1010101,
1011101,
1012101,
1100011,
1101011,
1102011,
1110111,
1111111,
2000002,
2001002
};
int find(LL n)
{
    if(n>=num[pn]) return pn;
    int l=0,r=pn;
    int m;
    while(true)
    {
        m=(r+l)/2;
        if(num[m]==n) return m;
        if(r-l<=1) return l;
        if(num[m]<n) l=m;
        else r=m;
    }
    return -1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int T;
    LL A,B;
    int cas=0;
    scanf("%d",&T);
    for(int i=0;i<=pn;i++)
        num[i]=num[i]*num[i];
    while(T--)
    {
        cas++;
        scanf("%I64d%I64d",&A,&B);
        printf("Case #%d: %d\n",cas,find(B)-find(A-1));
    }
    return 0;
}
