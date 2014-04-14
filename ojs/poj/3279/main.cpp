#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20;
const int inf=0x3f3f3f3f;
int N,M;

bool map[maxn][maxn];
bool res[maxn][maxn];
bool RES[maxn][maxn];
int fln,rfln;
bool now[maxn][maxn];

void flip(int x,int y)
{
    res[x][y]=1;
    if(x>0)
        now[x-1][y]^=1;
    if(x<N-1)
        now[x+1][y]^=1;
    if(y>0)
        now[x][y-1]^=1;
    if(y<M-1)
        now[x][y+1]^=1;
    now[x][y]^=1;
}

bool judge()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(now[i][j]) return false;
        }
    return true;
}

bool find(int state)
{
    fln=0;
    memset(res,0,sizeof(res));
    memcpy(now,map,sizeof(map));
    for(int i=0;i<M;i++)
    {
        if(state&(1<<i))
            flip(0,i);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(now[i-1][j])
                flip(i,j);
        }
    }
    if(judge())
        return true;
    else return false;
}

void printRes()
{
    for(int i=0;i<N;i++)
    {
        printf("%d",(int)RES[i][0]);
        for(int j=1;j<M;j++)
            printf(" %d",(int)RES[i][j]);
        puts("");
    }
}

bool compare()
{
    for(int i=0;i<N;i++)
        for(int j=M-1;j>=0;j--)
        {
            if(res[i][j]!=RES[i][j])
            {
                return RES[i][j];
            }
        }
    return false;
}

void work()
{
    rfln=inf;
    for(int i=0;i<(1<<M);i++)
        if(find(i))
        {
            if(fln<rfln)
            {
                memcpy(RES,res,sizeof(res));
                rfln=fln;
            }
            else if(fln==rfln)
            {
                if(compare())
                {
                    memcpy(RES,res,sizeof(res));
                    rfln=fln;
                }
            }
        }
    if(rfln==inf)
        printf("IMPOSSIBLE\n");
    else printRes();
}

void input()
{
    int tmp;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%d",&tmp);
            map[i][j]=tmp;
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
