#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=60;
int N,K;

struct Inter
{
    int x,y,r;
};
Inter ins[maxn];

struct State
{
    bool map[maxn][maxn];
    int num;
    State():num(0),has(0)
    {
        memset(map,0,sizeof(map));
    }
    int has;
    void printMap()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                printf("%d ",map[i][j]);
            puts("");
        }
    }
    void update(int x,int y,int r)
    {
        for(int i=0; i<=r; i++)
        {
            for(int j=0; j<=r-i; j++)
            {
                if(x+i<N)
                {
                    if(y+j<N)
                        map[x+i][y+j]=1;
                    if(y-j>=0)
                        map[x+i][y-j]=1;
                }
                if(x-i>=0)
                {
                    if(y+j<N)
                        map[x-i][y+j]=1;
                    if(y-j>=0)
                        map[x-i][y-j]=1;
                }
            }
        }
    }
    bool isEnd()
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                if(!map[i][j])
                    return false;
            }
        return true;
    }
};
bool in[2000];
queue<State> que;

int bfs()
{
    State now,tmp;
    for(int i=0;i<K;i++)
        tmp.map[ins[i].x][ins[i].y]=1;
    que.push(tmp);
    if(tmp.isEnd()) return 0;
    int has;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0; i<K; i++)
        {
            if(!(now.has&(1<<i)))
            {
                has=now.has|(1<<i);
                if(in[has]) continue;
                tmp=now;
                tmp.has=has;
                tmp.num++;
                tmp.update(ins[i].x,ins[i].y,ins[i].r);
 //               tmp.printMap();
                if(tmp.isEnd())
                    return tmp.num;
                in[tmp.has]=1;
                que.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        while(!que.empty()) que.pop();
        memset(in,0,sizeof(in));

        scanf("%d",&K);
        for(int i=0;i<K;i++)
        {
            scanf("%d%d",&ins[i].x,&ins[i].y);
            ins[i].x--;
            ins[i].y--;
        }
        for(int i=0;i<K;i++)
            scanf("%d",&ins[i].r);

        printf("%d\n",bfs());
    }
    return 0;
}
