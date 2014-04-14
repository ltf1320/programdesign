#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool dp[120][15][50];
int md[15]= {0,31,28,31,30,31,30,31,31,30,31,30,31,0};

bool judgey(int a)
{
    if(a%4) return 0;
    if(a%400==0) return 1;
    if(a%100==0) return 0;
    return 1;
}

void pre()
{
    memset(dp,0,sizeof(dp));
    dp[2001-1900][11][3]=dp[2001-1900][10][4]=1;
    bool flag;
    md[11]=3;
    for(int m=11; m>0; m--)
        for(int d=md[m]; d>0; d--)
        {
            if(dp[2001-1900][m][d]) continue;
            flag=0;
            if(d<=md[m+1])
                if(!dp[2001-1900][m+1][d]) flag=1;
            if(d<md[m])
            {
                if(!dp[2001-1900][m][d+1]) flag=1;
            }
            else if(!dp[2001-1900][m+1][1]) flag=1;
            dp[2001-1900][m][d]=flag;
        }
    md[11]=30;
    dp[2001-1900][11][2]=0;
    /*
    for(int m=1; m<=11; m++)
    {
        for(int d=1; d<=md[m]; d++)
        {
            cout<<dp[2001-1900][m][d]<<" ";
        }
        cout<<endl;
    }
*/
    for(int y=2000-1900; y>=0; y--)
    {
        if(judgey(1900+y))  md[2]=29;
        else md[2]=28;
        for(int d=md[12]; d>0; d--)
        {
            flag=0;
            if(d<=md[1])
                if(!dp[y+1][1][d]) flag=1;
            if(d<md[12])
            {
                if(!dp[y][12][d+1]) flag=1;
            }
            else if(!dp[y+1][1][1]) flag=1;
            dp[y][12][d]=flag;
        }
        for(int m=11; m>0; m--)
            for(int d=md[m]; d>0; d--)
            {
                flag=0;
                if(d<=md[m+1])
                    if(!dp[y][m+1][d]) flag=1;
                if(d<md[m])
                {
                    if(!dp[y][m][d+1]) flag=1;
                }
                else if(!dp[y][m+1][1]) flag=1;
                dp[y][m][d]=flag;
            }
    }
}

int main()
{
    pre();
    int _;
    scanf("%d",&_);
    int y,m,d;
    while(_--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(dp[y-1900][m][d]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
