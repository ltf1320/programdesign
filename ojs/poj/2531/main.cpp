#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20+2;
int N,res;
int in[maxn];
int net[maxn][maxn];

void dfs(int now,int sum)
{
    if(now==N) return;
    dfs(now+1,sum);
    for(int i=0;i<N;i++)
    {
        if(in[i]) sum-=net[now][i];
        else sum+=net[now][i];
    }
    if(sum>res) res=sum;
    in[now]=1;
    dfs(now+1,sum);
    in[now]=0;
}



int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                scanf("%d",&net[i][j]);
            }
        res=0;
        memset(in,0,sizeof(in));
        dfs(0,0);
        printf("%d\n",res);
    }
    return 0;
}
