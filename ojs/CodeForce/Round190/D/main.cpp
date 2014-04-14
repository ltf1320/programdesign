#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int nMax=230;
int N,M;
struct{
    int v, cap, cost, next, re;    //  re记录逆边的下标。
}edge[eMax];
int n, m, ans;
int k, edgeHead[nMax];
int que[nMax], pre[nMax], dis[nMax];
bool vis[nMax];

void addEdge(int u, int v, int ca, int co){
    edge[k].v = v;
    edge[k].cap = ca;
    edge[k].cost = co;
    edge[k].next = edgeHead[u];
    edge[k].re = k + 1;
    edgeHead[u] = k ++;
    edge[k].v = u;
    edge[k].cap = 0;
    edge[k].cost = -co;
    edge[k].next = edgeHead[v];
    edge[k].re = k - 1;
    edgeHead[v] = k ++;
}

bool spfa(){                  //  源点为0，汇点为n。
    int i, head = 0, tail = 1;
    for(i = 0; i <= n; i ++){
        dis[i] = -inf;
        vis[i] = false;
    }
    dis[0] = 0;
    que[0] = 0;
    vis[u] = true;
    while(tail > head){       //  这里最好用队列，有广搜的意思，堆栈像深搜。
        int u = que[head ++];
        for(i = edgeHead[u]; i != 0; i = edge[i].next){
            int v = edge[i].v;
            if(edge[i].cap && dis[v] < dis[u] + edge[i].cost){
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v]){
                    vis[v] = true;
                    que[tail ++] = v;
                }
            }
        }
        vis[u] = false;
    }
    if(dis[n] == inf) return false;
    return true;
}

void end(){
    int u, p, sum = inf;
    for(u = n; u != 0; u = edge[edge[p].re].v){
        p = pre[u];
        sum = min(sum, edge[p].cap);
    }
    for(u = n; u != 0; u = edge[edge[p].re].v){
        p = pre[u];
        edge[p].cap -= sum;
        edge[edge[p].re].cap += sum;
        ans += sum;     //  cost记录的为单位流量费用，必须得乘以流量。
    }
}

struct JJ
{
    int stren;
    bool state;
    bool operator<(const JJ& a)const
    {
        return stren<a.stren;
    }
};
JJ JS[nMax];
void input()
{
    k=1;
    memset(edgeHead,0,sizeof(edgeHead));
    char tmp[10];
    int st;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        add(0,i+1,1,0);
        scanf("%s%d",tmp,&JS[i].stren);
        if(tmp[0]=='A')
            JS[i].state=1;
        else JS[i].state=0;
    }
    sort(JS,JS+N);
    for(int i=0;i<M;i++)
    {
        scanf("%d",&st);
        for(int j=0;j<N;j++)
        {
            addEdge(i+N+1,N+M+1,1,0);
            if(st<JS[j].stren) break;
            if(JS[j].state)
                addEdge(j+1,i+N+1,1,JS[j].stren-st);
            else addEdge(j+1,i+N+1,1,0);
        }
    }
}

int main(){
    input();
    ans = 0;
    while(spfa()) end();

    return 0;
}

