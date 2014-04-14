#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

int minN[10];
int maxN[10];
LL p10[10];
LL sum[10];

void pre()
{
    p10[0]=1;
    for(int i=1;i<10;i++)
        p10[i]=p10[i-1]*10;
    minN[0]=4;
    for(int i=1;i<10;i++)
        minN[i]=minN[i-1]*10+4;
    maxN[0]=7;
    for(int i=1;i<10;i++)
        maxN[i]=maxN[i-1]*10+7;
    sum[0]=0;
    for(int i=1;i<10;i++)
    {
        sum[i]+=10*sum[i-1];
        sum[i]+=4*p10[i-1]*(minN[i-1]-p10[i-1]+1);
        sum[i]+=7*p10[i-1]*(maxN[i-1]-minN[i-1]);
        sum[i]+=44*p10[i-1]*(p10[i]-maxN[i-1]-1);
    }
}

LL getSum(int n)
{
    LL res=0;
    for(int k=1;n;n/=10,k++)
    {
        int now=n%10;
        res+=now*sum[k-1];
        res+=(min(now,4))*4*p10[k-1];
        if(now>4)
        {
            res+=(min(now,7)-4)*7*p10[k-1];
        }
        if(now>7)
        {
            res+=(now-7)*44*p10[k-1];
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int l,r;
    pre();
    while(~scanf("%d",&r))
    {
        cout<<getSum(r)<<endl;
    }
}
