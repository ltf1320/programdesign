#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1000000+100;
LL N,M,len,p,gc;
LL res;
char *str1;
char *str2;
int len1,len2;
int vis[maxn];

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

int compare(int s2)
{
    int res=0;
    for(int i=0;i<len1;i++)
    {
        if(str1[i]!=str2[(s2+i)%len2])
            res++;
    }
    return res;
}

char _str1[maxn];
char _str2[maxn];

int main()
{
    str1=_str1;
    str2=_str2;
    scanf("%I64d%I64d",&N,&M);
    gc=gcd(N,M);
    scanf("%s%s",str1,str2);
    len1=strlen(str1);
    len2=strlen(str2);
    len=len1/gcd(len1,len2)*len2;
    p=N*len1/len;
    if(len1>len2)
    {
        LL t=len1;
        len1=len2;
        len2=t;

        char *tt=str1;
        str1=str2;
        str2=tt;
    }
    for(int i=0;;i+=len1)
    {
        if(i>=len2)
            i=i%len2;
        if(vis[i]) break;
        vis[i]=1;
        res+=compare(i);
    }
    res*=p;
    printf("%I64d\n",res);
    return 0;
}
