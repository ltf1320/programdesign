#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXN 100100
#define MAXK 30

using namespace std;
int N,M,K;
int lev[MAXN];

int pipei[MAXK];
int pnum[MAXK];

int dp[MAXN];
int next[MAXN];
int a[MAXN];

void getnext()
{
    memset(next,0,sizeof(next));
    int i=-1,j=0;
    next[0]=-1;
    while(j<M)
    {
       if(i==-1||a[i]==a[j])
       {
           i++;  j++;
           next[j]=i;
       }
       else i=next[i];
    }
}

bool judge()
{
    int pre=1;
    while(pnum[pre]==0)
        pre++;
    for(int j=pre+1; j<=K; j++)
    {
        if(pnum[j])
        {
            if(pipei[j]<=pipei[pre])
                return false;
            pre=j;
        }
    }
    return true;
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
    memset(pnum,0,sizeof(pnum));
    memset(a,0,sizeof(a));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        init();
        input();
        getnext();
        int p=-1;
        for(int i=0; i<N; i++)
        {
            dp[i+1]=max(dp[i+1],dp[i]);
            while(true)
            {
                bool de=0;
                if(a[p+1]&&!pnum[a[p+1]])
                {
                    pipei[a[p+1]]=lev[i];
                    pnum[a[p+1]]=1;
                    de=1;
                }
                if(a[p+1]&&pipei[a[p+1]]==lev[i]&&judge())
                {
                    if(!de)
                        pnum[a[p+1]]++;
                    break;
                }
                if(de)
                    pnum[a[p+1]]--;
                if(p==-1)
                    break;
                if(next[p]==-1)
                {
                    i=i-p-1;
                    p=-1;
                    memset(pipei,0,sizeof(pipei));
                    memset(pnum,0,sizeof(pnum));
                    break;
                }
                for(int j=next[p]+1; j<=p; j++)
                {
                    pnum[a[j]]--;
                }
                p=next[p];
            }
            if(pipei[a[p+1]]==lev[i])
                p++;
            if(p==M-1)
            {
                dp[i+1]=max(dp[i+1],dp[i+1-M]+1);
            }
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}
