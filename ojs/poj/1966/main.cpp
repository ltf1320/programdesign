#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=200;
const int maxm=50*50*100+1000;
const int inf=0x3f3f3f3f;
int N,M;


struct Bian
{
    int f,t;
};
Bian bs[maxm];

struct EDGE
{
    int to,next,v;
};
EDGE edge[maxm];
int box[maxn];
int ent;

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
    _add(t,f,0);
}

int level[maxn];
bool makelevel(int s,int t)
{
    memset(level,0,sizeof(level));
    level[s]=1;
    queue<int> que;
    que.push(s);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(edge[i].v==0) continue;
            if(level[edge[i].to]) continue;
            level[edge[i].to]=level[now]+1;
            que.push(edge[i].to);
            if(edge[i].to==t) return 1;
        }
    }
    return false;
}
int que[maxn*10];
int dinic(int s,int t)
{
    int ans = 0;
    while(makelevel(s,t))
    {
        int now, x, y, back, iter = 1;
        while(iter)
        {
            x = (iter == 1) ? s : edge[que[iter - 1]].to;
            if (x == t)
            {
                int minCap = inf;
                for (int i = 1; i < iter; i++)
                {
                    now = que[i];
                    if (edge[now].v < minCap)
                    {
                        minCap = edge[now].v;
                        back = i;
                    }
                }
                for (int i = 1; i < iter; i++)
                {
                    now = que[i];
                    edge[now].v -= minCap;
                    edge[now ^ 1].v += minCap;
                }
                ans += minCap;
                iter = back;
            }
            else
            {
                for (now = box[x]; now + 1; now = edge[now].next)
                {
                    y = edge[now].to;
                    if (edge[now].v && level[y] >= level[x] + 1)
                        break;
                }
                if (now+1)
                    que[iter++] = now;
                else
                {
                    level[x] = -1;
                    iter--;
                }
            }
        }
    }
    return ans;
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
    for (int i = 0; i <= n; ++i) //初始化当前弧为第一条弧
    {
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
        {
            // 从当前弧开始查找允许弧
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
    /*
    if(N==0)
    {
        puts("0");
        return;
    }
    */
    int res=inf;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i!=j)
            {
                memset(box,-1,sizeof(box));
                ent=0;
                for(int k=0; k<N; k++)
                {
                    add(k*2,k*2+1,1);
                    add(k*2+1,k*2,1);
                }
                for(int k=0; k<M; k++)
                {
                    add(bs[k].f*2+1,bs[k].t*2,inf);
                    add(bs[k].t*2+1,bs[k].f*2,inf);
                }
                             res=min(res,dinic(i*2+1,j*2));
   //             res=min(res,sap(i*2+1,j*2,N*2));
            }
    if(res>=inf)
        res=N;
    printf("%d\n",res);
}



void input()
{
    for(int i=0; i<M; i++)
    {
        while(getchar()==' ');
        scanf("%d",&bs[i].f);
        while(getchar()==' ');
        scanf("%d",&bs[i].t);
        while(getchar()!=')');
        //      map[bs[i].f][bs[i].t]=map[bs[i].t][bs[i].f]=1;
    }
}

void init()
{
    //  memset(map,0,sizeof(map));
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
