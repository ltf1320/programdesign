#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
const int inf=0x3f3f3f3f;
int pre[maxm];
int N,M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[2*maxn*maxm];
int box[maxn+maxm];
int ent;
void _add(int from,int to,int v)
{
    edge[ent].to=to;
    edge[ent].v=v;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void add(int from,int to,int v)
{
    _add(from,to,v);
    _add(to,from,0);
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

int tn;
void input()
{
    int t,k;
    tn=2;
    for(int i=0; i<M; i++)
    {
        scanf("%d",&t);
        add(0,tn++,t);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d",&t);
        for(int j=0; j<t; j++)
        {
            scanf("%d",&k);
            if(pre[k]!=-1)
                add(pre[k],tn,inf);
            pre[k]=tn;
            add(k+1,tn,inf);
        }
        scanf("%d",&k);
        add(tn,1,k);
        tn++;
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(pre,-1,sizeof(pre));
}

int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&M,&N))
    {
        init();
        input();
        printf("%d\n",sap(0,1,tn));
    }
    return 0;
}
