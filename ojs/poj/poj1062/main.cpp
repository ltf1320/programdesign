#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1000;
const int inf=0x3f3f3f3f;

int m,n;
int lowestLever;
bool exlev[maxn];
int levs[maxn];

struct EDGE
{
    int to,next;
    int v;
};
EDGE edge[maxn];
int box[maxn];
int ctn;
void add(int from,int to,int vv)
{
    edge[ctn].to=to;
    edge[ctn].v=vv;
    edge[ctn].next=box[from];
    box[from]=ctn++;
}

int cnt[maxn];
int dis[maxn];
bool in[maxn];
queue<int> que;

bool spfa(int start)
{
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    for(int i=0;i<=n;i++) dis[i]=inf;
    que.push(start);
    dis[start]=0;
    cnt[start]++;
    int tmp;
    while(!que.empty())
    {
        tmp=que.front();
        que.pop();
        for(int i=box[tmp];i!=-1;i=edge[i].next)
        {
            if(levs[edge[i].to]>lowestLever+m) continue;
            if(levs[edge[i].to]<lowestLever) continue;
            if(dis[edge[i].to]>dis[tmp]+edge[i].v)
            {
                dis[edge[i].to]=dis[tmp]+edge[i].v;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>n){
                        while(!que.empty()) que.pop();
                        return false;
                    }
                    que.push(edge[i].to);
                }
            }
        }
        in[tmp]=0;
    }
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(box,-1,sizeof(box));
    memset(exlev,0,sizeof(exlev));
    ctn=0;
    scanf("%d%d",&m,&n);
    int P,L,X;
    int t,yh;
    int maxlever=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&P,&L,&X);
        if(L>maxlever) maxlever=L;
        levs[i]=L;
        exlev[L]=1;
        add(0,i,P);
        for(int j=0;j<X;j++)
        {
            scanf("%d%d",&t,&yh);
            add(t,i,yh);
        }
    }
    int res=inf;
    for(int i=0;i<=maxlever;i++)
    {
        if(exlev[i])
        {
            lowestLever=i;
            if(spfa(0)&&dis[1]<res) res=dis[1];

        }
    }
    printf("%d\n",res);
    return 0;
}
