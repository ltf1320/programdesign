#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N;

struct MAN
{
    int d,p;
    bool operator<(const MAN &a)const
    {
        return d>a.d;
    }
};
MAN man[maxn][maxn];

int dk[maxn*maxn];
int ms[maxn];
set<int> intset;
int dp[maxn][maxn*maxn];
int dkn;

int find(int n)
{
    int l=0,r=dkn;
    int m=(l+r)>>1;
    while(true)
    {
        m=(l+r)>>1;
        if(n==dk[m]) return m;
        if(r-l<=1) return -1;
        if(n>dk[m])
            l=m;
        else r=m;
    }
}


void input()
{
    scanf("%d",&N);
    int d,p,m;
    intset.clear();
    dkn=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&m);
        ms[i]=m;
        for(int j=0; j<m; j++)
        {
            scanf("%d%d",&d,&p);
            intset.insert(d);
            man[i][j].d=d;
            man[i][j].p=p;
        }
    }
    for(set<int>::iterator iter=intset.begin(); iter!=intset.end(); iter++)
    {
        dk[dkn++]=*iter;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=dkn; j++)
            dp[i][j]=inf;
    }
    for(int i=0;i<N;i++)
        sort(man[i],man[i]+ms[i]);
}

float work()
{
    int k1,k2,mm;
    k1=find(man[0][0].d);
    dp[0][k1]=man[0][0].p;
    for(int j=1; j<ms[0]; j++)
    {
        k2=find(man[0][j].d);
        for(int k=k2; k<k1; k++)
            dp[0][k]=dp[0][k1];
        dp[0][k2]=min(dp[0][k2],man[0][j].p);
        k1=k2;
    }
    for(int j=0; j<k1; j++)
        dp[0][j]=dp[0][k1];
    for(int i=1; i<N; i++)
    {
        k1=find(man[i][0].d);
        dp[i][k1]=man[i][0].p+dp[i-1][k1];
        mm=man[i][0].p;
        for(int j=1; j<ms[0]; j++)
        {
            k2=find(man[i][j].d);
            for(int k=k2; k<k1; k++)
                dp[i][k]=dp[i-1][k]+mm;
            dp[i][k2]=min(dp[i][k2],dp[i-1][k2]+man[i][j].p);
            if(mm>man[i][j].p) mm=man[i][j].p;
            k1=k2;
        }
        for(int j=0; j<k1; j++)
            dp[i][j]=dp[i-1][k1]+mm;
    }
    float res=0.0;
    for(int i=0; i<dkn; i++)
    {
        if(1.0*dk[i]/dp[N-1][i]>res)
            res=1.0*dk[i]/dp[N-1][i];
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        input();
        printf("%.3f\n",work());
    }
    return 0;
}
