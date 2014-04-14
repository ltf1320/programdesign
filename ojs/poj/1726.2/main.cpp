#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
const int inf=0x3f3f3f3f;
int game[maxn];
int dp[maxn][4][4];
int path[maxn][4][4];
int from[maxn][4][4];
int pstack[maxn];
int N;

void printdp()
{
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                if(dp[i][j][k]==inf)
                    printf("%d %d ",-1,-1);
                else
                    printf("%d %d ",from[i][j][k],dp[i][j][k]);
        putchar('\n');
    }
}

int getType(char ch)
{
    switch(ch)
    {
    case 'U':
        return 0;
    case 'R':
        return 2;
    case 'D':
        return 3;
    case 'L':
        return 1;
    case '.':
        return 4;
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int p;
    char ch;
    int l,r;
    int pn;
    while(true)
    {
        p=1;
        ch=getchar();
        if(ch=='#') break;
        while(ch!='\n')
        {
            game[p]=getType(ch);
            if(game[p]!=-1)
                p++;
            ch=getchar();
        }
        N=p-1;
        if(game[0]=='#') break;
        for(int i=0; i<=N; i++)
            for(int j=0; j<4; j++)
                for(int k=0; k<4; k++)
                    dp[i][j][k]=inf;
        dp[0][1][2]=0;
        path[0][1][2]=4;
        int d;
        for(int i=1; i<=N; i++)
        {
            //◊ÛΩ≈
            for(int j=0; j<4; j++)
                for(int k=0; k<4; k++)
                {
                    if(game[i]==4)
                    {
                        dp[i][j][k]=dp[i-1][j][k];
                        path[i][j][k]=4;
                        continue;
                    }
                    if(!path[i-1][j][k]) continue;
                    if(game[i]==k) continue;
                    if(k==1&&game[i]!=j) continue;
                    if(k==j) continue;
                    d=1;
                    if(path[i-1][j][k]==1)
                    {
                        if(j==game[i]) d=3;
                        else if(j+game[i]==3) d=7;
                        else d=5;
                    }
                    if(dp[i][game[i]][k]>dp[i-1][j][k]+d)
                    {
                        dp[i][game[i]][k]=dp[i-1][j][k]+d;
                        path[i][game[i]][k]=1;
                        from[i][game[i]][k]=j;
                    }
                }
            //”“Ω≈
            for(int j=0; j<4; j++)
                for(int k=0; k<4; k++)
                {
                    if(game[i]==4)
                    {
                        dp[i][j][k]=dp[i-1][j][k];
                        path[i][j][k]=4;
                        continue;
                    }
                    if(!path[i-1][j][k]) continue;
                    if(game[i]==j) continue;
                    if(j==2&&game[i]!=k) continue;
                    if(k==j) continue;
                    d=1;
                    if(path[i-1][j][k]==2)
                    {
                        if(k==game[i]) d=3;
                        else if(k+game[i]==3) d=7;
                        else d=5;
                    }
                    if(dp[i][j][game[i]]>dp[i-1][j][k]+d)
                    {
                        dp[i][j][game[i]]=dp[i-1][j][k]+d;
                        path[i][j][game[i]]=2;
                        from[i][j][game[i]]=k;
                    }
                }
        }
        l=0,r=0;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                if(dp[N][i][j]<dp[N][l][r])
                {
                    l=i;
                    r=j;
                }
            }
        pn=0;
        for(int i=N; i>0; i--)
        {
            pstack[pn++]=path[i][l][r];
            if(path[i][l][r]==1)
                l=from[i][l][r];
            else if(path[i][l][r]==2)
                r=from[i][l][r];
        }
        while(pn)
        {
            --pn;
            if(pstack[pn]==2) putchar('R');
            else if(pstack[pn]==1) putchar('L');
            else putchar('.');
        }
        putchar('\n');
  //      printdp();
    }
    return 0;
}
