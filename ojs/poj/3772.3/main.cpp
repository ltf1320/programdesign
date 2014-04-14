#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=16;
int N;
int all;
int goNext(int st)
{
    int tmp=7;
    tmp=tmp&st;
    tmp<<=1;
    tmp&=7;
    for(int i=0; i<3; i++)
        st&=(-1)^(1<<(i));
    st^=tmp;
    return st;
}

int out1(int st)
{
    if(st&(1<<(3)))
        st^=(1<<(3))+(1<<(4));
    else st|=(1<<(3));
    return st;
}

struct FSO
{
    bool used[maxn];
    int n,state,score;
    int exp;
    FSO()
    {
        memset(used,0,sizeof(used));
        state=0;
        score=0;
        n=0;
        exp=all;
    }
    FSO(const FSO &a,int sc,int st,int k)
    {
        memcpy(used,a.used,sizeof(used));
        used[k]=1;
        exp=sc;
        for(int i=0;i<N;i++)
            if(!used[k])
                exp++;
        state=st;
        score=sc;
        n=a.n+1;
    }
    bool operator<(const FSO &a) const
    {
        return exp>a.exp;
    }
};

int map[maxn][maxn];
int sum[maxn];
int res;

priority_queue<FSO> que;

void bfs()
{
    int nxt,sc;
    FSO now;
    que.push(FSO());
    while(!que.empty())
    {
        now=que.top();
        que.pop();
        if(now.n==N||(now.state>>3)==3)
        {
            if(now.score>res) res=now.score;
            continue;
        }
        for(int i=0; i<N; i++)
        {
            if(!now.used[i])
            {
                switch(map[i][now.n])
                {
                case 0:
                    nxt=out1(now.state);
                    que.push(FSO(now,now.score,nxt,i));
                    break;
                case 1:
                    sc=now.state&(1<<2)?1:0;
                    nxt=out1(now.state);
                    nxt=goNext(now.state);
                    que.push(FSO(now,now.score+sc,nxt,i));
                    break;
                case 2:
                    sc=now.state&(1<<2)?1:0;
                    nxt=goNext(now.state);
                    nxt|=1;
                    que.push(FSO(now,now.score+sc,nxt,i));
                    break;
                case 3:
                    sc=1;
                    nxt=now.state;
                    for(int p=0; p<3; p++)
                    {
                        if(now.state&(1<<p))
                            sc++;
                        nxt&=((-1)^(1<<p));
                    }
                    que.push(FSO(now,now.score+sc,nxt,i));
                    break;
                }
            }
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        memset(sum,0,sizeof(sum));
        all=0;
        while(!que.empty()) que.pop();
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]==3)
                {
                    sum[i]+=1;
                    all++;
                }
            }
        res=0;
        bfs();
        printf("%d\n",res);
    }
    return 0;
}
