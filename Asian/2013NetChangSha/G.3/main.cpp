#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=80000+100;
int N;
int pri[maxn];
bool ispri[maxn];
int prn;

void getPri(int n)
{
    for(int i=2; i<=n; i+=2)
        ispri[i]=1;
    pri[prn++]=2;
    for(int i=3; i<=n; i++)
    {
        if(ispri[i])
            ispri[i]=0;
        else
        {
            ispri[i]=1;
            pri[prn++]=i;
            for(int j=i; j<=n; j+=2*i)
                ispri[j]=1;
        }
    }
}

int divn[maxn];
int decn[maxn];

void pre()
{
    getPri(80000);
}

int fdiv(int now,int pr)
{
    int res=0;
    for(int i=0; i<prn&&pri[i]*pri[i]<=now; i++)
    {
        if(now%pri[i]==0&&ispri[now/pri[i]])
        {
            res++;
            if(pri[i]*pri[i]==now)
            {
                res++;
                if(pr==pri[i])
                    res++;
            }
        }
        return res;
    }
    return 0;
}

int fdec(int now,int pr)
{
    int res=0;
    for(int i=0; i<prn&&pri[i]+pri[i]<=now; i++)
    {
        if(ispri[now-pri[i]])
        {
            res++;
            if(pri[i]+pri[i]==now)
            {
                res++;
                if(pr==pri[i])
                    res++;
            }
        }
    }
    return res;
}

int res[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    int res1,res2;
    for(N=1;N<=80000;N++)
    {
        res1=res2=0;
        for(int i=0; i<prn&&pri[i]<N; i++)
        {
            res1+=fdec(N-pri[i],pri[i]);
            if(fdiv(N-pri[i],-1))
                res1+=3;
            if(N%pri[i]==0)
                res1+=fdiv(N/pri[i],pri[i]);
        }
        if(fdiv(N,-1))
            res1+=3;
        if(ispri[N])
            res1+=3;

        for(int i=0; i<prn&&pri[i]+pri[i]<=N; i++)
            if(ispri[N-pri[i]])
                res1+=3;
  //      cout<<res1<<endl;
        res[N]=res1/3;
    }

    while(~scanf("%d",&N))
    {
        printf("%d\n",res[N]);
    }
    return 0;
}
