#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxk=30;
int N,M,K;
int lev[maxn];
int pp[maxk];
int fpp[maxk];
int pnum[maxk];
int dp[maxn];
int pi[maxn];
int a[maxn];

int count[maxk];
int ppn;

void kmp()
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

void pop(int i)
{
    for(int j=i-p; j<i-pi[p]; j++)
    {
        pnum[lev[j]]--;
        if(pnum[lev[j]]==0)
        {
            fpp[pp[lev[j]]]=0;
            pp[lev[j]]=0;
        }
    }
    p=pi[p];
}

int find(int i)
{
    int np=0;
    memset(count,0,sizeof(count));
    while(i>=0)
    {
        if(count[lev[i]]==0)
            np++;
        count[lev[i]]++;
        if(np>ppn) return i;
        i--;
    }
    return -1;
}


void work()
{
    kmp();
    memset(count,0,sizeof(count));
    for(int i=0; i<M; i++)
        count[a[i]]++;
    for(int i=0; i<maxk; i++)
        if(count[i])
            ppn++;
    p=-1;
    for(int i=0; i<N; i++)
    {
        dp[i+1]=max(dp[i+1],dp[i]);
        if(pp[lev[i]])
            pnum[lev[i]]++;
        else
        {
            bool flag=0;
            while(fpp[a[p+1]])
            {
                if(pi[p]==-1)
                {
                    i=find(i);
                    flag=1;
                    break;
                }
                pop(i);
            }
            if(flag)
            {
                p=-1;
                memset(fpp,0,sizeof(fpp));
                memset(pp,0,sizeof(pp));
                memset(pnum,0,sizeof(pnum));
                continue;
            }
            pp[lev[i]]=a[p+1];
            fpp[a[p+1]]=pp[lev[i]];
            pnum[lev[i]]=1;
        }
        while(true)
        {
            if(a[p+1]==pp[lev[i]])
            {
                p++;
                if(p==M-1)
                {
                    bool flag=1;
                    int w=1;
                    while(pnum[w]==0)
                        w++;
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
                    if(flag)
                    {
                        dp[i+1]=max(dp[i+1],dp[i+1-M]+1);
                    }
                    pop(i);
                }
                break;
            }
            else
            {
                if(p==-1) break;
                pop(i);
            }
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
    memset(fpp,0,sizeof(fpp));
    memset(pp,0,sizeof(pp));
    memset(pnum,0,sizeof(pnum));
    ppn=0;
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
