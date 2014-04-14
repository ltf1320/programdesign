#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
using namespace std;
const int maxn=1000+10;
const int maxp=80;
const int inf=0x3f3f3f3f;
int N,M,K;
map<string,int> mp;
struct EDGE
{
    int next,to,v;
};
EDGE edge[10*maxn];
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

int tn;
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

int makeflow(int s,int t,int maxc)
{
    if(s==t) return maxc;
    int rec=0,flow;
    for(int i=box[s]; i!=-1; i=edge[i].next)
    {
        if(!edge[i].v)continue;
        if(level[edge[i].to]<=level[s]) continue;
        flow=makeflow(edge[i].to,t,min(edge[i].v,maxc-rec));
        edge[i].v-=flow;
        edge[i^1].v+=flow;
        rec+=flow;
        if(rec==maxc) return maxc;
    }
    return rec;
}
int que[maxn+maxm];
int dinic(int s,int t)
{
    int ans = 0;
    while(getlevel(s,t))
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


void input()
{
    memset(box,-1,sizeof(box));
    ent=0;
    tn=2;
    string t1,t2;
    map<string,int>::iterator c1,c2;
    int k1,k2;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        cin>>t1;
        c1=mp.find(t1);
        if(c1==mp.end())
        {
            mp.insert(make_pair(t1,tn));
            k1=tn++;
        }
        else k1=c1->second;
        add(0,k1,1);
    }
    scanf("%d",&M);
    for(int i=0; i<M; i++)
    {
        cin>>t1>>t2;
        c1=mp.find(t2);
        if(c1==mp.end())
        {
            k1=tn;
            mp.insert(make_pair(t2,tn++));
        }
        else k1=c1->second;
        add(tn,1,1);
        add(k1,tn,1);
        tn++;
    }
    scanf("%d",&K);
    for(int i=0; i<K; i++)
    {
        cin>>t1>>t2;
        c1=mp.find(t1);
        c2=mp.find(t2);
        if(c1==mp.end())
        {
            k1=tn;
            mp.insert(make_pair(t1,tn++));
        }
        else k1=c1->second;
        if(c2==mp.end())
        {
            k2=tn;
            mp.insert(make_pair(t2,tn++));
        }
        else k2=c2->second;
//        _add(k1,k2,inf);
//        _add(k2,k1,inf);
        add(k2,k1,inf);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    input();
    printf("%d\n",M-dinic(0,1));
    return 0;
}
