#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int len;
char gp[maxn],gpp[maxn];
char p[maxn],pp[maxn];
char mgpp[maxn],mgp[maxn];
int ans;
void getPP()
{
    int i=len-1;
    while(p[i]=='1')
        pp[i--]='0';
    pp[i]='1';
    for(i--;i>=0;i--)
        pp[i]=p[i];
    pp[len]=0;
    mgpp[0]=pp[0];
    mgpp[len]=0;
    mgp[len]=0;
    for(int i=1;i<len;i++)
        mgpp[i]=((pp[i]-'0')^(pp[i-1]-'0'))+'0';
}

bool checkPP()
{
    for(int i=0;i<len;i++)
    {
        if(gpp[i]!='?'&&gpp[i]!=mgpp[i])
            return false;
    }
    return true;
}

void dfs(int n)
{
    if(n==len)
    {
        p[n]=0;
        getPP();
        if(checkPP())
        {
            ans++;
            printf("%s  %s\n%s  %s\n\n",p,mgp,pp,mgpp);
        }
        return;
    }
    if(gp[n]=='?')
    {
        mgp[n]='0';
        if(n)
            p[n]=((mgp[n]-'0')^(p[n-1]-'0'))+'0';
        else
            p[n]=mgp[n];
        dfs(n+1);
        mgp[n]='1';
        if(n)
            p[n]=((mgp[n]-'0')^(p[n-1]-'0'))+'0';
        else
             p[n]=mgp[n];
        dfs(n+1);
    }
    else
    {
        mgp[n]=gp[n];
        if(n)
            p[n]=((gp[n]-'0')^(p[n-1]-'0'))+'0';
        else
            p[n]=gp[n];
        dfs(n+1);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s%s",gp,gpp))
    {
        len=strlen(gp);
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
