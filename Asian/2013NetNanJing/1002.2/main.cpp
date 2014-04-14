#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxk=30;
int N,M,K;
int lev[maxn];

int pp[maxk]; //匹配的数
int pnum[maxk]; //匹配的个数

int dp[maxn];
int pi[maxn]; //kmp预处理数组
int a[maxn]; //a数组

void kmp() //kmp预处理
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1; p<=M; p++)
    {
        while(k!=-1&&a[k+1]!=a[p])
            k=pi[k];
        if(a[k+1]==a[p])
            k=k+1;
        pi[p]=k;
    }
}
int p;

bool judge() //判断匹配是否符合大小关系
{
    bool flag=1;
    int w=1;
    while(pnum[w]==0) w++; //
    for(int j=w+1; j<=K; j++)
    {
        if(pnum[j])
        {
            if(pp[j]<=pp[w])
            {
                flag=0;
                break;
            }
            w=j;
        }
    }
    return flag;
}

void work()
{
    kmp();
    p=-1;
    for(int i=0; i<N; i++)
    {
        dp[i+1]=max(dp[i+1],dp[i]);
        while(true)
        {
            bool de=0; //标记是否新加了匹配
            if(a[p+1]&&!pnum[a[p+1]])
            {
                pp[a[p+1]]=lev[i];
                pnum[a[p+1]]=1;
                de=1;
            }
            if(a[p+1]&&pp[a[p+1]]==lev[i]&&judge())
            {
                if(!de)
                    pnum[a[p+1]]++;
                break;
            }
            if(de)
                pnum[a[p+1]]--;
            if(p==-1)
                break;
//如果匹配失败，从i-p-1开始从新匹配
/*
10 5 10
2 4 2 4 2 1 7 1 7 1
1 2 1 2 1
*/
            if(pi[p]==-1)
            {
                i=i-p-1;
                p=-1;
                memset(pp,0,sizeof(pp));
                memset(pnum,0,sizeof(pnum));
                break;
            }
            //将已经已经无法匹配的去掉
            for(int j=pi[p]+1; j<=p; j++)
            {
                pnum[a[j]]--;
            }
            p=pi[p];
        }
        if(pp[a[p+1]]==lev[i])
            p++;
        if(p==M-1)
        {
            dp[i+1]=max(dp[i+1],dp[i+1-M]+1);
        }
    }
    printf("%d\n",dp[N]);
}

void input()
{
    for(int i=0; i<N; i++)
        scanf("%d",&lev[i]);
    for(int i=0; i<M; i++)
        scanf("%d",&a[i]);
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(pp,0,sizeof(pp));
    memset(pnum,0,sizeof(pnum));
    memset(a,0,sizeof(a));
    memset(pi,0,sizeof(pi));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        init();
        input();
        work();
    }
    return 0;
}
