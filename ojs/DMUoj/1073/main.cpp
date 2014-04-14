#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=20;

int N;
int num[maxn];

bool find(int start,int n)
{
    /*
    int l(start),r(N),m;
    m=(start+N)/2;
    while(1)
    {
        if(n==num[m]) return true;
        if(r-l<=1) return false;
        if(n<num[m]) r=m;
        else l=m+1;
        m=(l+r)/2;
    }
    */
    for(int i=start;i<N;i++)
        if(num[i]==n) return true;
    return false;
}

int dfs(int now,int sum)
{
    if(now==N) return 0;
    int res=dfs(now+1,sum);
    sum+=num[now];
    if(find(now+1,sum)) res++;
    res+=dfs(now+1,sum);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d",&N))
    {
        for(int i=0;i<N;i++)
            scanf("%d",&num[i]);
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
