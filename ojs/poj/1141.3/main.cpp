//È¥ÄãÃÃµÄ¿ÕÐÐ

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=110;
const int inf=0x3f3f3f3f;
int N;
char s[maxn];
int dp[maxn][maxn];
int f[maxn][maxn];

void print(int i,int j)
{
    if(i>j) return;
    if(i==j)
    {
        if(s[i]=='('||s[i]==')')
            printf("()");
        else printf("[]");
        return;
    }
    if(f[i][j]>=0) //!=
    {
        print(i,f[i][j]);
        print(f[i][j]+1,j);
    }
    else
    {
        switch(f[i][j])
        {
        case -1:
            putchar('(');
            print(i,j-1);
            putchar(')');
   //         printf("()");
            break;
        case -2:
            putchar('[');
            print(i,j-1);
            putchar(']');
   //         printf("[]");
            break;
        case -3:
            putchar('(');
   //         printf("()");
            print(i+1,j);
            putchar(')');
            break;
        case -4:
            putchar('[');
    //        printf("[]");
            print(i+1,j);
            putchar(']');
            break;
        case -5:
            putchar('(');
            print(i+1,j-1);
            putchar(')');
            break;
        case -6:
            putchar('[');
            print(i+1,j-1);
            putchar(']');
            break;
        case -7:
            if(s[i]==')'||s[i]=='(')
                printf("()");
            else printf("[]");
            print(i+1,j-1);
            if(s[j]==')'||s[j]=='(') //!
                printf("()");
            else printf("[]");
        }
    }
}

void pdp()
{
    for(int i=0; i<N; i++)
    {
        for(int k=0; k<N; k++)
            printf("%d ",dp[i][k]);
        putchar('\n');
    }
}

void pf()
{
    for(int i=0; i<N; i++)
    {
        for(int k=0; k<N; k++)
            printf("%d ",f[i][k]);
        putchar('\n');
    }
}

void work()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            dp[i][j]=inf;
    dp[0][0]=1;
    for(int i=1; i<N; i++)
    {
        dp[i][i]=1;
        dp[i][i-1]=0;
    }
    int j;
    for(int l=1; l<N; l++)
        for(int i=0; i<N-l; i++)
        {
            j=i+l;
            if(s[i]=='('&&s[j]==')')
            {
                if(dp[i][j]>dp[i+1][j-1])
                {
                    dp[i][j]=dp[i+1][j-1];
                    f[i][j]=-5;
                }
            }
            if(s[i]=='['&&s[j]==']')
            {
                if(dp[i][j]>dp[i+1][j-1])
                {
                    dp[i][j]=dp[i+1][j-1];
                    f[i][j]=-6;
                }
            }
            if(s[i]=='(')
            {
                if(dp[i][j]>dp[i+1][j]+1)
                {
                    dp[i][j]=dp[i+1][j]+1;
                    f[i][j]=-3;
                }
            }
            if(s[i]=='[')
            {
                if(dp[i][j]>dp[i+1][j]+1)
                {
                    dp[i][j]=dp[i+1][j]+1;
                    f[i][j]=-4;
                }
            }
            if(s[j]==')')
            {
                if(dp[i][j]>dp[i][j-1]+1)
                {
                    dp[i][j]=dp[i][j-1]+1;
                    f[i][j]=-1;
                }
            }
            if(s[j]==']')
            {
                if(dp[i][j]>dp[i][j-1]+1)
                {
                    dp[i][j]=dp[i][j-1]+1;
                    f[i][j]=-2;
                }
            }
            if(dp[i][j]>dp[i+1][j-1]+2)
            {
                dp[i][j]=dp[i+1][j-1]+2; //!
                f[i][j]=-7;
            }
            for(int k=i; k<j; k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j];
                    f[i][j]=k;
                }
            }
        }
    print(0,N-1);
    putchar('\n');
 //   pdp();
 //   pf();
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ch;
    int kk;
    while(~scanf("%c",&ch))
    {
  //      scanf("%c",&ch);
        kk=0;
        if(ch=='\n') {putchar('\n');return 0;} //!!!!!!
        while(ch!='\n')
        {
            s[kk++]=ch;
            ch=getchar();
        }
        s[kk]=0;
        N=kk;
        work();
    }
    return 0;
}
