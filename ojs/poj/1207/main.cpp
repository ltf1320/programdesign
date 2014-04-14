#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=10000;
const int inf=0x3f3f3f3f;
int num[3*maxn+10];
int dp[maxn+10][20];
int p2[20];

void pre()
{
    p2[0]=1;
    for(int i=1;i<20;i++)
        p2[i]=p2[i-1]*2;
}
int find2(int n)
{
    return (int)(log(1.0*n+1)/log(2.0));
}

bool in[maxn+10];
void spfa()
{
    int now;
    memset(in,0,sizeof(in));
    for(int i=0;i<maxn;i++)
        num[i]=inf;
    queue<int> que;
    que.push(1);
    num[1]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now*2<=3*maxn&&num[now*2]>num[now]+1)
        {
            num[now*2]=num[now]+1;
            if(!in[now*2])
            {
                in[now*2]=1;
                que.push(now*2);
            }
        }
        if((now-1)&&(now-1)%3==0)
        {
            if(num[(now-1)/3]>num[now]+1)
            {
                num[(now-1)/3]=num[now]+1;
                if(!in[(now-1)/3])
                {
                    in[(now-1)/3]=1;
                    que.push((now-1)/3);
                }
            }
        }
        in[now]=0;
    }
}

void RMQ()
{
    for(int i=1;i<=maxn;i++)
        dp[i][0]=num[i];
    for(int j=1;p2[j]<=maxn;j++)
        for(int i=1;i<=maxn-p2[j-1];i++)
            dp[i][j]=max(dp[i][j-1],dp[i+p2[j-1]][j-1]);
}

int query(int a,int b)
{
    int pp=find2(b-a);
    return max(dp[a][pp],dp[b-p2[pp]+1][pp]);
}

int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    pre();
    spfa();
    RMQ();
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d %d ",a,b);
        if(a>b)
        {
            int t=a;
            a=b;
            b=t;
        }
        printf("%d\n",query(a,b));
    }
    return 0;
}
