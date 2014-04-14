#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
const int maxn=200+10;
const int inf=0x3f3f3f3f;
int N,M;

int pnt,ent;
map<string,int> mp;

int dp[maxn][maxn];
int kdp[maxn];
int count[maxn];
bool head[maxn];
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];

void add(int from,int to)
{
    head[to]=0;
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void dfs(int n)
{
    dp[n][0]=0;
    dp[n][1]=count[n];
    for(int i=box[n]; i!=-1; i=edge[i].next)
    {
        if(dp[edge[i].to][0]!=0)
            dfs(edge[i].to);
        for(int j=M-1; j>=0; j--)
            for(int k=1; k<=M-j; k++)
            {
                if(dp[edge[i].to][k]>=inf) break;
                if(dp[n][j]+dp[edge[i].to][k]<dp[n][j+k])
                    dp[n][j+k]=dp[n][j]+dp[edge[i].to][k];
            }
    }
    for(int i=1; i<=M; i++)
        if(dp[n][i]<inf)
        {
            dp[n][i]=min(count[n],dp[n][i]);
        }
        else break;
}

int work()
{
    for(int i=0; i<N; i++)
    {
        if(!head[i]) continue;
        kdp[0]=0;
        if(dp[i][0]!=0)
            dfs(i);
        for(int j=M-1; j>=0; j--)
            for(int k=1; k<=M-j; k++)
            {
                if(dp[i][k]>=inf) break;
                if(kdp[j]+dp[i][k]<kdp[j+k])
                    kdp[j+k]=kdp[j]+dp[i][k];
            }
    }
    return kdp[M];
}

void input()
{
    char tmp[200],ch;
    int dcount,cc,np;
    for(int i=0; i<N; i++)
    {
        scanf("%s%d",tmp,&dcount);
        np=pnt;
        if(mp.count(string(tmp)))
        {
            count[mp[string(tmp)]]=dcount;
            np=mp[string(tmp)];
        }
        else
        {
            mp[string(tmp)]=pnt;
            count[pnt++]=dcount;
        }
        cc=0;
        while(true)
        {
            ch=getchar();
            if(cc>200)
            {
                cc++;
                cc--;
            }
            if(ch=='\n')
            {
                if(cc==0) break;
                tmp[cc]=0;
                if(mp.count(string(tmp)))
                {
                    add(np,mp[string(tmp)]);
                }
                else
                {
                    mp[string(tmp)]=pnt++;
                    add(np,pnt-1);
                }
                cc=0;
                break;
            }
            if(ch==' ')
            {
                if(cc==0) continue;
                tmp[cc]=0;
                if(mp.count(string(tmp)))
                {
                    add(np,mp[string(tmp)]);
                }
                else
                {
                    mp[string(tmp)]=pnt++;
                    add(np,pnt-1);
                }
                cc=0;
            }
            else tmp[cc++]=ch;
        }
    }
 //   gets(tmp);
}

void init()
{
    mp.clear();
    memset(box,-1,sizeof(box));
//   memset(count,-1,sizeof(count));
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=M; j++)
            dp[i][j]=inf;
    }
    for(int i=0; i<=M; i++)
        kdp[i]=inf;
    for(int i=0; i<=N; i++)
        head[i]=1;
    ent=0;
    pnt=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    char tmp[maxn];
    while(true)
    {
        gets(tmp);
        if(tmp[0]=='#') break;
        sscanf(tmp,"%d%d",&N,&M);
        init();
        input();
        printf("%d\n",work());
    }
    return 0;
}
