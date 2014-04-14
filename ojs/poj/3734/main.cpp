#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=4;
const int MOD=10007;
int N;


struct Ma
{
    int arr[maxn][maxn];
    Ma operator*(const Ma &a)
    {
        Ma res;
        for(int i=0; i<maxn; i++)
        {
            for(int j=0; j<maxn; j++)
            {
                res.arr[i][j]=0;
                for(int k=0; k<maxn; k++)
                {
                    res.arr[i][j]+=arr[i][k]*a.arr[k][j];
                    if(res.arr[i][j]>=MOD) res.arr[i][j]%=MOD;
                }
            }
        }
        return res;
    }
    Ma operator^(int n)
    {
        Ma res,now=*this;
        memset(res.arr,0,sizeof(res.arr));
        for(int i=0; i<maxn; i++)
            res.arr[i][i]=1;
        while(n)
        {
            if(n&1)
                res=res*now;
            now=now*now;
            n>>=1;
        }
        return res;
    }
};

/*
2,1,1,0
1,2,0,1
1,0,2,1
0,1,1,2
*/

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    Ma dp,now;
    memset(dp.arr,0,sizeof(dp.arr));
    for(int i=0; i<maxn; i++)
        dp.arr[i][i]=2;
    for(int j=1;j<3;j++)
        dp.arr[0][j]=dp.arr[j][0]=dp.arr[3][j]=dp.arr[j][3]=1;
    while(T--)
    {
        Ma start;
        memset(start.arr,0,sizeof(start.arr));
        start.arr[0][0]=1;
        scanf("%d",&N);
        now=dp^N;
        now=start*now;
        printf("%d\n",now.arr[0][0]);
    }
    return 0;
}
