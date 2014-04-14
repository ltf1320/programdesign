#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100+10;
int num[maxn];
int dp[maxn][100000+100];
int N;

struct Node
{
    int c,r;
    Node(int cc,int rr):c(cc),r(rr){}
    Node(){}
};

inline int abs(int a)
{
    return a>0?a:-a;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    queue<Node> que;
    Node now;
    int c1,r1,c2,r2;
    int res=inf;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        num[i]++;
        for(int j=1;j<=num[i];j++)
            dp[i][j]=inf;
    }
    scanf("%d%d%d%d",&c1,&r1,&c2,&r2);
    dp[c1][r1]=0;
    que.push(Node(c1,r1));
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(dp[now.c][now.r]>res)
            continue;
        if(now.c==c2)
            res=min(res,abs(now.r-r2)+dp[now.c][now.r]);
        if(now.c>1)
        {
            if(now.r>num[now.c-1])
            {
                if(dp[now.c-1][num[now.c-1]]>dp[now.c][now.r])
                {
                    que.push(Node(now.c-1,num[now.c-1]));
                    dp[now.c-1][num[now.c-1]]=dp[now.c][now.r]+1;
                }
            }
            else
            {
                if(dp[now.c-1][now.r]>dp[now.c][now.r])
                {
                    que.push(Node(now.c-1,now.r));
                    dp[now.c-1][now.r]=dp[now.c][now.r]+1;
                }
            }
        }
        if(now.c<N)
        {
            if(now.r>num[now.c+1])
            {
                if(dp[now.c+1][num[now.c+1]]>dp[now.c][now.r])
                {
                    que.push(Node(now.c+1,num[now.c+1]));
                    dp[now.c+1][num[now.c+1]]=dp[now.c][now.r]+1;
                }
            }
            else
            {
                if(dp[now.c+1][now.r]>dp[now.c][now.r])
                {
                    que.push(Node(now.c+1,now.r));
                    dp[now.c+1][now.r]=dp[now.c][now.r]+1;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
