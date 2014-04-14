#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

LL dp[3][3][3][50];
LL cost[3][3];


LL hano(int i,int j,int k,int n)
{
    if(n==0)
        return 0;
    if(dp[i][j][k][n]!=-1)
        return dp[i][j][k][n];
    dp[i][j][k][n]=0;
    LL tmp;
    tmp=hano(i,k,j,n-1)+cost[i][j]+hano(k,j,i,n-1);

    tmp=min(tmp,
            min(hano(i,j,k,n-1),hano(i,k,j,n-1)+hano(k,j,i,n-1))+cost[i][k]+hano(j,i,k,n-1)+cost[k][j]+min(hano(i,j,k,n-1),hano(i,k,j,n-1)+hano(k,j,i,n-1)));
    tmp=min(tmp,
            hano(i,j,k,n-1)+hano(j,k,i,n-1)+cost[i][j]+hano(k,j,i,n-1));
    dp[i][j][k][n]+=tmp;
    return dp[i][j][k][n];
}

int main()
{
  //  freopen("in.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>cost[i][j];
    int n;
    cin>>n;
    LL res=hano(0,2,1,n);
    cout<<res<<endl;
    return 0;
}
