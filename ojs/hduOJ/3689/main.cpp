#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxm=1000+10;
const int maxn=30;
int N,M;
char word[maxn];
int l;
double p[maxn];

double dp[maxm][maxn];
int next[maxn];

void get_next()
{
    int k=0;
    next[1]=0;
    for(int i=2;i<=l;i++)
    {
        while(k!=0&&word[k+1]!=word[i])
            k=next[k];
        if(word[k+1]==word[i])
            k++;
        next[i]=k;
    }
}

double work()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    get_next();
    int nxt;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(dp[i][j]!=0)
            {
                dp[i+1][j+1]+=dp[i][j]*p[word[j+1]-'a'];
                for(int k=0;k<26;k++)
                {
                    if(k==word[j+1]-'a') continue;
                    nxt=next[j];
                    while(nxt!=0&&word[nxt+1]!=k+'a')
                        nxt=next[nxt];
                    if(word[nxt+1]==k+'a')
                        nxt++;
                    //dp[i+1][nxt]+=dp[i][j]*(1-p[word[j+1]-'a'])*p[k];
                    dp[i+1][nxt]+=dp[i][j]*p[k];
                }
            }
        }
    }
    double res=0.0;
    for(int j=0;j<l;j++)
        res+=dp[M][j];
    return (1-res)*100;
}

void input()
{
    char ch;
    double pp;
    memset(p,0,sizeof(p));
    for(int i=0;i<N;i++)
    {
        getchar();
        scanf("%c%lf",&ch,&pp);
        p[ch-'a']=pp;
    }
    scanf("%s",word+1);
    l=strlen(word+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        input();
        printf("%.2f%%\n",work());
    }
    return 0;
}
