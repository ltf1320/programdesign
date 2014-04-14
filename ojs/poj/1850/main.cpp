#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[10+5][26+5];

void pre()
{
    memset(dp,0,sizeof(dp));
    for(int j=0;j<26;j++)
        dp[0][j]=j+1;
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<i;j++)
            dp[i][0]+=dp[j][25];
        for(int j=1;j<26;j++)
        {
            dp[]
        }
    }
}
int main()
{
    char tmp[20];
    int len,res;
    pre();
    scanf("%s",tmp);
    len=strlen(tmp);
    res=0;
    for(int i=0;i<len;i++)
    {
        res+=dp[len-i-1][tmp[i]-'a'];
    }
    printf("%d\n",res);
    return 0;
}
