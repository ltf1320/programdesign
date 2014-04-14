#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=120;

char pp[maxn][maxn];
bool used[maxn][maxn];
int n;
bool judge(int i,int j)
{
    if(i>=n-2) return 0;
    if(j==0||j==n-1) return 0;
    if(pp[i+1][j]=='#'&&!used[i+1][j]&&pp[i+2][j]=='#'&&!used[i+2][j]&&pp[i+1][j-1]=='#'&&!used[i+1][j-1]&&pp[i+1][j+1]=='#'&&!used[i][j])
    {
        used[i][j]=1;
        used[i+1][j]=1;
        used[i+1][j+1]=1;
        used[i+1][j-1]=1;
        used[i+2][j]=1;
        return 1;
    }
    return 0;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    cin>>n;
    gets(pp[0]);
    for(int i=0;i<n;i++)
        gets(pp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(pp[i][j]=='#'&&!used[i][j])
        {
            if(!judge(i,j))
            {
                puts("NO");
                return 0;
            }
        }
    puts("YES");
    return 0;
}
