#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000;

int sum[maxn+100][20];

int pri[maxn+100];
int prin;
bool ispri[maxn+100];

void getPri(int N)
{
    for(int i=2;i<=N;i++)
        ispri[i]=1;
    for(int i=3;i<=N;i++)
    {
        if(ispri[i])
        {
            ispri[i]=0;
        }
        else
        {
            pri[prin++]=i;
            for(int j=i;j<=N;j+=2*i)
                ispri[j]=1;
        }
    }
}

int fj(int n)
{
    int res=0;
    for(int i=0;i<prin;i++)
    {
        if(n==1) break;
        while(n%pri[i]==0)
        {
            res++;
            n/=pri[i];
        }
    }
    return res;
}

void pre()
{
    getPri(maxn);
    sum[0][0]=1;
    for(int i=1;i<=maxn;i++)
    {
        for(int j=0;j<20;j++)
            sum[i][j]=sum[i][j-1];
        sum[i][fj(i)]++;
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
