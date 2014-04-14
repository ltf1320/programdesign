#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=50+10;
int N,M;
int d,f,b;
int map[50][50];
int res;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

void fby()
{
    for(int i=0;i<N;i++)
    {
        if(!map[i][0])
        {
            res+=f;
            map[i][0]=1;
        }
        if(!map[i][M-1])
        {
            res+=f;
            map[i][M-1]=1;
        }
    }
    for(int i=0;i<M;i++)
    {
        if(!map[0][i])
        {
            res+=f;
            map[0][i]=1;
        }
        if(!map[N-1][i])
        {
            res+=f;
            map[0][i]=1;
        }
    }
}

void k2(int df,int co)
{
    int cnt;
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
        {
            if(map[i][j]==df)
            {
                cnt=0;
                for(int k=0;k<4;k++)
                {
                    if(map[i+dx[k]][j+dy[k]]!=df)
                        cnt++;
                }
                if(cnt==3)
                {
                    res+=co;
                    map[i][j]^=1;
                }
            }
        }
}

void k4(int df,int co)
{
    int cnt;
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
        {
            if(map[i][j]==df)
            {
                cnt=0;
                for(int k=0;k<4;k++)
                {
                    if(map[i+dx[k]][j+dy[k]]!=df)
                        cnt++;
                }
                if(cnt==4)
                {
                    res+=co;
                    map[i][j]^=1;
                }
            }
        }
}


void input()
{
    scanf("%d%d",&M,&N);
    scanf("%d%d%d",&d,&f,&b);
    char tmp;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            tmp=getchar();
            if(tmp==' '||tmp=='\n')
            {
                j--;
                continue;
            }
            if(tmp=='#')
                map[i][j]=1;
            else map[i][j]=0;
        }
}

void getf()
{
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
        {
            if(map[i][j]!=map[i-1][j])
                res+=b;
            if(map[i][j]!=map[i][j-1])
                res+=b;
        }
    for(int j=1;j<M-1;j++)
    {
        if(map[N-2][j]!=map[N-2][j+1])
            res+=b;
        if(map[N-1][j]!=map[N-2][j])
            res+=b;
    }
}

void work()
{
    res=0;
    fby();
    if(d<2*b)
        k2(1,d);
    if(f<2*b)
        k2(0,f);
    if(d<4*b)
        k4(1,d);
    if(f<4*b)
        k4(1,f);
    getf();
    printf("%d\n",res);
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
