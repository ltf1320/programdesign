#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1000000+100;
LL N,M;

int cnt[maxn][50];
char str1[maxn];
char str2[maxn];
LL l1,l2,len,p;

LL gcd(LL a,LL b)
{
    LL t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    scanf("%I64d%I64d",&N,&M);
    scanf("%s%s",str1,str2);
    l1=strlen(str1);
    l2=strlen(str2);
    LL gc=gcd(l1,l2);
    len=l1/gc*l2;
    p=N*l1/len;

    for(int i=0;i<l1;i++)
        cnt[i%gc][str1[i]-'a']++;
    LL res=len;
    for(int i=0;i<l2;i++)
        res-=cnt[i%gc][str2[i]-'a'];
    printf("%I64d\n",res*p);

    return 0;
}
