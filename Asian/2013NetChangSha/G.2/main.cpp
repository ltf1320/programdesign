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
    for(int i=2;i<=n;i+=2)
        ispri[i]=1;
    pri[prn++]=2;
    for(int i=3;i<=n;i++)
    {
        if(ispri[i])
            ispri[i]=0;
        else
        {
            ispri[i]=1;
            pri[prn++]=i;
            for(int j=i;j<=n;j+=2*i)
                ispri[j]=1;
        }
    }
}

int divn[maxn];
int decn[maxn];

void pre()
{
    getPri(80000);
    for(int i=2;i<=80000;i++)
    {
        for(int j=0;j<prn&&pri[j]+pri[j]<=i;j++)
        {
            if(ispri[i-pri[j]])
            {
                decn[i]++;
                if(pri[j]+pri[j]==i)
                    decn[i]++;
            }
        }
        for(int j=0;j<prn&&pri[j]*pri[j]<=i;j++)
        {
            if(i%pri[j]==0&&ispri[i/pri[j]])
            {
                divn[i]++;
                if(pri[j]*pri[j]==i)
                    divn[i]++;
                break;
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    int res1,res2;
    while(~scanf("%d",&N))
    {
        res1=res2=0;
        for(int i=0;i<prn&&pri[i]<N;i++)
        {
            res1+=decn[N-pri[i]];
            if(N==pri[i]*3)
                res1++;
            if(N%pri[i]==0)
            {
                res1+=divn[N/pri[i]];
                if(pri[i]*pri[i]*pri[i]==N)
                    res1++;
            }
            if(divn[N-pri[i]])
                res1+=3;
        }
        if(divn[N])
            res1+=3;
        if(ispri[N])
            res1+=3;
        for(int i=0; i<prn&&pri[i]+pri[i]<=N; i++)
            if(ispri[N-pri[i]])
                res1+=3;
        printf("%d\n",res1/3);
    }
    return 0;
}
