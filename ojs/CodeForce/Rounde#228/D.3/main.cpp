#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1100;

char ans[maxn][maxn];

void conn(int x,int y)
{
    ans[x][y]='Y';
    ans[y][x]='Y';
}

int N;
int now=2;

void dn(int n)
{
    for(int i=0; i<n; i++)
    {
        conn(now,now+i+1);
        conn(now+i+1,now+n+1);
    }
    now+=n+1;
}

int d3[50];
int main()
{
    //  freopen("out.txt","w",stdout);
    scanf("%d",&N);
    memset(ans,'N',sizeof(ans));
    int pp=0;
    while(N)
    {
        d3[pp++]=N%3;
        N/=3;
    }
    for(int i=0; i<pp; i++)
    {
       if(d3[i])
        {
            conn(0,now);
            dn(d3[i]);
            for(int j=0; j<i; j++)
                dn(3);
            for(int j=i+1; j<pp; j++)
                dn(1);
            conn(now,1);
            now++;
        }
    }
    printf("%d\n",now);
    for(int i=0; i<now; i++)
    {
        for(int j=0; j<now; j++)
            putchar(ans[i][j]);
        puts("");
    }
    return 0;
}
