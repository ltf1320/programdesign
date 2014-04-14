#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e3+9,N=1000,mod=1e9+7;
int n,m,K;
int stack[maxn],end;
int dp[2][maxn][maxn],c[maxn][maxn];
int mm[maxn];
int gcd(int a,int b)
{
    int tmp;
    while(a%b)
    {
        tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
void get()
{
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    c[i][j]=i*j/gcd(i,j);
}
int main()
{
   freopen("in.txt","r",stdin);
    get();
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        end=0;
        for(int i=1;i<=m;i++)
        if(m%i==0)
        stack[++end]=i;
        memset(dp,0,sizeof(dp));
        int now=1,to=0;
        dp[to][1][0]=1;
        for(int k=0;k<K;k++)
        {
            now=now^1,to=to^1;

            for(int kk=1,i=stack[1];kk<=end;kk++,i=stack[kk])
            memset(dp[to][i],0,sizeof(dp[to][i]));

            for(int kk=1,i=stack[1];kk<=end;kk++,i=stack[kk])
            for(int j=0;j<=n;j++)
            if(dp[now][i][j])
            for(int p=1;p<=end&&stack[p]+j<=n;p++)
            if(c[i][stack[p]]<=m)
            {
//                cout<<c[i][stack[p]]<<endl;
                dp[to][c[i][stack[p]]][j+stack[p]]+=dp[now][i][j];
                if(dp[to][c[i][stack[p]]][j+stack[p]]>mod)
                dp[to][c[i][stack[p]]][j+stack[p]]-=mod;
            }
        }
//        cout<<tt<<endl;
        cout<<dp[to][m][n]<<endl;
    }
    return 0;
}
