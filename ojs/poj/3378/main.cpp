#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=50000+100;
const long long MOD=1E12;
struct LL
{
    long long a,b;
    LL(){}
    LL(long long k):b(k)
    {
        a=b/MOD;
        b=b%MOD;
    }
    LL operator+(const LL &k)
    {
        LL res;
        res.b=b+k.b;
        res.a=a+k.a+res.b/MOD;
        res.b%=MOD;
        return res;
    }
    void operator+=(const LL &k)
    {
        *this=*this+k;
    }
    void print()
    {
        if(a) printf("%I64d%012I64d",a,b);
        else printf("%I64d",b);
    }
};

int N;
int num[maxn];
int tt[maxn];
LL dp[10][maxn];
map<int,int> mp;
int lowbit(int n)
{
    return n&(-n);
}

LL sum(int len,int n)
{
    LL res(0);
    for(;n>0;n-=lowbit(n))
        res+=dp[len][n];
    return res;
}

void add(int len,int n,LL a)
{
    for(;n<=N;n+=lowbit(n))
        dp[len][n]+=a;
}

void lisan()
{
    mp.clear();
    for(int i=0;i<N;i++)
        tt[i]=num[i];
    sort(tt,tt+N);
    for(int i=0;i<N;i++)
        mp.insert(make_pair(tt[i],i+1));
}

LL work()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++)
    {
        add(1,mp[num[i]],LL(1));
        for(int j=2;j<6;j++)
        {
            add(j,mp[num[i]],sum(j-1,mp[num[i]]-1));
        }
    }
    return sum(5,N);
}

int main()
{
    freopen("in.txt","r",stdin);
    LL res;
    while(~scanf("%d",&N))
    {
        for(int i=0;i<N;i++)
            scanf("%d",&num[i]);
        lisan();
        res=work();
        res.print();[]
        putchar('\n');
    }
    return 0;
}
