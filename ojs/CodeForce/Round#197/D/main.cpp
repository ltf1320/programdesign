#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1<<17;
int N,M;
int dui[maxn*2+100];
int start;

void buildheap()
{
    int kk=0;
    for(int i=N-1;i>=0;i--)
    {
        kk^=1;
        for(int j=(1<<i);j<(1<<(i+1));j++)
        {
            if(kk)
                dui[j]=dui[j<<1]|dui[j<<1|1];
            else dui[j]=dui[j<<1]^dui[j<<1|1];
        }
    }
}

void change(int p,int b)
{
    dui[start+p-1]=b;
    int kk=0,now=start+p-1;
    for(int i=N-1;i>=0;i--)
    {
        kk^=1;
        now>>=1;
        if(kk)
            dui[now]=dui[now<<1]|dui[now<<1|1];
        else dui[now]=dui[now<<1]^dui[now<<1|1];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    start=1<<N;
    for(int i=0;i<start;i++)
    {
        scanf("%d",&dui[start+i]);
    }
    buildheap();
    int p,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&p,&b);
        change(p,b);
        printf("%d\n",dui[1]);
    }
    return 0;
}
