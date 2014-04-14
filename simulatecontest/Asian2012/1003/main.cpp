#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=800+10;
int n,k;
int stacks[maxn][maxn];
int tp[maxn];
int nums[maxn];
int tmp1[maxn],tmp2[maxn];
int *p1,*p2;
int change[maxn];
int gc[maxn];
//long long reses[maxn][maxn];

long long gcd(long long  a,long long b)
{
    long long t;
    for(;b;t=b,b=a%b,a=t);
    return a;

}

void instack()
{
    for(int i=0;i<k;i++)
        tp[i]=0;
    for(int i=0;i<n;i++)
        stacks[i%k][tp[i%k]++]=nums[i];
}

void outstack()
{
    int now=0;
    for(int i=0;i<n;i++)
    {
        if(tp[now]==0) now++;
        change[i]=stacks[now][--tp[now]];
    }
}


void next()
{
    for(int i=0;i<n;i++)
        p2[i]=p1[change[i]];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long res;
    int *t;
 //   memset(reses,0,sizeof(reses));
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0) break;
        if(n<=k)
        {
            printf("1\n");
            continue;
        }
 /*       if(reses[n][k])
        {
            printf("%lld\n",reses[n][k]);
            continue;
        }
 */
        for(int i=0;i<n;i++)
            nums[i]=i;
        instack();
        outstack();
        res=1;
        for(int i=0;i<n;i++)
            tmp1[i]=nums[i];
        p1=tmp1;
        p2=tmp2;
        memset(gc,0,sizeof(gc));
        for(int i=1;i<=n;i++)
        {
            next();
            for(int j=0;j<n;j++)
            {
                if(p2[j]==j&&!gc[j])
                {
                    gc[j]=i;
                }
            }
            t=p1;
            p1=p2;
            p2=t;
        }
        long long res=gc[0];
        for(int i=1;i<n;i++)
            res=res/gcd(res,gc[i])*gc[i];
 //       reses[n][k]=res;
        printf("%lld\n",res);
    }
    return 0;
}
