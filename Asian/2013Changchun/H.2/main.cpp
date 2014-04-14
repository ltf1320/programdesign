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
int yzn;
int wc[maxn];

void div(int n)
{
    prn=yzn=prsum=0;
    memset(wc,-1,sizeof(wc));
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
                wc[p]=prn;
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
    Node(int s,int ii):st(s),i(ii) {}
    Node() {}
};
bool in[maxn][maxn];
queue<Node> que[2];

void work()
{
    /*
    if(N==1000&&M==840&&K==100)
    {
        printf("653643351\n");
        return;
    }
    */
    div(M);
    memset(dp,0,sizeof(dp));
    if(prsum-prn+K>N||K>N)
    {
        printf("0\n");
        return;
    }
    dp[0][0][0]=1;
    que[0].push(Node(0,0));
    int st,i,nst;
    for(int k=0; k<K; k++)
    {
        memset(dp[(k&1)^1],0,sizeof(dp[0]));
        memset(in,0,sizeof(in));
        while(!que[k&1].empty())
        {
            st=que[k&1].front().st;
            i=que[k&1].front().i;
            que[k&1].pop();
            for(int j=0; j<yzn; j++)
            {
                if(i+yzs[j]<=N)
                {
                    if(wc[yzs[j]]!=-1)
                    {
                        nst=st|(1<<wc[yzs[j]]);
                        dp[(k&1)^1][nst][i+yzs[j]]+=dp[k&1][st][i];
                        if(dp[(k&1)^1][nst][i+yzs[j]]>=MOD)
                            dp[(k&1)^1][nst][i+yzs[j]]-=MOD;
                        if(!in[nst][i+yzs[j]])
                        {
                            in[nst][i+yzs[j]]=1;
                            que[(k&1)^1].push(Node(nst,i+yzs[j]));
                        }
                    }
                    else
                    {
                        dp[(k&1)^1][st][i+yzs[j]]+=dp[k&1][st][i];
                        if(dp[(k&1)^1][st][i+yzs[j]]>=MOD)
                            dp[(k&1)^1][st][i+yzs[j]]-=MOD;
                        if(!in[st][i+yzs[j]])
                        {
                            in[st][i+yzs[j]]=1;
                            que[(k&1)^1].push(Node(st,i+yzs[j]));
                        }
                    }
                }
                else
                    break;
            }
        }
    }

    printf("%d\n",dp[K&1][(1<<prn)-1][N]);
}

void init()
{
    while(!que[0].empty())
        que[0].pop();
    while(!que[1].empty())
        que[1].pop();
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
