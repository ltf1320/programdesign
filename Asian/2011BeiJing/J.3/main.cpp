#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=8;
int N,M,K;
const int dx[]= {-1,0,1,-1,1,-1,0,1};
const int dy[]= {1,1,1,0,0,-1,-1,-1};
const int MOD=999997;

int bfall[maxn];

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
            if(!bfall[i]) continue;
            for(int j=bfall[i]; j>=0; j--)
            {
                if(map[j][i])
                {
                    k=j+1;
                    while(!map[k][i]&&k<bfall[i]+1)
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

struct zipState
{
    int map[maxn];
    bool operator==(const zipState &a)
    {
        for(int i=0; i<N; i++)
            if(map[i]!=a.map[i])
                return false;
        return true;
    }
    zipState() {}
    zipState(const State &a)
    {
        getZiped(a);
    }
    void getZiped(const State &a)
    {
        for(int i=0; i<N; i++)
        {
            map[i]=0;
            for(int j=0; j<M; j++)
                map[i]=map[i]*(K+1)+a.map[i][j];
        }
    }
    State unZip()
    {
        State res;
        int now;
        for(int i=0; i<N; i++)
        {
            now=map[i];
            for(int j=M-1; j>=0; j--)
            {
                res.map[i][j]=now%(K+1);
                now/=(K+1);
            }
        }
        return res;
    }
    int getHas()
    {
        int res=0;
        for(int i=0; i<N; i++)
            res+=map[i];
        return res%MOD;
    }
};

struct HasNode
{
    zipState zp;
    int sc;
    int next;
};

struct Has
{
    HasNode has[1000000];
    int box[MOD];
    int end;
    bool insert(zipState zp,int sc)
    {
        int h=zp.getHas();
        for(int i=box[h]; i!=-1; i=has[i].next)
        {
            if(zp==has[i].zp)
            {
                if(sc>has[i].sc)
                {
                    has[i].sc=sc;
                    return true;
                }
                else return false;
            }
        }
        has[end].zp=zp;
        has[end].sc=sc;
        has[end].next=box[h];
        box[h]=end++;
        return true;
    }
    void clear()
    {
        memset(box,-1,sizeof(box));
        end=0;
    }
};
Has has;
bool vis[maxn][maxn];

int dfs(State& st,int x,int y,int col)
{
    st.map[x][y]=0;
    vis[x][y]=1;
    bfall[y]=max(bfall[y],x);
    int nx,ny;
    int res=1;
    for(int i=0; i<8; i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M) continue;
        if(st.map[nx][ny]==col)
        {
            /*
            if(vis[nx][ny])
            {
                printf("%d",1/0);
            }
            */
            res+=dfs(st,nx,ny,col);
        }
    }
    return res;
}


struct FSO
{
    zipState st;
    int score;
    FSO(zipState ss,int s):st(ss),score(s) {}
    FSO() {}
};

queue<FSO> que;

int bfs()
{
    que.push(FSO(zipState(startst),0));
    FSO now;
    State nowst;
    State nst;
    zipState nzst;
    int sc;
    int res=0;
    while(!que.empty())
    {
        memset(vis,0,sizeof(vis));
        now=que.front();
        res=max(res,now.score);
        que.pop();
        nowst=now.st.unZip();
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(!vis[i][j]&&nowst.map[i][j])
                {
                    nst=nowst;
                    memset(bfall,0,sizeof(bfall));
                    sc=dfs(nst,i,j,nst.map[i][j]);
                    if(sc>=3)
                    {
/*
                        if(N)
                        {
                            nowst.print();
                            puts("");
                            printf("%d %d %d\n",i,j,nowst.map[i][j]);
                            printf("%d\n",now.score+sc*sc);
                            puts("");
                            nst.print();
                            puts("");
                            nst.fall();
                            nst.print();
                            puts("");
                            puts("------");
                        }
                        else*/
                        nst.fall();
                        nzst.getZiped(nst);
                        if(has.insert(nzst,now.score+sc*sc))
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

void init()
{
    has.clear();
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
 //   freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        init();
        input();
        work();
    }
    return 0;
}
