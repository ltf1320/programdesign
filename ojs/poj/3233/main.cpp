#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30+10;
int N,K,M;

struct Mat
{
    int arr[maxn][maxn];
    Mat operator*(const Mat &a)
    {
        Mat res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                res.arr[i][j]=0;
                for(int k=0;k<N;k++)
                    res.arr[i][j]+=arr[i][k]*a.arr[k][j]%M;
                res.arr[i][j]%=M;
            }
        return res;
    }
    Mat operator+(const Mat &a)
    {
        Mat res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                res.arr[i][j]=(arr[i][j]+a.arr[i][j])%M;
        return res;
    }
    Mat operator^(int n)
    {
        Mat res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(i==j) res.arr[i][j]=1;
                else res.arr[i][j]=0;
        Mat now=*this;
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
Mat mt,ONE;

Mat solve(int n)
{
    if(n==1)
        return mt;
    else if(n%2)
        return mt+mt*(ONE+(mt^(n/2)))*solve(n/2);
    else return (ONE+(mt^(n/2)))*solve(n/2);
}

int main()
{
    freopen("in.txt","r",stdin);
    Mat res;
    scanf("%d%d%d",&N,&K,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ONE.arr[i][j]=(i==j);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&mt.arr[i][j]);
    res=solve(K);
    for(int i=0;i<N;i++)
    {
        printf("%d",res.arr[i][0]);
        for(int j=1;j<N;j++)
            printf(" %d",res.arr[i][j]);
        putchar('\n');
    }
    return 0;
}
