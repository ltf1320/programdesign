#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2000;
bool zs[maxn];

int dp[70][70][maxn];
int N;
long long res;
void pre()
{
    int k[maxn];
    int kn;
    kn=1;
    k[0]=2;
    memset(zs,0,sizeof(zs));
    for(int i=2; i<maxn; i+=2)
        zs[i]=1;
    for(int i=3; i<maxn; i++)
    {
        if(zs[i])
        {
            zs[i]=0;
        }
        else
        {
            k[kn++]=i;
            for(int j=i; j<maxn; j+=2*i)
                zs[j]=1;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(~scanf("%d",&N))
    {
        res=0;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=N; i++)
            dp[N][i][i]=1;
        for(int i=N-1; i>0; i--)
            for(int j=1; j<=i; j++)
                for(int k=j+1; k<maxn; k++)
                    dp[i][j][k]=dp[i+1][j][k-j]+dp[i+1][j+1][k-j];
        for(int i=1; i<maxn; i++)
            if(zs[i])
                res+=dp[1][1][i];
        cout<<res<<endl;
    }
    return 0;
}
