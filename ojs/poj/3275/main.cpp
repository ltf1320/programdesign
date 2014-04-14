#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxm=20000;
int N,M;

struct EDGE
{
    int next,to;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}
int indu[maxn];
queue<int> que;
void work()
{
    int res=0,now;
    for(int i=1;i<=N;i++)
        if(indu[i]==0)
            que.push(i);
    for(int i=0;i<N;i++)
    {
        res+=que.size()*(que.size()-1)/2;
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            indu[edge[i].to]--;
            if(indu[edge[i].to]==0)
            {
                que.push(edge[i].to);
            }
        }
    }
    printf("%d\n",res);
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
        indu[t]++;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    init();
    input();
    work();
    return 0;
}
