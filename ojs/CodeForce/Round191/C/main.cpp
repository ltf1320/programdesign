#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+1000;
const int MOD=1000000007;
LL q;

LL pow(int a,int b)
{
    LL now=a,res=1;
    while(b)
    {
        if(b&1)
        {
            res*=now;
            res%=MOD;
        }
        now*=now;
        now%=MOD;
        b>>=1;
    }
    return res;
}

LL solve(int n)
{
    if(n==0) return 0;
    if(n==1)
        return q;
    else if(n%2)
        return (q+(q*(1+pow(q,n/2))%MOD)*solve(n/2)%MOD)%MOD;
    else return (1+pow(q,n/2))*solve(n/2)%MOD;
}


int main()
{
    freopen("in.txt","r",stdin);
    char str[maxn];
    int len;int k;
    LL res=0;
    gets(str);
    scanf("%d",&k);
    len=strlen(str);
    q=pow(2,len);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0'||str[i]=='5')
            res+=(pow(2,i)+pow(2,i)*solve(k-1)%MOD)%MOD;
        res%=MOD;
    }
    cout<<res<<endl;
    return 0;
}
