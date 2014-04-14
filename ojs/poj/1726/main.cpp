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
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                if(dp[i][j][k]==inf)
                    printf("%d ",-1);
                else
                    printf("%d ",dp[i][j][k]);
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
        return 1;
    case 'D':
        return 2;
    case 'L':
        return 3;
    case '.':
        return 4;
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
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
        dp[0][3][1]=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<4; j++)
            {
                for(int k=0; k<4; k++)
                {
                    if(dp[i][j][k]!=inf)
                    {
                        if(game[i+1]==4) //!
                        {
                            if(dp[i+1][j][k]>dp[i][j][k])
                            {
                                dp[i+1][j][k]=dp[i][j][k];
                                path[i+1][j][k]=4;
                            }
                            continue;
                        }
                        if(j==game[i+1]||k==game[i+1])
                        {
                            if(dp[i][j][k]+3<dp[i+1][j][k])
                            {
                                dp[i+1][j][k]=dp[i][j][k]+3;
                                path[i+1][j][k]=(j==game[i+1])?3:1;
                                from[i+1][j][k]=(j==game[i+1])?j:k;
                            }
                            continue;
                        }
                        if(game[i+1]==3)
                        {
                            if(j==1)
                            {
                                if(dp[i+1][3][k]>dp[i][j][k]+7)
                                {
                                    dp[i+1][3][k]=dp[i][j][k]+7;
                                    path[i+1][3][k]=3;
                                    from[i+1][3][k]=j;
                                }
                            }
                            else
                            {
                                if(dp[i+1][3][k]>dp[i][j][k]+1)
                                {
                                    dp[i+1][3][k]=dp[i][j][k]+1;
                                    path[i+1][3][k]=3;
                                    from[i+1][3][k]=j;
                                }
                                if(dp[i+1][j][3]>dp[i][j][k]+1)
                                {
                                    dp[i+1][j][3]=dp[i][j][k]+1;
                                    path[i+1][j][3]=1;
                                    from[i+1][j][3]=k;
                                }
                            }
                        }
                        else if(game[i+1]==1)
                        {
                            if(k==3)
                            {
                                if(dp[i+1][j][1]>dp[i][j][k]+7)
                                {
                                    dp[i+1][j][1]=dp[i][j][k]+7;
                                    path[i+1][j][1]=1;
                                    from[i+1][j][1]=k;
                                }
                            }
                            else
                            {
                                if(dp[i+1][1][k]>dp[i][j][k]+1)
                                {
                                    dp[i+1][1][k]=dp[i][j][k]+1;
                                    path[i+1][1][k]=3;
                                    from[i+1][1][k]=j;
                                }
                                if(dp[i+1][j][1]>dp[i][j][k]+1)
                                {
                                    dp[i+1][j][1]=dp[i][j][k]+1;
                                    path[i+1][j][1]=1;
                                    from[i+1][j][1]=k;
                                }
                            }
                        }
                        else
                        {
                            if(j==1)
                            {
                                if(dp[i+1][game[i+1]][k]>dp[i][j][k]+5)
                                {
                                    dp[i+1][game[i+1]][k]=dp[i][j][k]+5;
                                    path[i+1][game[i+1]][k]=3;
                                    from[i+1][game[i+1]][k]=j;
                                }
                            }
                            else if(k==3)
                            {
                                if(dp[i+1][j][game[i+1]]>dp[i][j][k]+5)
                                {
                                    dp[i+1][j][game[i+1]]=dp[i][j][k]+5;
                                    path[i+1][j][game[i+1]]=1;
                                    from[i+1][j][game[i+1]]=k;
                                }
                            }
                            else
                            {
                                if(dp[i+1][game[i+1]][k]>dp[i][j][k]+1)
                                {
                                    dp[i+1][game[i+1]][k]=dp[i][j][k]+1;
                                    path[i+1][game[i+1]][k]=3;
                                    from[i+1][game[i+1]][k]=j;
                                }
                                if(dp[i+1][j][game[i+1]]>dp[i][j][k]+1)
                                {
                                    dp[i+1][j][game[i+1]]=dp[i][j][k]+1;
                                    path[i+1][j][game[i+1]]=1;
                                    from[i+1][j][game[i+1]]=k;
                                }
                            }
                        }
                    }
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
        for(int i=N;i>0;i--)
        {
            pstack[pn++]=path[i][l][r];
            if(path[i][l][r]==3)
                l=from[i][l][r];
            else if(path[i][l][r]==1)
                r=from[i][l][r];
        }
        while(pn)
        {
            --pn;
            if(pstack[pn]==1) putchar('R');
            else if(pstack[pn]==3) putchar('L');
            else putchar('.');
        }
        putchar('\n');
        printdp();
    }
    return 0;
}
