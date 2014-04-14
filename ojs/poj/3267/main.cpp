#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxw=600+10;
const int maxn=300+10;
char str[maxw][maxn];
int len[maxw];
char ss[maxn];
int sslen;
int W,L;

int dp[maxn];

int maxf[maxw];

bool getdiff(int from,int to,int j)
{
    if(from<=maxf[j]) return true;
    int k=0,i=from;
    int res=0;
    while(k<len[j]&&i<to)
    {
        if(ss[i]==str[j][k])
        {
            i++;
            k++;
        }
        else
        {
            i++;
            res++;
        }
    }
    if(k==len[j])
    {
        if(from>maxf[j]) maxf[j]=from;
        return 1;
    }
    else return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(maxf,0,sizeof(maxf));
    while(~scanf("%d%d",&W,&L))
    {
        scanf("%s",ss);
        sslen=strlen(ss);
        for(int i=0; i<W; i++)
        {
            scanf("%s",str[i]);
            len[i]=strlen(str[i]);
        }
        dp[0]=0;
        for(int i=1; i<=sslen; i++) //匹配长度
        {
            dp[i]=dp[i-1]+1;
            for(int j=0; j<W; j++) //字典第j个
            {
                for(int k=0; k<=i-len[j]; k++) //从ss[k]开始匹配
                {
 //                   int k=i-len[j]-1;
                    if(ss[k]!=str[j][0]) continue;
                    if(!getdiff(k,i,j)) break;
                    if(dp[i]>dp[k]+i-k-len[j])
                        dp[i]=dp[k]+i-k-len[j];
                }
            }
        }
        printf("%d\n",dp[sslen]);
    }
    return 0;
}
