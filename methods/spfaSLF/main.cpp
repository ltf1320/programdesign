#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=50000+1000;
const int inf=0x3f3f3f;
const int pengpeng=50001;
struct EDGE
{
    int to,next;
} edge[maxn];
int box[maxn];

int ctn;
void add(int from,int to)
{
    edge[ctn].to=to;
    edge[ctn].next=box[from];
    box[from]=ctn++;
}

int cnt[maxn];
bool in[maxn];
int dis[maxn];
deque<int> que;

int n,m;

bool spfa(int start)
{
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    for(int i=0; i<=n; i++)
        dis[i]=inf;
    que.push_back(start);
    in[start]=0;
    dis[start]=0;
    cnt[start]++;
    int tmp;
    int flagdis;
    while(!que.empty())
    {
        tmp=que.front();
        flagdis=dis[tmp];
        que.pop_front();
        for(int i=box[tmp]; i!=-1; i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[tmp]+1)
            {
                dis[edge[i].to]=dis[tmp]+1;
                if(!in[edge[i].to])
                {
                    if(dis[edge[i].to]<flagdis)
                        que.push_front(edge[i].to);
                    else que.push_back(edge[i].to);
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>n)
                    {
                        while(!que.empty()) que.pop_front();
                        return false;
                    }
                }
            }
        }
        in[tmp]=0;
    }
    return true;
}

void init()
{
    ctn=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    int q,a,b;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        init();
        if(n==0&&m==0&&q==0) break;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(int i=0; i<q; i++)
        {
            scanf("%d",&a);
            add(pengpeng,a);
        }
        if(spfa(pengpeng))
        {
            if(dis[1]!=inf)
                printf("%d\n",dis[1]-1);
            else printf("Emmm..\n");
        }
        else printf("Emmm..\n");
    }
    return 0;
}
