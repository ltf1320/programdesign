#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=2000+100;
const int MOD=1E9+7;
int N,K;
char str[maxn];
LL p26[maxn];

struct DP
{
    int nk;
    LL num;
};
DP dps[maxn];

LL res;

void dfs(int now,int nk,int sum)
{
    if(nk>K)
        return;
    if(nk==K)
    {
        res+=sum;
        res%=MOD;
        return;
    }
    if(now==N)
        return;
    dfs(now+1,nk,sum);
    dfs(now+1,nk+dps[now].nk,(sum+dps[now].num)%MOD);
}

void pre()
{
    p26[0]=1;
    for(int i=1;i<maxn;i++)
    {
        p26[i]=p26[i-1]*26;
        p26[i]%=MOD;
    }
}

void AC()
{
    for(int i=0;i<N;i++)
    {
        dps[i].nk=(N-i)*(i+1);
        dps[i].num=('z'-str[i])*p26[N-i-1];
        dps[i].num%=MOD;
    }
    res=0;
    dfs(0,0,0);
    printf("%I64d\n",res);
}

void input()
{
    scanf("%s",str);
}


int main()
{
    pre();
    scanf("%d%d",&N,&K);
    input();
    AC();
    return 0;
}
