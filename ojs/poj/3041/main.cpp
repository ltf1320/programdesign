#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=500+100;
const int maxm=10000+100;
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

int pa[maxn],pb[maxn];
int disa[maxn],disb[maxn];

bool bfs()
{
    memset(disa,0,sizeof(disa));
    memset(disb,0,sizeof(disb));
    bool flag=0;
    queue<int> que;
    for(int i=1; i<=N; i++)
        if(pa[i]==-1)
            que.push(i);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(!disb[edge[i].to])
            {
                disb[edge[i].to]=disa[now]+1;
                if(pb[edge[i].to]==-1) flag=1;
                else
                {
                    disa[pb[edge[i].to]]=disb[edge[i].to]+1;
                    que.push(pb[edge[i].to]);
                }
            }
        }
    }
    return flag;
}

bool dfs(int now)
{
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(disb[edge[i].to]==disa[now]+1)
        {
            disb[edge[i].to]=0;
            if(pb[edge[i].to]==-1||dfs(pb[edge[i].to]))
            {
                pb[edge[i].to]=now;
                pa[now]=edge[i].to;
                return 1;
            }
        }
    }
    return 0;
}



int Hopcroft_Karp()
{
    int res=0;
    while(bfs())
    {
        for(int i=1; i<=N; i++)
            if(pa[i]==-1&&dfs(i))
                res++;
    }
    return res;
}



int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        int f,t;
        memset(box,-1,sizeof(box));
        memset(pa,-1,sizeof(pa));
        memset(pb,-1,sizeof(pb));
        ent=0;
        for(int i=0; i<M; i++)
        {
            scanf("%d%d",&f,&t);
            add(f,t);
        }
        printf("%d\n",Hopcroft_Karp());
    }
    return 0;
}
