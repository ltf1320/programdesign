#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=500+10;
const int inf=0x3f3f3f3f;
const int maxm=maxn*maxn;
int N,M;
struct EDGE
{
    int to,next,v;
};
EDGE edge[2*maxm];
int box[maxn];
int ent;

struct Bian
{
    int f,t,v;
};
Bian bs[maxm];

void _add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int v)
{
    _add(f,t,v);
    _add(t,f,v);
}

int dis[maxn],pre[maxn];
int cur[maxn],aug[maxn];
int gap[maxn];

int sap(int s, int e, int n)
{
    int max_flow = 0, v, u = s;
    int id, mindis;
    aug[s] = inf;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    for (int i = 0; i <= n; ++i){//初始化当前弧为第一条弧
        cur[i] = box[i];
    }

    while (dis[s] < n)
    {
        bool flag = false;
        if (u == e)
        {
            max_flow += aug[e];
            for (v = pre[e]; v != -1; v = pre[v])//路径回溯更新残留网络
            {
                id = cur[v];
                edge[id].v -= aug[e];
                edge[id^1].v += aug[e];
                aug[v] -= aug[e]; //修改可增广量，以后会用到
                if (edge[id].v == 0) u = v; //不回退到源点，仅回退到容量为0的弧的弧尾
            }
        }
        for (id = cur[u]; id != -1; id = edge[id].next)
        {   // 从当前弧开始查找允许弧
            v = edge[id].to;
            if (edge[id].v > 0 && dis[u] == dis[v] + 1) //找到允许弧
            {
                flag = true;
                pre[v] = u;
                cur[u] = id;
                aug[v] = min(aug[u], edge[id].v);
                u = v;
                break;
            }
        }
        if (flag == false)
        {
            if (--gap[dis[u]] == 0) break; /*gap优化层次树出现断层则结束算法*/
            mindis = n;
            cur[u] = box[u];
            for (id = box[u]; id != -1; id = edge[id].next)
            {
                v = edge[id].to;
                if (edge[id].v > 0 && dis[v] < mindis)
                {
                    mindis = dis[v];
                    cur[u] = id; //修改标号的同时修改当前弧
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if (u != s) u = pre[u]; //回溯继续寻找允许弧
        }
    }
    return max_flow;
}


void work()
{
    int res=inf;
    for(int i=1;i<N;i++)
    {
        memset(box,-1,sizeof(box));
        ent=0;
        for(int j=0;j<M;j++)
            add(bs[j].f,bs[j].t,bs[j].v);
        res=min(res,sap(0,i,N));
    }
    printf("%d\n",res);
}

void input()
{
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&bs[i].f,&bs[i].t,&bs[i].v);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
