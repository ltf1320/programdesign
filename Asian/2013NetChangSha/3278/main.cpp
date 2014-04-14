#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1000000+100;
bool vis[maxn];
int N,K;
struct Node
{
    int num,step;
    int h;
    Node() {}
    Node(int n,int st):num(n),step(st)
    {
        h=geth();
    }
    bool operator<(const Node &a) const
    {
        return h+step<a.h+a.step;
    }
    int geth()
    {
        int now=num;
        int res=0;
        if(now==0)
        {
            now=1;
            res++;
        }
        if(now>K) return now-K;
        else
        {
            while(now<K)
            {
                now*=2;
                res++;
            }
        }
        return res;
    }
};


priority_queue<Node> que;

int bfs()
{
    que.push(Node(N,0));
    vis[N]=1;
    Node now;
    while(!que.empty())
    {
        now=que.top();
        que.pop();
        if(now.num==K) return now.step;
        if(!vis[now.num+1])
        {
            vis[now.num+1]=1;
            que.push(Node(now.num+1,now.step+1));
        }
        if(now.num<2*K&&!vis[now.num*2])
        {
            vis[now.num*2]=1;
            que.push(Node(now.num*2,now.step+1));
        }
        if(now.num>0&&!vis[now.num-1])
        {
            vis[now.num-1]=1;
            que.push(Node(now.num-1,now.step+1));
        }
    }
    return -1;
}


int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    printf("%d\n",bfs());
    return 0;
}
