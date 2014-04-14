#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

#define FOR(a,b,c,d,e) for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) for(int p=0;p<=d;p++) for(int q=0;q<=e;q++)
using namespace std;
const int maxn=10;
const int maxs=100+10;
const int inf=0x3f3f3f3f;
int B,S;

map<int,int> mp;
int dp[maxn][maxn][maxn][maxn][maxn];

struct ITEM
{
    int pri,num;
};
ITEM its[maxn];

struct SO
{
    int num[maxn];
    int pri;
    void reset()
    {
        memset(num,0,sizeof(num));
        pri=0;
    }
};
SO sos[maxs];

int work()
{
    int state[maxn];
    bool go;
    FOR(its[0].num,its[1].num,its[2].num,its[3].num,its[4].num)
    {
        if(i>0) dp[i][j][k][p][q]=min(dp[i-1][j][k][p][q]+its[0].pri,dp[i][j][k][p][q]);
        if(j>0) dp[i][j][k][p][q]=min(dp[i][j-1][k][p][q]+its[1].pri,dp[i][j][k][p][q]);
        if(k>0) dp[i][j][k][p][q]=min(dp[i][j][k-1][p][q]+its[2].pri,dp[i][j][k][p][q]);
        if(p>0) dp[i][j][k][p][q]=min(dp[i][j][k][p-1][q]+its[3].pri,dp[i][j][k][p][q]);
        if(q>0) dp[i][j][k][p][q]=min(dp[i][j][k][p][q-1]+its[4].pri,dp[i][j][k][p][q]);
        for(int l=0;l<S;l++)
        {
            go=1;
            state[0]=i-sos[l].num[0];
            state[1]=j-sos[l].num[1];
            state[2]=k-sos[l].num[2];
            state[3]=p-sos[l].num[3];
            state[4]=q-sos[l].num[4];
            for(int m=0;m<5;m++)
                if(state[m]<0)
                {
                    go=0;
                    break;
                }
            if(go)
                dp[i][j][k][p][q]=min(dp[state[0]][state[1]][state[2]][state[3]][state[4]]+sos[l].pri,dp[i][j][k][p][q]);
        }
    }
    return dp[its[0].num][its[1].num][its[2].num][its[3].num][its[4].num];
}

void input()
{
    int c,k,p,n;
    for(int i=0;i<B;i++)
    {
        scanf("%d%d%d",&c,&k,&p);
        its[i].num=k;
        its[i].pri=p;
        mp[c]=i;
    }
    scanf("%d",&S);
    for(int i=0;i<S;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&c,&k);
            sos[i].num[mp[c]]=k;
        }
        scanf("%d",&p);
        sos[i].pri=p;
    }
}

void init()
{
    FOR(5,5,5,5,5)
        dp[i][j][k][p][q]=inf;
    dp[0][0][0][0][0]=0;
    mp.clear();
    for(int i=0;i<=5;i++)
        its[i].num=0;
    for(int i=0;i<maxs;i++)
        sos[i].reset();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&B))
    {
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
