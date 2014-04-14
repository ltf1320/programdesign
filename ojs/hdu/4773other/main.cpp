#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <string>
#include <cstdio>
#define maxn 100010
#define mod 1000000007
using namespace std;

char s1[maxn],s2[maxn];
int path[maxn];
int dp[maxn][2];
int flag[maxn][2];
int N;
int may[maxn];
char res1[maxn],res2[maxn];

bool try1(int x)
{
    res1[x]='0';
    res2[x]='1';
    int pre=0;
    int i,j;

    for(i=x-1;i>=1;i--)
    {
        if(s1[i]=='1'||s2[i]=='1')
        {
            res1[i]=res2[i]=1+'0';
            pre=pre^1;
            continue;
        }
        if(s1[i]=='0'||s2[i]=='0')
        {
            res1[i]=res2[i]=0+'0';
            pre=pre;
            continue;
        }

        if(flag[i-1][0]&&flag[i-1][1])
        {
            return false;
        }
        if(flag[i-1][1])
        {
            res1[i]=res2[i]=pre^1+'0';
            pre=1;
        }
        else if(flag[i-1][0])
        {
            res1[i]=res2[i]=pre^0+'0';
            pre=0;
        }
    }
    return true;
}
bool try2(int x)
{
    res1[x]='1';
    res2[x]='0';
    int pre=1,cur;
    int i,j;
    for(i=x-1;i>=1;i--)
    {
        if(s1[i]=='1'||s2[i]=='1')
        {
            res1[i]=res2[i]=1+'0';
            pre=pre^1;
            continue;
        }
        if(s1[i]=='0'||s2[i]=='0')
        {
            res1[i]=res2[i]=0+'0';
            pre=pre;
            continue;
        }

        if(flag[i-1][0]&&flag[i-1][1])
        {
            return false;
        }
        if(flag[i-1][1])
        {
            res1[i]=res2[i]=pre^1+'0';
            pre=1;
        }
        else if(flag[i-1][0])
        {
            res1[i]=res2[i]=pre^0+'0';
            pre=0;
        }
    }
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int i,j;
    int T;
    scanf("%d",&T);
    int test=0;
    while(T--)
    {
        scanf("%s %s",s1+1,s2+1);
        printf("Case #%d:\n",++test);
        N=strlen(s1+1);
        memset(dp,0,sizeof(dp));
        memset(flag,0,sizeof(flag));
        memset(may,0,sizeof(may));
        dp[0][0]=1,flag[0][0]=1;
        for(i=1; i<=N; i++)
        {
            if(s1[i]=='?'&&s2[i]=='?')
            {
                dp[i][0]=dp[i-1][0]+dp[i-1][1];
                dp[i][1]=dp[i-1][0]+dp[i-1][1];
                flag[i][0]=flag[i-1][0]+flag[i-1][1];
                flag[i][1]=flag[i-1][0]+flag[i-1][1];
                may[i]=1;
            }
            else if(s1[i]=='?'||s2[i]=='?')
            {
                if(s1[i]=='0'||s2[i]=='0')
                {
                    dp[i][0]=dp[i-1][0];
                    dp[i][1]=dp[i-1][1];
                    flag[i][0]=flag[i-1][0];
                    flag[i][1]=flag[i-1][1];
                }
                else if(s1[i]=='1'||s2[i]=='1')
                {
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=dp[i-1][0];
                    flag[i][0]=flag[i-1][1];
                    flag[i][1]=flag[i-1][0];
                }
                may[i]=1;
            }
            else if(s1[i]!=s2[i])
            {
                dp[i][0]=dp[i][1]=0;
                flag[i][0]=flag[i][1]=0;
                may[i]=1;
                break;
            }
            else
            {
                if(s1[i]=='0')
                {
                    dp[i][0]=dp[i-1][0];
                    dp[i][1]=dp[i-1][1];
                    flag[i][0]=flag[i-1][0];
                    flag[i][1]=flag[i-1][1];
                }
                else
                {
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=dp[i-1][0];
                    flag[i][0]=flag[i-1][1];
                    flag[i][1]=flag[i-1][0];
                }
            }
            dp[i][0]%=mod;
            dp[i][1]%=mod;
            if(flag[i][0]>2) flag[i][0]=2;
            if(flag[i][1]>2) flag[i][1]=2;
        }

        int ok=1;
        int ans=0;
        int num=0;
        int id;
        int pp=1;
        for(i=N; i>=1&&ok; i--)
        {
            if(may[i]&&pp)
            {
                if(s1[i]=='1')
                {
                    ans=(ans+dp[i-1][1])%mod;
                    num+=flag[i-1][1];
                    if(num) id=i;
                    if(num>2) num=2;
                }
                else if(s1[i]=='0')
                {
                    ans=(ans+dp[i-1][0])%mod;
                    num+=flag[i-1][0];
                    if(num) id=i;
                    if(num>2) num=2;
                }
                else if(s2[i]=='1')
                {
                    ans=(ans+dp[i-1][0])%mod;
                    num+=flag[i-1][0];
                    if(num) id=i;
                    if(num>2) num=2;
                }
                else if(s2[i]=='0')
                {
                    ans=(ans+dp[i-1][1])%mod;
                    num+=flag[i-1][1];
                    if(num) id=i;
                    if(num>2) num=2;
                }
                else if(s1[i]==s2[i]&&s1[i]=='?')
                {
                    ans=(ans+dp[i-1][1])%mod;
                    ans=(ans+dp[i-1][0])%mod;
                    num+=flag[i-1][0]+flag[i-1][1];
                    if(num) id=i;
                    if(num>2) num=2;
                }
            }
            if(s1[i]=='0'||s2[i]=='0')
            {
                pp=0;
            }
            else
            {
                pp=1;
            }

            if(i<N&&(s1[i+1]=='1'||s2[i+1]=='1'))
            {
                ok=0;
            }
        }
        if(num==0)
        {
            puts("Impossible");
        }
        else if(num==2)
        {
            printf("Ambiguous %d\n",ans);
        }
        else
        {
            res1[N+1]=0,res2[N+1]=0;
            int pre=0;

            i=id;
            if(s1[i]=='0'||s2[i]=='1')
            {
                try1(id);
            }
            else if(s1[i]=='1'||s2[i]=='0')
            {
                try2(id);
            }
            else
            {
                if(!try1(id))
                {
                    try2(id);
                }
            }
            i=id+1;
            if(i<=N)
            {
                res1[i]=res2[i]='1';
            }
            for(i++; i<=N; i++)
            {
                res1[i]='0';
                res2[i]='0';
            }
            puts(res1+1);
            puts(res2+1);
        }
    }
    return 0;
}
