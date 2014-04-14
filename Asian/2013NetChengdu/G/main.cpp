#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10+10;
int A,B;
int res;
int p10[maxn];
int p2[maxn];

void pre()
{
    p10[0]=1;
    for(int i=1;i<10;i++)
        p10[i]=p10[i-1]*10;
    for(int i=0;i<10;i++)
        p2[i]=1<<i;
}
int num[maxn];
int div(int n)
{
    int res=0;
    while(n)
    {
        num[res]=n%10;
        n/=10;
        res++;
    }
    return res;
}

void work()
{
    int len=div(B);
    int t;
    res=1;
    bool flag=0;
    for(int i=len-1;i>=0;i--)
    {
        t=A/p2[i];
        if(num[i]<t)
        {
            if(flag)
                res+=t*p10[i];
            else res+=num[i]*p10[i];
            continue;
        }
        else
        {
            flag=1;
            A-=t*p2[i];
            if(t)
                res+=(t-1)*p10[i];
        }
    }
    printf("%d\n",res);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    pre();
    int cas=0;
    while(T--)
    {
        cas++;
        scanf("%d%d",&A,&B);
        printf("Case #%d: ",cas);
        work();
    }
    return 0;
}
