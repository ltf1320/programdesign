#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=500;
const int inf=0x3f3f3f3f;

struct EDGE
{
    int to,next;
    double com,rate;
};
EDGE edge[maxn*2];
int box[maxn];

int n,m;

int ctn;
void add(int from,int to,double rate,double com)
{
    edge[ctn].to=to;
    edge[ctn].com=com;
    edge[ctn].rate=rate;
    edge[ctn].next=box[from];
    box[from]=ctn++;
}

int cnt[maxn];
bool in[maxn];
double dis[maxn];
queue<int> que;
double im;

bool spfa(int start)
{
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(cnt));
    for(int i=0; i<=n; i++) dis[i]=0;
    que.push(start);
    in[start]=1;
    dis[start]=im;
    cnt[start]++;
    int tmp;
    while(!que.empty())
    {
        if(dis[start]>im)
            return true;
        tmp=que.front();
        que.pop();
        for(int i=box[tmp]; i!=-1; i=edge[i].next)
        {
            if(dis[edge[i].to]<(dis[tmp]-edge[i].com)*edge[i].rate)
            {
                dis[edge[i].to]=(dis[tmp]-edge[i].com)*edge[i].rate;
                if(!in[edge[i].to])
                {
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    que.push(edge[i].to);
                    if(cnt[edge[i].to]>2*n)
                        return true;
                }
            }
        }
        in[tmp]=0;
    }
    return dis[start]>im;
}

void init()
{
    ctn=0;
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    int start;
    int a,b;
    double com1,com2,rate1,rate2;
    scanf("%d%d%d%lf",&n,&m,&start,&im);
    init();
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&rate1,&com1,&rate2,&com2);
        add(a,b,rate1,com1);
        add(b,a,rate2,com2);
    }
    if(spfa(start))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
