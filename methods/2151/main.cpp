//dp+数学题
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;

float p[maxn][2];//0 for no more than one,1 for more than N
float tmp[30+5];
int M,T,N;

float dp[30+5][30+5];//dp[i][j]为做第i题的时候做出j道的概率

int main()
{
    freopen("in.txt","r",stdin);
    float onep,np,res;
    while(~scanf("%d%d%d",&M,&T,&N))
    {
        if(!(M||T||N)) break;
        for(int i=0;i<T;i++)
        {
            for(int j=0;j<M;j++)
                scanf("%f",&tmp[j]);
            p[i][0]=1.0;
            for(int j=0;j<M;j++)
                p[i][0]*=1-tmp[j];
            p[i][0]=1-p[i][0];
            memset(dp,0,sizeof(dp));
            dp[1][1]=tmp[0];
            dp[1][0]=1-tmp[0];
            for(int j=2;j<=M;j++)
            {
                dp[j][0]=dp[j-1][0]*(1-tmp[j-1]);
                for(int k=1;k<=j;k++)
                    dp[j][k]=dp[j-1][k]*(1-tmp[j-1])+dp[j-1][k-1]*tmp[j-1];
            }
            p[i][1]=0;
            for(int j=1;j<N;j++)
                p[i][1]+=dp[M][j];
        }
        onep=1.0;
        for(int i=0;i<T;i++)
            onep*=p[i][0];
        np=1.0;
        for(int i=0;i<T;i++)
            np*=p[i][1];
        res=onep-np;//补集...这个概念实在比较难想
        printf("%.3f\n",res);
    }
    return 0;
}
