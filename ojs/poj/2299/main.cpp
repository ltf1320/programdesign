#include <cstdio>

using namespace std;
const long long maxn=500000+100;
long long num[maxn];
long long c[maxn];
long long L[maxn];
long long R[maxn];

long long cn;
void UquickSort(long long l,long long r)
{
    if(l==r-1) return;
    long long m=(l+r)/2;
    UquickSort(l,m);
    UquickSort(m,r);
    long long ln(0),rn(0);
    for(long long i=l;i<m;i++)
        L[ln++]=num[i];
    for(long long i=m;i<r;i++)
        R[rn++]=num[i];
    long long lk=0,an=l;
    for(long long i=0;i<rn;i++)
    {
        for(;lk<ln;lk++)
        {
            if(L[lk]<=R[i])
            {
                num[an]=L[lk];
                an++;
            }
            else break;
        }
        cn+=ln-lk;
        num[an]=R[i];
        an++;
    }
    for(;lk<ln;lk++)
    {
        num[an]=L[lk];
        an++;
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    long long k;
    while(scanf("%lld",&k)!=EOF)
    {
        if(k==0) break;
        for(long long i=0;i<k;++i)
            scanf("%d",&num[i]);
        cn=0;
        UquickSort(0,k);
        printf("%lld\n",cn);
    }
    return 0;
}
