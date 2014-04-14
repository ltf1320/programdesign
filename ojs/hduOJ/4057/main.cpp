#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=20;
const int maxl=100+10;
int N,L;
int dp[maxl][maxn*maxl];
int state[maxl][maxn*maxl];
int W[4][maxn*maxl];

int mp(char a)
{
    switch(a)
    {
        case 'A':return 0;
        case 'T':return 1;
        case 'G':return 2;
        case 'C':return 3;
    }
    return -1;
}


struct Node
{
    int fail;
    int next[4];
    void reset()
    {
        fail=-1;
        for(int i=0; i<4; i++)
            next[i]=-1;
    }
};
Node nds[maxn*maxl];
int code;
void insert(const char *s,int w)
{
    int i=0;
    int now=0;
    while(s[i])
    {
        if(nds[now].next[mp(s[i])]==-1)
            nds[now].next[mp(s[i])]=code++;
        now=nds[now].next[mp(s[i])];
        i++;
    }
    for(i=0;i<4;i++)
        W[i][now]=w;
}

void BuildAC()
{
    int now,tmp;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0; i<4; i++)
        {
            if(nds[now].next[i]!=-1)
            {
                que.push(nds[now].next[i]);
                tmp=nds[now].fail;
                while(tmp!=-1&&nds[tmp].next[i]==-1)
                    tmp=nds[tmp].fail;
                if(tmp==-1)
                    nds[nds[now].next[i]].fail=0;
                else if(nds[tmp].next[i]!=-1)
                {
  //                  if(nds[nds[tmp].next[i]].end)
   //                     nds[nds[now].next[i]].end=1;
                    nds[nds[now].next[i]].fail=nds[tmp].next[i];
                }
            }
        }
    }
}

int find(int state,int f)
{
    while(state!=-1&&nds[state].next[f]==-1)
        state=nds[state].fail;
    if(state==-1) return -1;
    return nds[state].next[f];
}

int work()
{
    int ma,last,mstate,nstate,noww;
    memset(dp[0],0,sizeof(dp[0]));
    memset(state[0],0,sizeof(state[0]));
    for(int i=1;i<=L;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i][j]=-1;
            last=-1;
            ma=-1;
            for(int k=0;k<4;k++)
            {
                if(dp[i-1][k]==-1) continue;
                nstate=find(state[i-1][k],j);
                if(nstate==-1) noww=0;
                else noww=W[k][nstate];
                if(dp[i-1][k]+noww>ma)
                {
                    mstate=nstate;
                    ma=dp[i-1][k]+noww;
                    last=k;
                }
            }
            if(last!=-1)
            {
                dp[i][j]=ma;
                state[i][j]=mstate;
                memcpy(W[j],W[last],sizeof(W[last]));
                W[j][mstate]=0;
            }
        }
    }
    int res=-1;
    for(int i=0;i<4;i++)
        res=max(res,dp[L][i]);
    return res;
}

void input()
{
    char tmp[maxl];
    int w;
    code=1;
    memset(W,0,sizeof(W));
    for(int i=0;i<maxn*maxl;i++)
        nds[i].reset();
    for(int i=0;i<N;i++)
    {
        scanf("%s%d",tmp,&w);
        insert(tmp,w);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int res;
    while(~scanf("%d%d",&N,&L))
    {
        input();
        BuildAC();
        res=work();
        if(res!=-1)
            printf("%d\n",res);
        else printf("No Rabbit after 2012!\n");
    }
    return 0;
}
