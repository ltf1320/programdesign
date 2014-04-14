#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100;
int mat[maxn][maxn];
int N,M;
const int inf=0x3f3f3f3f;

bool cn[maxn],cm[maxn];
int res;
void dfs(int i,int j,int sum)
{
    if(j==M)
    {
        j=0;
        i++;
    }
    if(i==N)
    {
        for(int i=0;i<N;i++)
            if(!cn[i])
                return;
        for(int i=0;i<M;i++)
            if(!cm[i])
                return;
        res=min(res,sum);
        return;
    }
    dfs(i,j+1,sum);
    if(!(cn[i]&&cm[j]))
    {
        int tn=cn[i],tm=cm[j];
        cn[i]=1;
        cm[j]=1;
        dfs(i,j+1,sum+mat[i][j]);
        cn[i]=tn;
        cm[j]=tm;
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&mat[i][j]);
    res=inf;
    dfs(0,0,0);
    printf("Case %d: %d\n",cas,res);
    }
    return 0;
}
