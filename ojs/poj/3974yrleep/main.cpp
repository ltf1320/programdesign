#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e6+9;
char a[maxn];
int dp[maxn];
inline int max(int &a,int &b)
{
    if(a>b) return a;
    return b;
}
int main()
{freopen("in.txt","r",stdin);
    int tt=0;
    while(1)
    {
        char tmp;
        for(int i=0;;)
        {
            cin>>tmp;
            if(tmp=='\n') {a[++i]=0;break;}
            else if(tmp!=' ')
            {
                a[++i]=tmp;
                a[++i]='#';
            }
        }
        if(a[1]=='E') break;

        int top=0,n=strlen(a+1);
        dp[0]=0,a[0]=-1;
        for(int i=1,t,s;i<=n;i++)
        {
            if(top+dp[top]<i)
            {
                top=i;
                t=i-1,s=i+1;
                while(a[t]==a[s]) t--,s++;
                dp[i]=s-i-1;
            }
            else
            {
                if(dp[top-(i-top)]+i<top+dp[top])
                dp[i]=dp[top-(i-top)];
                else
                {
                    s=top+dp[top]+1;
                    t=i-(s-i);
                    while(a[t]==a[s]) t--,s++;
                    dp[i]=s-i-1;
                    top=i;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        if(a[i]=='#')
        ans=max(ans,dp[i]+1>>1<<1);
        else
        ans=max(ans,(dp[i]>>1<<1)+1);
        printf("Case %d: %d\n",++tt,ans);
    }
    return 0;
}
