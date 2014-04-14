#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=10000+10;
const int inf=0x3f3f3f3f;
int N;

int du[maxn];
int time[maxn];
int mdis[maxn];

queue<int> que;

struct EDGE
{
    int to,next;
};
EDGE edge[maxn*100];
int box[maxn];
int ent;
void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}



int main()
{
    int v,m,f;
    memset(box,-1,sizeof(box));
    ent=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        mdis[i]=0;
        scanf("%d%d",&v,&m);
        time[i]=v;
        du[i]=m;
        if(m==0) {que.push(i);mdis[i]=0;}
        for(int j=0;j<m;j++)
        {
            scanf("%d",&f);
            add(f,i);
        }
    }
    int now,res=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            mdis[edge[i].to]=max(mdis[now]+time[now],mdis[edge[i].to]);
            du[edge[i].to]--;
            if(du[edge[i].to]==0)
                que.push(edge[i].to);
        }
        res=max(res,mdis[now]+time[now]);
    }
    printf("%d\n",res);
    return 0;
}
