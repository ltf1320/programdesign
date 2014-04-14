#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
int N,K;
bool map[maxn][maxn];
bool used[maxn];

int dfs(int n,int num)
{
    if(num==K) return 1;
    if(n==N) return 0;
    int res=dfs(n+1,num);
    for(int i=0;i<N;i++)
    {
        if(!map[n][i]) continue;
        if(!used[i])
        {
            used[i]=1;
            res+=dfs(n+1,num+1);
            used[i]=0;
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    char tmp;
    while(~scanf("%d%d",&N,&K))
    {
        if(N==K&&N==-1) break;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                scanf("%c",&tmp);
                if(tmp=='\n')
                    {j--;continue;}
                if(tmp=='#')
                    map[i][j]=1;
                else map[i][j]=0;
            }
        memset(used,0,sizeof(used));
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
