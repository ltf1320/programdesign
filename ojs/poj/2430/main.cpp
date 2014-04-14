#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define gm(a,b) a=min(a,b)
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int N,K,B;
int nds[2][maxn];
int num[2];

int dp[2][maxn][4];
//0 :只有一个在0,1:只有一个在1,2：只有一个1,2,3：有两个

void work()
{
    sort(nds[0],nds[0]+num[0]);
    sort(nds[1],nds[1]+num[1]);
    int l[2];
    l[0]=l[1]=0;
    int kk=0;
    int now;
    int d=1,pre;
    pre=min(nds[0][0],nds[1][0])-1;
    if(nds[0][l[0]]==nds[1][l[1]])
        now=2;
    else if(nds[0][l[0]]<nds[1][l[1]])
        now=0;
    else now=1;
    for(int i=0; i<=K; i++)
        for(int j=0; j<4; j++)
            dp[kk^1][i][j]=inf;
    if(now==0||now==1)
    {
        gm(dp[kk^1][1][now],1);//new
        gm(dp[kk^1][1][2],2);
        if(1<K)
        {
            gm(dp[kk^1][2][3],2);
        }
    }
    else
    {
        gm(dp[kk^1][1][2],2);
        if(1<K)
        {
            gm(dp[kk^1][2][3],2);
        }
    }
    if(now==2)
    {
        pre=nds[0][0];
        l[0]++,l[1]++;
    }
    else
    {
        pre=nds[now][0];
        l[now]++;
    }
    kk^=1;

    while(l[0]<num[0]||l[1]<num[1])
    {
        if(nds[0][l[0]]==nds[1][l[1]])
        {
            d=nds[0][l[0]]-pre;
            pre=nds[0][l[0]];
            now=2;
        }
        else if(nds[0][l[0]]<nds[1][l[1]])
        {
            d=nds[0][l[0]]-pre;
            pre=nds[0][l[0]];
            now=0;
        }
        else
        {
            d=nds[1][l[1]]-pre;
            pre=nds[1][l[1]];
            now=1;
        }
        for(int i=0; i<=K; i++)
            for(int j=0; j<4; j++)
                dp[kk^1][i][j]=inf;
        for(int i=1; i<=K; i++)
        {
            if(now==0||now==1)
            {
                gm(dp[kk^1][i][now],dp[kk][i][now]+d);
                gm(dp[kk^1][i][now],dp[kk][i][3]+d);
                gm(dp[kk^1][i][3],dp[kk][i][3]+2*d);
                gm(dp[kk^1][i][2],dp[kk][i][2]+2*d);
                if(i<K)
                {
                    for(int j=0; j<4; j++)
                    {
                        gm(dp[kk^1][i+1][now],dp[kk][i][j]+1);//new
                        gm(dp[kk^1][i+1][2],dp[kk][i][j]+2);
                    }
                    gm(dp[kk^1][i+1][3],dp[kk][i][now^1]+d+1);
                }
                if(i+1<K)
                {
                    for(int j=0; j<4; j++)
                        gm(dp[kk^1][i+2][3],dp[kk][i][j]+2);
                }
            }
            else
            {
                gm(dp[kk^1][i][2],dp[kk][i][2]+2*d);
                gm(dp[kk^1][i][3],dp[kk][i][3]+2*d);
                if(i<K)
                {
                    gm(dp[kk^1][i+1][3],dp[kk][i][0]+d+1);
                    gm(dp[kk^1][i+1][3],dp[kk][i][1]+d+1);
                    for(int j=0; j<4; j++)
                        gm(dp[kk^1][i+1][2],dp[kk][i][j]+2);
                }
                if(i+1<K)
                {
                    for(int j=0; j<4; j++)
                        gm(dp[kk^1][i+2][3],dp[kk][i][j]+2);
                }
            }
        }
        if(now==2)
            l[0]++,l[1]++;
        else
            l[now]++;
        kk^=1;
    }
    int res=inf;
    for(int i=0; i<4; i++)
        res=min(res,dp[kk][K][i]);
    printf("%d\n",res);
}

void input()
{
    int a,b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d",&a,&b);
        a--;
        nds[a][num[a]++]=b;
    }
    nds[0][num[0]]=inf;
    nds[1][num[1]]=inf;
}

void init()
{
    num[0]=num[1]=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&K,&B))
    {
        init();
        input();
        work();
    }
    return 0;
}
