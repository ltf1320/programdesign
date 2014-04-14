#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=15;
int N,M;
int map[maxn][maxn];
int cd[maxn][maxn];
//0 for s,1 for f,2 for y,3 for g,4 for D
int dp[maxn][maxn][1<<maxn];
int startx,starty;
int nnd,edstate;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};

void input()
{
    char ch;
    nnd=1;
    edstate=0;
    memset(cd,0,sizeof(cd));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            ch=getchar();
            switch(ch)
            {
            case 'S':
                map[i][j]=0;
                break;
            case 'F':
                map[i][j]=1;
                cd[i][j]=0;
                startx=i;
                starty=j;
                break;
            case 'Y':
                map[i][j]=2;
                cd[i][j]=nnd;
                edstate|=1<<nnd;
                nnd++;
                break;
            case 'G':
                map[i][j]=3;
                cd[i][j]=nnd++;
                break;
            case 'D':
                map[i][j]=4;break;
            default:
                j--;
                continue;
            }
        }
}

struct State
{
    int x,y,st;
    State(int xx,int yy,int s):x(xx),y(yy),st(s) {}
    State() {}
};

bool check(int gg)
{
    State now;
    memset(dp,0,sizeof(dp));
    dp[startx][starty][0]=gg;
    queue<State> que;
    que.push(State(startx,starty,0));
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if((now.st&edstate)==edstate)return true;
        for(int i=0; i<4; i++)
        {
            if(now.x+dx[i]<0||now.x+dx[i]>=N||now.y+dy[i]<0||now.y+dy[i]>=N)continue;
            if(dp[now.x][now.y][now.st]<=0) continue;
            switch(map[now.x+dx[i]][now.y+dy[i]])
            {
            case 0:
            case 1:
                if(dp[now.x][now.y][now.st]-1>dp[now.x+dx[i]][now.y+dy[i]][now.st])
                {
                    dp[now.x+dx[i]][now.y+dy[i]][now.st]=dp[now.x][now.y][now.st]-1;
                    que.push(State(now.x+dx[i],now.y+dy[i],now.st));
                }
                break;
            case 2:
                if(dp[now.x][now.y][now.st]-1>dp[now.x+dx[i]][now.y+dy[i]][now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])])
                {
                    dp[now.x+dx[i]][now.y+dy[i]][now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])]=dp[now.x][now.y][now.st]-1;
                    que.push(State(now.x+dx[i],now.y+dy[i],now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])));
                }
                break;
            case 3:
                if(gg>dp[now.x+dx[i]][now.y+dy[i]][now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])])
                {
                    dp[now.x+dx[i]][now.y+dy[i]][now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])]=gg;
                    que.push(State(now.x+dx[i],now.y+dy[i],now.st|(1<<cd[now.x+dx[i]][now.y+dy[i]])));
                }
                if(dp[now.x][now.y][now.st]-1>dp[now.x+dx[i]][now.y+dy[i]][now.st])
                {
                    dp[now.x+dx[i]][now.y+dy[i]][now.st]=dp[now.x][now.y][now.st]-1;
                    que.push(State(now.x+dx[i],now.y+dy[i],now.st));
                }
                break;
            case 4:break;
            }
        }
    }
    return false;
}

int work()
{
    int l=0,r=1000;
    int m;
    while(r-l)
    {
        m=(r+l)/2;
        if(check(m)) r=m;
        else l=m;
        if(r-l==1)
        {
            if(check(l)) return l;
            else return r;
        }
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        input();
        printf("%d\n",work());
    }
    return 0;
}
