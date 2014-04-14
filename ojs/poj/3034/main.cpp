#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double err=1E-7;
const int xz=20;
int N,d,M;
int maxt;
int dp[10+5][40+5][40+5];
bool map[10+5][40+5][40+5];

int ft(int x,int y,int t)
{
    int kk;
    int res=0;
    for(int i=max(0,x-d); i<=min(N-1+d+d,x+d); i++)
        for(int j=max(0,y-d); j<=min(N-1+d+d,y+d); j++)
        {
            if(sqrt(1.0*(i-x)*(i-x)+(j-y)*(j-y))<=d+err)
            {
                kk=0;
                for(int k=min(i,x); k<=max(i,x); k++)
                    for(int p=min(j,y); p<=max(j,y); p++)if(map[t][k][p]){
                        if((k==x&&p==y)||(k==i&&p==j)) kk++;
                        else if(((0.0+k-x)/(0.0+p-y)<=(0.0+i-k)/(0.0+j-p)+err)&&((0.0+k-x)/(0.0+p-y)+err>=(0.0+i-k)/(0.0+j-p))) kk++;
                    }
                if(kk+dp[t+1][i][j]>res) res=kk+dp[t+1][i][j];
            }
        }
    return res;
}


int work()
{
    for(int t=maxt; t>0; t--)
    {
        for(int i=0; i<N+d+d; i++)
        {
            for(int j=0; j<N+d+d; j++)
            {
                dp[t][i][j]=ft(i,j,t);
            }
        }
    }
    int res=0;
    for(int i=0;i<N+d+d;i++)
        for(int j=0;j<N+d+d;j++)
            if(dp[1][i][j]>res) res=dp[1][i][j];
    return res;
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(map,0,sizeof(map));
    maxt=0;
}

void input()
{
    int x,y,t;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        map[t][x+d][y+d]=1;
        if(t>maxt) maxt=t;
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&d,&M))
    {
        if(!(N||d||M)) break;
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
