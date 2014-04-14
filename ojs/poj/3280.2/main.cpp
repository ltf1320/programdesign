#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxm=2000+100;
const int maxn=30;
const int inf=0x3f3f3f3f;
int N,M;

char str[maxm];
map<char,int> mp;
char alph[maxn];
int add[maxn];
int del[maxn];
int dp[maxm][maxm];

int work()
{
    for(int j=1;j<M;j++)
        for(int i=0;i<M-j;i++)
        {
            if(str[i]==str[i+j]) dp[i][i+j]=dp[i+1][i+j-1];
            else dp[i][i+j]=inf;
            dp[i][i+j]=min(dp[i][i+j],dp[i][i+j-1]+add[mp[str[i+j]]]);
            dp[i][i+j]=min(dp[i][i+j],dp[i+1][i+j]+add[mp[str[i]]]);
        }
    return dp[0][M-1];
}

void input()
{
    scanf("%d%d",&N,&M);
    memset(dp,0,sizeof(dp));
    scanf("%s",str);
    getchar();
    char ch;
    for(int i=0;i<N;i++)
    {
        scanf("%c%d%d%c",&alph[i],&add[i],&del[i],&ch);
        mp[alph[i]]=i;
        add[i]=min(add[i],del[i]);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    input();
    printf("%d\n",work());
    return 0;
}
