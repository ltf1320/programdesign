#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=100000+10;
int N,Q;
int num[maxn];
int start[maxn];;
int change[maxn];
int nn;
int dp[maxn][20];
int p2[20];
void pre()
{
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
}

int find2(int n)
{
    return (int)(1.0*log(n+1)/log(2.0));
}

void RMQ()
{
    for(int i=1; i<=nn; i++)
        dp[i][0]=num[i];
    for(int j=1; p2[j-1]<=nn; j++)
    {
        for(int i=1; i<=nn-p2[j-1]; i++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i+p2[j-1]][j-1]);
        }
    }
    /*
    for(int i=1; i<=nn; i++)
    {
        for(int j=0; j<5; j++)
            printf("%d ",dp[i][j]);
        putchar('\n');
    }
    */
}

void input()
{
    int tmp,pre;
    nn=1;
    scanf("%d",&pre);
    num[nn]=1;
    change[1]=1;
    start[1]=1;
    for(int i=2; i<=N; i++)
    {
        scanf("%d",&tmp);
        if(tmp==pre)
            num[nn]++;
        else
        {
            nn++;
            num[nn]=1;
            start[nn]=i;
            pre=tmp;
        }
        change[i]=nn;
    }
}

int query(int a,int b)
{
    int ca=change[a],cb=change[b];
    int res=max(min(b+1,start[ca]+num[ca])-a,b-max(a,start[cb])+1); //max
    ca++;cb--;//!!
    if(ca<cb)
    {
        int pp=find2(cb-ca);
        res=max(res,max(dp[ca][pp],dp[cb-p2[pp]+1][pp]));
    }
    if(ca==cb) res=max(res,num[ca]);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    pre();
    while(~scanf("%d%d",&N,&Q)&&N)
    {
        input();
        RMQ();
        for(int i=0; i<Q; i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}
