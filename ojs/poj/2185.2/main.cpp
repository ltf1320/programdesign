#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn= 10000+100;
const int maxm=100;
int N,M;
char map[maxn][maxm];
int resn,resm;

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int pi[maxn];
int kmp1(int n)
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1;p<=M;p++)
    {
        while(k!=-1&&map[n][k+1]!=map[n][p])
            k=pi[k];
        if(map[n][k+1]==map[n][p])
            k=k+1;
        pi[p]=k;
    }
    return M-pi[M-1]-1;
}

int kmp2(int n)
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1;p<=N;p++)
    {
        while(k!=-1&&map[k+1][n]!=map[p][n])
            k=pi[k];
        if(map[k+1][n]==map[p][n])
            k=k+1;
        pi[p]=k;
    }
    return N-pi[N-1]-1;
}

void work()
{
    resn=resm=1;
    for(int i=0;i<N;i++)
        resn=lcm(resn,kmp1(i));
    for(int j=0;j<M;j++)
        resm=lcm(resm,kmp2(j));
    resn=min(resn,M);
    resm=min(resm,N);
    printf("%d\n",resn*resm);
}


void input()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%c",&map[i][j]);
            if(map[i][j]=='\n')
            {
                j--;
                continue;
            }
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        input();
        work();
    }
    return 0;
}
