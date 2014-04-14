#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
char xx[maxn];
int N;
int ans;
char astr[maxn];
int judge()
{
    int res=1,now;
    for(int i=1;i<=N;i++)
    {
        now=1;
        while(xx[i+now]==xx[i-now])
            now++;
        res=max(res,now*2-1);
        now=0;
        while(xx[i+now]==xx[i-now-1])
            now++;
        res=max(res,now*2);
    }
    return res;
}

void dfs(int n)
{
    if(n==N+1)
    {
        int now=judge();
        if(now<ans)
        {
            ans=now;
            strcpy(astr,xx);
        }
        return ;
    }
    xx[n]='a';
    dfs(n+1);
    xx[n]='b';
    dfs(n+1);
}

int main()
{
    freopen("out.txt","w",stdout);
 //   N=7;
 //   strcpy(xx,"{aaababb}");
 //   cout<<judge()<<endl;
    xx[0]='{';
    for(N=1;N<30;N++)
    {
        ans=0x3f3f3f3f;
        xx[N+1]='}';
        dfs(1);
        printf("%d\n%d %s\n",N,ans,astr);
    }
    return 0;
}
