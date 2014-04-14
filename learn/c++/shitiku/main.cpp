#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int N,K;
int M;
struct EDGE
{
    int next,to,v;
};
EDGE edge[maxn*maxn];
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
        for(int i=box[now];i!=-1;i=edge[i].next)
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

//S:0,T':1,T:2,leixing:3...2+K,timu:3+k...
void input()
{
    int tt,st;
    scanf("%d%d",&K,&N);
    M=0;
    for(int i=0;i<K;i++)
    {
        scanf("%d",&tt);
        add(0,i+3,tt);
        M+=tt;
    }
    for(int i=0;i<N;i++)
    {
        add(i+K+3,1,1);
        scanf("%d",&tt);
        for(int j=0;j<tt;j++)
        {
            scanf("%d",&st);
            add(st+2,i+3+K,1);
        }
    }
    add(1,2,M);
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    input();
    int ans=dinic(0,2);
    if(ans!=M)
        printf("NoSolution!\n");
    else
    {
        for(int i=3;i<3+K;i++)
        {
            printf("%d:",i-2);
            for(int j=box[i];j!=-1;j=edge[j].next)
            {
                if(edge[j].v==0)
                {
                    printf(" %d",edge[j].to-K-2);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
