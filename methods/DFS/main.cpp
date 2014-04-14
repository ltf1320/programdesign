//lrj竞赛入门107,dfs

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1200;
bool image[maxn][maxn];
bool visited[maxn][maxn];

void dfs(int i,int j,int n)
{
    if(visited[i][j]||!image[i][j]) return;
    visited[i][j]=1;
    dfs(i-1,j,n);dfs(i+1,j,n);
    dfs(i,j-1,n); dfs(i,j+1,n);
    dfs(i-1,j-1,n);dfs(i-1,j+1,n);
    dfs(i+1,j-1,n);dfs(i+1,j+1,n);
}


int main()
{
    freopen("in","r",stdin);
    int n;
    while(1)
    {
        cin>>n;
        if(!cin) break;
        int count=0;
        memset(image,0,sizeof(image));
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;++i)  //在图形边缘加上一圈虚拟的白色方块，减少判断量
            for(int j=1;j<=n;++j)
                cin>>image[i][j];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                if(image[i][j]&&!visited[i][j])
                {
                    ++count;
                    dfs(i,j,n);
                }
            }
        cout<<count<<endl;
    }
    return 0;
}
