#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 18

using namespace std;

int a[maxn];
int n;

int dfs(int sum,int now)
{
    int ans=0;
    if(sum==0)return 1;
    if(sum<0||now<0)return 0;
    for(int i=now;i>=0;i--)ans+=dfs(sum-a[i],i-1);
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int ans;
    while(~scanf("%d",&n))
    {
        ans=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=2;i<n;i++)ans+=dfs(a[i],i-1);
        printf("%d\n",ans);
    }
    return 0;
}
