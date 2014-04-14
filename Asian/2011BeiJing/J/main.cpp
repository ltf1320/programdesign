#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=8;
int N,M,K;
const int dx[]= {-1,0,1,-1,1,-1,0,1};
const int dy[]= {1,1,1,0,0,-1,-1,-1};

struct State
{
    int map[maxn][maxn];
    void print()
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
                printf("%d ",map[i][j]);
            puts("");
        }
    }
    void fall()
    {
        int k;
        for(int i=0; i<M; i++)
        {
            for(int j=N-1; j>=0; j--)
            {
                if(map[j][i])
                {
                    k=j+1;
                    while(!map[k][i]&&k<N)
                        k++;
                    if(k!=j+1)
                    {
                        map[k-1][i]=map[j][i];
                        map[j][i]=0;
                    }
                }
            }
        }
        for(int s=0; s<M-1; s++)
        {
            bool flag=0;
            for(k=s; k<M; k++)
            {
                for(int j=0; j<N; j++)
                {
                    if(map[j][k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag&&k>s)
            {
                for(int i=s; i<M-k; i++)
                {
                    for(int j=0; j<N; j++)
                    {
                        map[j][i]=map[j][i+k];
                        map[j][i+k]=0;
                    }
                }
            }
        }
    }
};
State startst;
bool vis[maxn][maxn];
int dfs(State& st,int x,int y,int col)
{
    st.map[x][y]=0;
    vis[x][y]=1;
    int nx,ny;
    int res=1;
    for(int i=0; i<7; i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=N) continue;
        if(st.map[nx][ny]==col)
            res+=dfs(st,nx,ny,col);
    }
    return res;
}


struct FSO
{
    State st;
    int score;
    FSO(State ss,int s):st(ss),score(s) {}
    FSO() {}
};

queue<FSO> que;

int bfs()
{
    que.push(FSO(startst,0));
    FSO now;
    State nst;
    int sc;
    int res=0;
    while(!que.empty())
    {
        memset(vis,0,sizeof(vis));
        now=que.front();
        res=max(res,now.score);
//        cout<<que.size()<<endl;
        que.pop();
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(!vis[i][j]&&now.st.map[i][j])
                {
                    nst=now.st;
                    sc=dfs(nst,i,j,nst.map[i][j]);
                    if(sc>=3)
                    {
                        /*
                        now.st.print();
                        puts("");
                        printf("%d %d %d\n",i,j,now.st.map[i][j]);
                        printf("%d\n",now.score+sc*sc);
                        puts("");
                        nst.print();
                        puts("");
                        nst.fall();
                        nst.print();
                        puts("");
                        puts("------");
                        */
                        nst.fall();
                        que.push(FSO(nst,now.score+sc*sc));
                    }
                }
            }
    }
    return res;
}

void work()
{
    printf("%d\n",bfs());
}

void input()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d",&startst.map[i][j]);
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        input();
        work();
    }
    return 0;
}
