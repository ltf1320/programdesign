#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+100;
const int maxk=100+10;
const int MOD=1E9+7;

int cnt=0;

int N,M,K;
int prsum;
int pri[10];
int prn;

int yzs[100];
int yzh[100];
int yzn;
int wc[maxn];

void div(int n)
{
    prn=yzn=prsum=0;
    int now=n;
    int p;
    yzs[yzn++]=1;
    for(int i=2; i<=n; i++)
    {
        if(n%i==0)
        {
            yzs[yzn++]=i;
            if(now%i==0)
            {
                pri[prn]=i;
                p=1;
                while(now%i==0)
                {
                    now/=i;
                    p*=i;
                }
                wc[prn]=p;
                prsum+=p;
                prn++;
            }
        }
    }
}

int dp[2][maxn][maxn];//k st j

struct Node
{
    int st,i;
};
bool in[2][maxn][maxn];
Node que[2][16000];
int tail[2];
void work()
{
    div(M);
    for(int i=0;i<yzn;i++)
    {
        yzh[i]=0;
        for(int j=0;j<prn;j++)
            if(yzs[i]%wc[j]==0)
                yzh[i]|=(1<<j);
    }
  //  memset(dp,0,sizeof(dp));
    if(prsum-prn+K>N||K>N)
    {
        printf("0\n");
        return;
    }
    dp[0][0][0]=1;
    que[0][tail[0]].st=0;
    que[0][tail[0]++].i=0;
    int st,i,nst;
    for(int k=0; k<K; k++)
    {
//       memset(dp[(k&1)^1],0,sizeof(dp[0]));
//        memset(in,0,sizeof(in));
        tail[(k&1)^1]=0;
        for(int p=0; p<tail[k&1]; p++)
        {
            st=que[k&1][p].st;
            i=que[k&1][p].i;
            for(int j=0; j<yzn; j++)
            {
                if(i+yzs[j]<=N)
                {
                    nst=st|yzh[j];
                    dp[(k&1)^1][nst][i+yzs[j]]+=dp[k&1][st][i];
                    if(dp[(k&1)^1][nst][i+yzs[j]]>=MOD)
                        dp[(k&1)^1][nst][i+yzs[j]]-=MOD;
                    if(!in[(k&1)^1][nst][i+yzs[j]])
                    {
                        in[(k&1)^1][nst][i+yzs[j]]=1;
                        que[(k&1)^1][tail[(k&1)^1]].st=nst;
                        que[(k&1)^1][tail[(k&1)^1]++].i=i+yzs[j];
                    }
                }
                else
                    break;
            }
            in[k&1][st][i]=0;
            dp[k&1][st][i]=0;
        }
    }
    printf("%d\n",dp[K&1][(1<<prn)-1][N]);
    for(int p=0; p<tail[K&1]; p++)
    {
        st=que[K&1][p].st;
        i=que[K&1][p].i;
        in[K&1][st][i]=0;
        dp[K&1][st][i]=0;
    }
}

void init()
{
    tail[0]=tail[1]=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        init();
        work();
    }
    //  cout<<endl<<cnt<<endl;
    return 0;
}
