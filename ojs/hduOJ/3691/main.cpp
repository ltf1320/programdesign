/*
2
ATGCAT
GC
ATGCAC
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int cas=1;
char str[maxn];
int dp[maxn][maxn];
int len;
int N;
int mp(char ch)
{
    switch(ch)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    }
    exit(0);
}

struct Node
{
    int fail;
    int next[4];
    bool end;
    void reset()
    {
        fail=-1;
        for(int i=0; i<4; i++)
            next[i]=-1;
        end=0;
    }
};
Node nds[maxn];
int code;
void insert(const char *s)
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
    nds[now].end=1;
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
                while(tmp!=-1&&nds[tmp].next[i]==-1)  //¾ÓÈ»Ð´³ÉÁËnds[now]
                    tmp=nds[tmp].fail;
                if(tmp==-1)
                    nds[nds[now].next[i]].fail=0;
                else if(nds[tmp].next[i]!=-1)
                {
                    if(nds[nds[tmp].next[i]].end)
                        nds[nds[now].next[i]].end=1;
                    nds[nds[now].next[i]].fail=nds[tmp].next[i];
                }
            }
        }
    }
}


void work()
{
    int now;
    for(int i=0; i<=len; i++)
        for(int j=0; j<code; j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<code; j++)
        {
            if(dp[i][j]!=inf)
            {
                for(int k=0; k<4; k++)
                {
                    now=j;
                    while(now!=0&&nds[now].next[k]==-1)
                        now=nds[now].fail;
                    if(nds[now].next[k]!=-1)
                        now=nds[now].next[k];
                    if(!nds[now].end)  //!now
                    {
  //                      printf("%d\n",i);
                        if(k==mp(str[i]))
                            dp[i+1][now]=min(dp[i+1][now],dp[i][j]);
                        else dp[i+1][now]=min(dp[i+1][now],dp[i][j]+1);
                    }
                }

            }
        }
    }
    int res=inf;
    for(int i=0;i<code;i++)
    {
        if(dp[len][i]<res)
            res=dp[len][i];
    }
    printf("Case %d: ",cas++);
    if(res==inf) printf("-1\n");
    else printf("%d\n",res);
}

void input()
{
    char tmp[50];
    for(int i=0; i<N; i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    BuildAC();
    scanf("%s",str);
    len=strlen(str);
}

void init()
{
    for(int i=0; i<maxn; i++)
        nds[i].reset();
    code=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(!N) break;
        init();
        input();
        work();
    }
    return 0;
}
