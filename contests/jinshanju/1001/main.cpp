#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000000+10;
bool su[maxn];
int pri[maxn];
int prin;

int a[maxn];
int sum[maxn];

bool judge(int a)
{
    int sum=0;
    while(a)
    {
        sum+=a%10;
        a/=10;
    }
    return su[sum];
}
void pre()
{
    prin=1;
    pri[0]=2;
    su[2]=1;
    for(int i=4;i<maxn;i+=2)
        su[i]=1;
    for(int i=3;i<maxn;i++)
        if(!su[i])
        {
            pri[prin++]=i;
            for(int j=i;j<maxn;j+=i)
                su[j]=1;
        }
        else su[i]=0;
    for(int i=0;i<prin;i++)
        if(judge(pri[i]))
            a[pri[i]]=1;
    sum[0]=a[0];
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+a[i];
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    int T;
    scanf("%d",&T);
    int cas=0;
    int l,r;
    while(T--)
    {
        cas++;
        scanf("%d%d",&l,&r);
        printf("Case #%d: %d\n",cas,sum[r]-sum[l-1]);
    }
    return 0;
}
