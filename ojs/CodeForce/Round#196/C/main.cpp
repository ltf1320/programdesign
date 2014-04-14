#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL MOD=1000000009;
LL p2[70];
int N,M,K;

void calp2()
{
    p2[0]=1;
    for(int i=1;i<60;i++)
        p2[i]=p2[i-1]*2;
}

bool judge(int q)
{
    if(q*K+2*K-q-2>M)
        return true;
    return false;
}

int getRes(int q)
{
    LL res=p2[q]*M-p2[q]*q*K+q*p2[q];
    res%=MOD;
    return (int)res;
}

int getStart()
{
    for(int i=0;i<=N/K;i++)
    {
        if((M-i*K)*K<=(N-i*K+1)*(K-1))
            return i;
    }
    return 0;
}


int main()
{
    calp2();
    scanf("%d%d%d",&N,&M,&K);
    int q;
    for(q=getStart();q<M/K;q++)
    {
        if(!judge(q))
            break;
    }
    printf("%d\n",getRes(q));
    return 0;
}
