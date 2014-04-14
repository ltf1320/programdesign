#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 1000000007
typedef long long LL;
LL mod_exp(LL a,int b)
{
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
LL fac[10000],nfac[10000];
int flag[1010];
int a[1000];
int main()
{
    int n, m;
    fac[1]=nfac[1]=1;
    fac[0]=nfac[0]=1;
    for(int i=2;i<=1000;i++){
        fac[i]=fac[i-1]*i%mod;
        nfac[i]=mod_exp(fac[i],mod-2);
    }
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++)
        scanf("%d", &a[i]);
    sort(a, a + m);
    long long ans = 1;
    for (int i = 1; i < m; ++i)
    {
        if (a[i] > a[i - 1] + 1)
            ans *= mod_exp(2, a[i] - a[i - 1] - 2);
        ans %= mod;
    }
    for (int i = 1; i < m; ++i)
        ans = ans * nfac[a[i] - a[i - 1] - 1] % mod;
    ans = ans * nfac[a[0] - 1] % mod * nfac[n - a[m - 1]] % mod;
    ans = ans * fac[n - m] % mod;
    printf("%I64d\n", ans);
    return 0;
}
