#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;
const int maxn=50+10;
const int maxm=500+10;//!
int N,M,P;
map<unsigned char,int> mp;

struct Node
{
    int fail;
    int next[maxn];
    bool end;
    void reset()
    {
        fail=-1;
        for(int i=0; i<maxn; i++)
            next[i]=-1;
        end=0;
    }
};
Node nds[maxm];
int code;
void insert(const unsigned char *s)
{
    int i=0;
    int now=0;
    while(s[i])
    {
        if(nds[now].next[mp[s[i]]]==-1)
            nds[now].next[mp[s[i]]]=code++;
        now=nds[now].next[mp[s[i]]];
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
        for(int i=0; i<N; i++)
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
                    //    nds[now].end=1;
                    nds[nds[now].next[i]].fail=nds[tmp].next[i];
                }
            }
            //
            else nds[now].next[i]=nds[nds[now].fail].next[i];
        }
    }
}

void init()
{
    for(int i=0;i<maxn;i++)
        nds[i].reset();
    code=1;
}

void input()
{
    unsigned char tmp[maxn];
    unsigned char ch;
    scanf("%d%d%d",&N,&M,&P);
    ch=getchar();
    for(int i=0;i<N;i++)
    {
        ch=getchar();
        mp[ch]=i;
    }
    getchar();
    for(int i=0;i<P;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    BuildAC();
}

struct LN
{
    static const int JW=10000;
    int n;
    int a[100];
    LN(){memset(a,0,sizeof(a));n=0;}
    LN operator+(const LN &w)
    {
        LN res;
        for(int i=0;i<=max(n,w.n);i++)
        {
            res.a[i]+=a[i]+w.a[i];
            if(res.a[i]>=JW)
            {
                res.a[i+1]+=res.a[i]/JW;
                res.a[i]%=JW;
            }
            res.n++;
        }
        while(res.a[res.n]==0&&res.n>0)
            res.n--;
        return res;
    }
    LN operator*(int n)
    {
        LN res;
        for(int i=0;i<=n;i++)
        {
            res.a[i]+=a[i]*n;
            if(res.a[i]>=JW)
            {
                res.a[i+1]+=res.a[i]/JW;
                res.a[i]%=JW;
            }
            res.n++;
        }
        res.n++;
        while(res.a[res.n]==0&&res.n>0)
            res.n--;
        return res;
    }
    void print()
    {
        while(a[n]==0&&n)
            n--;
        printf("%d",a[n--]);
        for(int i=n;i>=0;i--)
            printf("%04d",a[i]); //forgot 04
    }
};

void work()
{
    int dp[maxn][maxn];
    memset(dp,0,sizeof(dp));
    int tmp;
    for(int i=0;i<code;i++)
    {
        if(nds[i].end) continue;
        for(int j=0;j<N;j++)
        {
            if(nds[i].next[j]!=-1)
            {
                if(nds[nds[i].next[j]].end) continue;
                dp[i][nds[i].next[j]]++;
                continue;
            }
            tmp=nds[i].fail;
            while(nds[tmp].next[j]==-1&&tmp!=-1)
                tmp=nds[tmp].fail;
            if(tmp==-1)
                dp[i][0]++;
            else {
                if(nds[nds[tmp].next[j]].end) continue;
                dp[i][nds[tmp].next[j]]++;
            }
        }
    }
/*
    for(int i=0;i<code;i++)
    {
        for(int j=0;j<code;j++)
        {
            printf("%d ",dp[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
*/
    LN ddp[maxn][maxn];
    ddp[0][0].a[0]=1;
    for(int i=0;i<M;i++)
        for(int j=0;j<code;j++)
            for(int k=0;k<code;k++)
            {
                if(dp[j][k])
                    ddp[i+1][k]=ddp[i+1][k]+ddp[i][j]*dp[j][k];
            }
/*
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<code;j++)
        {
            ddp[i][j].print();
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
*/
    LN res;
    for(int i=0;i<code;i++)
        res=res+ddp[M][i];
    res.print();
    putchar('\n');
    return;
}


int main()
{
    freopen("in.txt","r",stdin);
    init();
    input();
    work();
    return 0;
}
