#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
const int inf=0x3f3f3f3f;
int N;

int pp[1<<8];
int tn[1<<8];
int state[maxn];
int np;
int nst[maxn];
int res;
void pre()
{
    for(int i=0; i<(1<<8); i++)
    {
        pp[i]=tn[i]=0;
        for(int j=0; j<8; j++)
            if(i&(1<<j))
            {
                tn[i]++;
                pp[i]^=(1<<j);
                if(j)
                    pp[i]^=(1<<(j-1));
                if(j<7)
                    pp[i]^=(1<<(j+1));
            }
    }
}

void getNst()
{
    for(int i=0; i<N; i++)
        nst[i]=state[i];
}


void count(int st)
{
    int nres=0;
    nst[0]^=pp[st]&np;
    nst[1]^=st;
    nres+=tn[st];
    for(int i=1; i<N; i++)
    {
        nst[i]^=pp[nst[i-1]]&np;
        nres+=tn[nst[i-1]];
        if(nres>=res)
            return;
        if(i<N-1)
            nst[i+1]^=nst[i-1];
    }
    if(!nst[N-1])
        res=min(res,nres);
}

void work()
{
    np=(1<<N)-1;
    res=inf;
    for(int i=0; i<(1<<N); i++)
    {
        getNst();
        count(i);
    }
    if(res==inf)
        puts("-1");
    else
        printf("%d\n",res);
}

void input()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&state[i]);
}

int main()
{
    freopen("in.txt","r",stdin);
    pre();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
