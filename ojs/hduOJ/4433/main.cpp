#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+10;
const int maxk=100+10;
const int inf=0x3f3f3f3f;
int num[maxn],des[maxn];
int N;
int dp[maxn][maxk];

inline int getnum(int a)
{
    if(a>=10) a-=10;
    if(a<0) a+=10;
    return a;
}

void printdp()
{
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(dp[i][j]!=inf)
                printf("%d ",dp[i][j]);
            else printf("%d ",-1);
        }
        putchar('\n');
    }
}

int work()
{
    int r,kn,tmp;
    tmp=num[0]*10+num[1];
    dp[0][tmp]=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(dp[i][j]!=inf)
            {
                kn=j%10;
                r=getnum(des[i]-j/10);
                tmp=getnum(kn)*10+getnum(num[i+2]);
                if(dp[i+1][tmp]>dp[i][j]+r)
                    dp[i+1][tmp]=dp[i][j]+r;
                if(dp[i+1][tmp]>dp[i][j]+10-r)
                    dp[i+1][tmp]=dp[i][j]+10-r;
                for(int k=1; k<=r; k++)
                {
                    for(int p=0; p<=k; p++)
                    {
                        tmp=getnum(kn+k)*10+getnum(num[i+2]+p);
                        if(dp[i+1][tmp]>dp[i][j]+r)
                            dp[i+1][tmp]=dp[i][j]+r;
                    }
                }
                r=10-r;
                for(int k=1; k<=r; k++)
                {
                    for(int p=0; p<=k; p++)
                    {
                        tmp=getnum(kn-k)*10+getnum(num[i+2]-p);
                        if(dp[i+1][tmp]>dp[i][j]+r)
                            dp[i+1][tmp]=dp[i][j]+r;
                    }
                }

            }
        }
    }
    return dp[N][0];
}

int input()
{
    char ch;
    char tmp[maxn];
    int p=0;
    if(scanf("%c",&ch)==EOF) return EOF;
    while(ch!=' ')
    {
        num[p++]=ch-'0';
        ch=getchar();
    }
    num[p]=num[p+1]=0;
    des[p]=num[p+1]=0;
    N=p;
    while((ch=getchar())==' ');
    for(int i=0; i<N-1; i++)
    {
        des[i]=ch-'0';
        ch=getchar();
    }
    des[N-1]=ch-'0';
    gets(tmp);
    for(int i=0; i<N+2; i++)
    {
        for(int j=0; j<maxn; j++)
            dp[i][j]=inf;
    }
    return 1;
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~input())
    {
        printf("%d\n",work());
        //      printdp();
    }
    return 0;
}
