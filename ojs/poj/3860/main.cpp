//隐藏数太大，用log来处理
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=200+10;
const double inf=1E20;
const double err=1E-8;
int N;
int frn;
int fromn,ton;

char fstr[maxn],tstr[maxn];


bool comp(double d,double a)
{
    if(a<=d+err&&a>=d-err) return true;
    else return false;
}

int getFh(double a)
{
    if(a>=err) return 1;
    if(a<=-err) return -1;
    return 0;
}

int getN(char a)
{
    if(a>='a'&&a<='z')
        return a-'a';
    else return a-'A'+26;
}

struct Trie
{
    Trie* next[60];
    int n;
    Trie():n(-1){memset(next,0,sizeof(next));}
    void reset()
    {
        for(int i=0;i<60;i++)
        {
            if(next[i])
            {
                next[i]->reset();
                delete next[i];
                next[i]=0;
            }
        }
        n=-1;
    }
};
Trie Tree;

int insert(char *s)
{
    Trie *now=&Tree;
    int nxt;
    while(*s)
    {
        nxt=getN(*s);
        if(!now->next[nxt])
            now->next[nxt]=new Trie();
        now=now->next[nxt];
        s++;
    }
    if(now->n==-1)
        now->n=frn++;
    return now->n;
}

int find(char *s)
{
    Trie *now=&Tree;
    int nxt;
    while(*s)
    {
        nxt=getN(*s);
        if(!now->next[nxt])
            return -1;
        now=now->next[nxt];
        s++;
    }
    return now->n;
}

struct EDGE
{
    int to,next;
    double r;
};
EDGE edge[maxn];
int box[maxn];
int ent;

void add(int f,int t,double r)
{
    edge[ent].to=t;
    edge[ent].r=r;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int in[maxn];
double dis[maxn];
int cnt[maxn];
queue<int> que;
double spfa(int from,int to)
{
    int now;
    for(int i=0;i<frn;i++)
        dis[i]=inf;
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    que.push(from);
    dis[from]=log(1.0);
    in[from]=1;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now];i!=-1;i=edge[i].next)
        {
            if(getFh(dis[edge[i].to]-(dis[now]+edge[i].r))>0)
            {
                dis[edge[i].to]=dis[now]+edge[i].r;
                if(!in[edge[i].to])
                {
                    que.push(edge[i].to);
                    in[edge[i].to]=1;
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to]>frn)
                    {
                        while(!que.empty())que.pop();
                        return inf;
                    }
                }
            }
        }
        in[now]=0;
    }
   return dis[to];
}

int bellmanZH(int from,int to)
{
    for(int i=0;i<frn;i++)
        dis[i]=-inf;
    dis[from]=log(1.0);
    bool flag;
    for(int i=0;i<frn;i++)
    {
        flag=0;
        for(int n=0;n<frn;n++)
        {
            for(int j=box[n];j!=-1;j=edge[j].next)
            {
                if(dis[n]+edge[n].r>dis[edge[j].to])
                {
                    flag=1;
                    dis[edge[j].to]=dis[n]+edge[n].r;
                    if(i==frn-1) return -1;
                }
            }
        }
        if(!flag) break;
    }
    return 0;
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    Tree.reset();
    frn=0;
}

void input()
{
    int f,t;
    for(int i=0;i<N;i++)
    {
        scanf("%d%s%d%s",&fromn,fstr,&ton,tstr);
        f=insert(fstr);
        t=insert(tstr);
        add(f,t,log((double)ton/fromn));
    }
    scanf("%d%s%d%s",&fromn,fstr,&ton,tstr);
}


void work()
{
    double cp1,cp2,ans;
    int f=find(fstr),t=find(tstr);
    cp1=spfa(f,t);
    cp2=spfa(t,f);
    ans=log((double)ton/fromn);
    if(comp(cp1,inf)&&comp(cp2,inf))
        printf("INCONSISTENT\n");
    else if(comp(cp1,ans)&&comp(cp2,-ans))
        printf("==\n");
    else if(getFh(cp1-ans)<=0)
        printf("<=\n");
    else if(getFh(cp2+ans)<=0)
        printf(">=\n");
    else printf("UNAVAILABLE\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        init();
        input();
        work();
    }
    return 0;
}
