#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=15;
const int maxm=1000+10;
int M;
bool has[maxn];
int stack[maxm];
int dep;
bool dfs()
{
    int suma=0,sumb=0;
    int pre=-1;
    int i;
    while(true)
    {
        for(i=1;i<=10;i++)
        {
            if(!has[i]) continue;
            if(i==pre) continue;
            if(dep&1)
            {
                if(sumb+i>suma)
                {
                    sumb+=i;
                    pre=i;
                    stack[dep]=i;
                    break;
                }
            }
            else
            {
                if(suma+i>sumb)
                {
                    suma+=i;
                    pre=i;
                    stack[dep]=i;
                    break;
                }
            }
        }
        if(i>10) return false;
    }
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(has,0,sizeof(has));
    char ch;
    for(int i=1;i<=10;i++)
    {
        ch=getchar();
        if(ch==' '||ch=='\n'){i--;continue;}
        has[i]=ch=='1'?1:0;
    }
    scanf("%d",&M);
    if(dfs())
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
