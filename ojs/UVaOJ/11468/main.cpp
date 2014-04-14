#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxc=100;
const int maxn=1000;
const int maxl=100+10;
int K,N,L;
int cc[maxn];
double p[maxn];

double dp[maxl][maxn];

int getN(char ch)
{
    if(ch>='0'&&ch<='9')
        return ch-'0';
    if(ch>='a'&&ch<='z')
        return ch-'a'+10;
    if(ch>='A'&&ch<='Z')
        return ch-'A'+37;
    return -1;
}

struct Node
{
    int fail;
    int next[maxc];
    bool end;
    Node(){reset();}
    void reset()
    {
        fail=-1;
        for(int i=0; i<maxc; i++)
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
        if(nds[now].next[getN(s[i])]==-1)
            nds[now].next[getN(s[i])]=code++;
        now=nds[now].next[getN(s[i])];
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
        for(int i=0; i<maxc; i++)
        {
            if(nds[now].next[i]!=-1)
            {
                que.push(nds[now].next[i]);
                tmp=nds[now].fail;
                while(tmp!=-1&&nds[tmp].next[i]==-1)  //¨p§ã§ç¨m§á¨f§§§Ú§Ñ§Ünds[now]
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
    BuildAC();
    dp[0][0]=1;
    for(int l=0;l<L;l++)
        for(int i=0;i<code;i++)
            if(!nds[i].end)
                for(int j=0;j<N;j++)
                {
                    if(nds[i].next[cc[j]]!=-1)
                        dp[l+1][nds[i].next[cc[j]]]+=dp[l][i]*p[j];
                    else
                    {
                        int tmp=nds[i].fail;
                        while(tmp!=-1&&nds[tmp].next[cc[j]]==-1)
                            tmp=nds[tmp].fail;
                        if(tmp==-1)
                            tmp=0;
                        else
                            tmp=nds[tmp].next[cc[j]];
                        dp[l+1][tmp]+=dp[l][i]*p[j];
                    }
                }
    double res=0;
    for(int i=0;i<code;i++)
        if(!nds[i].end)
            res+=dp[L][i];
    printf("%.6f\n",res);
}
char tmp[maxn];
void input()
{
    double pp;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s%lf",tmp,&pp);
        cc[i]=getN(tmp[0]);
        p[i]=pp;
    }
    scanf("%d",&L);
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(p,0,sizeof(p));
    for(int i=0;i<code;i++)
        nds[i].reset();
    code=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        printf("Case #%d: ",cas);
        init();
        input();
        work();
    }
    return 0;
}
