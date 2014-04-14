#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=3100;

char ans[maxn][maxn];

void conn(int x,int y)
{
    ans[x][y]='Y';
    ans[y][x]='Y';
}

int N;
int mw=-1;
int now=1;
int main()
{
  //  freopen("out.txt","w",stdout);
    scanf("%d",&N);
    memset(ans,'N',sizeof(ans));
    for(int i=31; i>=0; i--)
    {
        if(N&(1<<i))
        {
            if(mw==-1)
                mw=i;
            now++;
            conn(0,now);
            for(int j=0; j<i; j++)
            {
                conn(now,now+1);
                conn(now,now+2);
                conn(now+1,now+3);
                conn(now+2,now+3);

                now+=3;
            }
            for(int j=i; j<mw; j++)
            {
                conn(now,now+1);
                conn(now+1,now+2);
                now+=2;
            }
            conn(1,now);
            //    cout<<now<<endl;
        }
    }
    now++;
    printf("%d\n",now);
    for(int i=0; i<now; i++)
    {
        for(int j=0; j<now; j++)
            putchar(ans[i][j]);
        puts("");
    }
    return 0;
}
