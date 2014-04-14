#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=15;
const int maxm=1000+10;
int M;
bool has[maxn];
int stack[maxm];

bool dfs(int dep,int suma,int sumb,int pre)
{
    if(dep==M)
        return true;
    for(int i=1; i<=10; i++)
    {
        if(!has[i]) continue;
        if(i==pre) continue;
        if(dep&1)
        {
            if(sumb+i>suma)
            {
                stack[dep]=i;
                if(dfs(dep+1,suma,sumb+i,i))return true;
            }
        }
        else
        {
            if(suma+i>sumb)
            {
                stack[dep]=i;
                if(dfs(dep+1,suma+i,sumb,i)) return true;
            }
        }
    }
    return false;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    memset(has,0,sizeof(has));
    char ch;
    for(int i=1; i<=10; i++)
    {
        ch=getchar();
        if(ch==' '||ch=='\n')
        {
            i--;
            continue;
        }
        has[i]=ch=='1'?1:0;
    }
    scanf("%d",&M);
    if(dfs(0,0,0,-1))
    {
        puts("YES");
        printf("%d",stack[0]);
        for(int i=1;i<M;i++)
            printf(" %d",stack[i]);
        puts("");
    }
    else puts("NO");
    return 0;
}
