#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define p2(x) ((x)*(x))
using namespace std;
const int maxn=500+10;
int N,M,R
int has[maxn][maxn];

void pre()
{
    int d,l,r;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            for(int k=max(0,i-R),k<min(N-1,i+R);k++)
            {
                d=sqrt(p2(R)-p2(i-k));
                l=max(j-d,0);
                r=min(M-1,j+d);
                dp[i][j]+=r-l+1;
            }
        }
}


int main()
{
    scanf("%d%d",&N,&M,&R);
    pre();

    return 0;
}
