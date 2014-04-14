#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=8+2;

int n,k;

bool map[maxn][maxn];
bool usedc[maxn];

int dfs(int dp,int num)
{
    if(num==k) return 1;
    if(dp==n) return 0;
    int res=0;
    res+=dfs(dp+1,num);
    for(int i=0;i<n;i++)
    {
        if(map[dp][i]&&!usedc[i])
        {
            usedc[i]=1;
            res+=dfs(dp+1,num+1);
            usedc[i]=0;
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    char ch;
//    int res;
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ch=getchar();
                if(ch=='\n')
                {
                    j--;continue;
                }
                if(ch=='#') map[i][j]=1;
                else map[i][j]=0;
            }
        }
        /*
        res=0;
        for(int i=0;i<n;i++)
        {
            memset(usedc,0,sizeof(usedc));
            res+=dfs(i,0);
        }
        */
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
