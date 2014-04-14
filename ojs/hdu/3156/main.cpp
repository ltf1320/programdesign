#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=30+2;
const int maxm=1000+10;
const int maxhas=100000;
const int MOD=99997;
int N,M;
int pp;
double dp[maxhas];
int indu[maxhas];
int self[maxhas];
int next[maxn*maxn];
struct UniF
{
    int fa[maxn];
    void init()
    {
        for(int i=0;i<N;i++)
            fa[i]=i;
    }
    int find(int a)
    {
        if(a>=maxn)
        {
            a++;
            a--;
        }
        if(fa[a]==a)
            return a;
        fa[a]=find(fa[a]);
        return fa[a];
    }
    void Uni(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a<b)
            fa[b]=a;
        if(a>b)
            fa[a]=b;
    }
    int getHas()
    {
        int res=0;
        for(int i=0;i<N;i++)
            res+=find(i)*i;
        return res%MOD;
    }
    void print()
    {
        for(int i=0;i<N;i++)
            printf("%d ",fa[i]);
        puts("");
    }
    bool operator==(UniF &a)
    {
        for(int i=0;i<N;i++)
            if(a.find(i)!=find(i))
                return false;
        return true;
    }
};
UniF start;

struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxhas*maxn*maxn];
int box[maxhas];
int ent;

void add(int f,int t,int v)
{
    edge[ent].to=t;
    edge[ent].v=v;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct HasNode
{
    UniF uf;
    int next;
};

struct Has
{
    HasNode has[maxhas];
    int box[MOD];
    int end;
    int find(UniF &uf)
    {
        int h=uf.getHas();
        for(int i=box[h];i!=-1;i=has[i].next)
        {
            if(has[i].uf==uf)
                return i;
        }
        return -1;
    }
    int insert(UniF &uf)
    {
        int h=uf.getHas();
        has[end].uf=uf;
        has[end].next=box[h];
        box[h]=end;
        return end++;
    }
    void clear()
    {
        memset(box,-1,sizeof(box));
        end=0;
    }
}has,nhas;


queue<int> tque;

void topsort()
{
    for(int i=0;i<has.end;i++)
    {
        if(indu[i]==0)
        {
            tque.push(i);
        }
    }
    int now;
    double p;
    while(!tque.empty())
    {
        now=tque.front();
        tque.pop();
        has.has[now].uf.print();
        if(dp[now])
        {
            p=1.0*self[now]/pp;
            dp[now]=(dp[now]+p)/(1-p);
        }
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            dp[edge[i].to]+=(dp[now]+1)*edge[i].v/pp;
            indu[edge[i].to]--;
            if(indu[edge[i].to]==0)
                tque.push(edge[i].to);
        }
    }
}

queue<UniF> que;
void work()
{
    pp=N*(N-1)/2;
    has.insert(start);
    que.push(start);
    UniF now,nxt;
    int tt,nt;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        nhas.clear();
        nt=has.find(now);
        memset(next,0,sizeof(next));
        if(nt==-1)
            nt=has.insert(now);
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
            {
                if(i==j) continue;
                nxt=now;
                nxt.Uni(i,j);
                if(nxt==now)
                    self[nt]++;
                else
                {
                    tt=nhas.find(nxt);
                    if(tt==-1)
                        tt=nhas.insert(nxt);
                    next[tt]++;
                }
            }
   //     cout<<has.end<<endl;
        for(int i=0;i<nhas.end;i++)
        {
            tt=has.find(nhas.has[i].uf);
            if(tt==-1)
            {
                tt=has.insert(nhas.has[i].uf);
                que.push(nhas.has[i].uf);
            }
            add(tt,nt,next[i]);
            indu[nt]++;
        }
    }
    //topsort
    topsort();
    printf("%.6f\n",dp[0]);
    cout<<has.end<<endl;
}

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        f--;
        t--;
        start.Uni(f,t);
    }
}

void init()
{
    start.init();
    memset(box,-1,sizeof(box));
    ent=0;
    has.clear();
    memset(indu,0,sizeof(indu));
    memset(self,0,sizeof(self));
    memset(dp,0,sizeof(dp));
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
}
