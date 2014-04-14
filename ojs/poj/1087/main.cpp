#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+10;
const int maxp=80;
const int inf=0x3f3f3f3f;
int N,M,K;
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

int getp(char a)
{
    if(a>='a'&&a<='z')
        return a-'a';
    else if(a>='A'&&a<='Z')
        return a-'A'+26;
    else return a-'0'+60;
}
int tn;
struct Tree
{
    Tree *next[maxp];
    int c;
    void reset()
    {
        tn=2;
        for(int i=0;i<maxp;i++)
            if(next[i])
            {
                next[i]->reset();
                next[i]=0;
            }
        c=-1;
    }
    Tree(){memset(next,0,sizeof(next));c=-1;}
    int insert(char * str)
    {
        Tree *p=this;
        while(*str)
        {
            if(!p->next[getp(*str)])
                p->next[getp(*str)]=new Tree();
            p=p->next[getp(*str)];
            str++;
        }
        p->c=tn;
        return tn++;
    }
    int find(char *str)
    {
        Tree *p=this;
        while(*str)
        {
            if(!p->next[getp(*str)])
                return -1;
            p=p->next[getp(*str)];
            str++;
        }
        return p->c;
    }
};
Tree rectree;

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

int makeflow(int s,int t,int maxc,int from)
{
    if(s==t) return maxc;
    int rec=0,flow;
    for(int i=box[s];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        if(!edge[i].v)continue;
        if(level[edge[i].to]<=level[s]) continue;
        flow=makeflow(edge[i].to,t,min(edge[i].v,maxc-rec),s);
        edge[i].v-=flow;
        edge[i^1].v+=flow;
        rec+=flow;
        if(rec==maxc) return maxc;
    }
    return rec;
}

int dinic(int s,int t)
{
    int res=0;
    while(makelevel(s,t))
        res+=makeflow(s,t,inf,-1);
    return res;
}


void input()
{
    memset(box,-1,sizeof(box));
    ent=0;
    tn=2;
    char t1[maxp],t2[maxp];
    int c1,c2;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",t1);
        c1=rectree.find(t1);
        if(c1==-1)
            c1=rectree.insert(t1);
        add(0,c1,1);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%s%s",t1,t2);
        c1=rectree.find(t2);
        if(c1==-1)
            c1=rectree.insert(t2);
        add(tn,1,1);
        add(c1,tn,1);
        tn++;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%s%s",t1,t2);
        c1=rectree.find(t1);
        c2=rectree.find(t2);
        if(c1==-1)
            c1=rectree.insert(t1);
        if(c2==-1)
            c2=rectree.insert(t2);
        _add(c1,c2,inf);
        _add(c2,c1,inf);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    input();
    printf("%d\n",M-dinic(0,1));
    return 0;
}
