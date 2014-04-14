#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
const int inf=0x3f3f3f3f;
int N;

int state[maxn];

bool nst[maxn][maxn];

void getNst()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            nst[i][j]=state[i]&(1<<j);
}

void chose(int i,int j)
{
    nst[i][j]^=1;
    if(i>0)
        nst[i-1][j]^=1;
    if(i<N-1)
        nst[i+1][j]^=1;
    if(j>0)
        nst[i][j-1]^=1;
    if(j<N-1)
        nst[i][j+1]^=1;
}

int count(int st)
{
    int res=0;
    for(int i=0; i<N; i++)
        if(st&(1<<i))
        {
            res++;
            chose(0,i);
        }
    for(int i=1; i<N; i++)
        for(int j=0; j<N; j++)
            if(nst[i-1][j])
            {
                res++;
                chose(i,j);
            }
    for(int i=0; i<N; i++)
        if(nst[N-1][i])
            return inf;
    return res;
}

void work()
{
    int res=inf;
    for(int i=0;i<(1<<N);i++)
    {
        getNst();
        res=min(res,count(i));
    }
    if(res==inf)
        puts("-1");
    else
        printf("%d\n",res);
}

void input()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&state[i]);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
