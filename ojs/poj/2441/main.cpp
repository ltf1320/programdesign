#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=22;
int N,M;
int res;
vector<int> cs[maxn];
bool used[maxn];
void dfs(int now)
{
    if(now==N)
    {
        res++;
        return;
    }
    for(int i=0;i<(int)cs[now].size();i++)
    {
        if(!used[cs[now][i]])
        {
            used[cs[now][i]]=1;
            dfs(now+1);
            used[cs[now][i]]=0;
        }
    }
}

void work()
{
    res=0;
    dfs(0);
    printf("%d\n",res);
}

void input()
{
    int t,k;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&t);
        for(int j=0;j<t;j++)
        {
            scanf("%d",&k);
            cs[i].push_back(k);
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        work();
    }
    return 0;
}
