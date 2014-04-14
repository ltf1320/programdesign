#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=0x3d3f3f3f;
const int maxn=100+10;
int N,L;

struct Gene
{
    char str[maxn];
    int w,kw,code,state,len;
    bool operator<(const Gene &a)const
    {
        return kw<a.kw;
    }
};
Gene genes[20];
int gn;

int mp(char a)
{
    switch(a)
    {
        case 'A':return 0;
        case 'G':return 1;
        case 'T':return 2;
        case 'C':return 3;
    }
    return -1;
}

struct Node
{
    Node *fail;
    Node *next[4];
    int count,code;
    Node()
    {
        fail=NULL;
        for(int i=0;i<4;i++)
            next[i]=0;
        count=0;
        code=0;
    }
    void reset()
    {
        fail=NULL;
        for(int i=0;i<4;i++)
        {
            if(next[i]!=NULL)
            {
                delete next[i];
                next[i]=NULL;
            }
        }
        count=0;
    }
    void copy(Node *p)
    {
        fail=p->fail;
        count=p->count;
        for(int i=0; i<4; i++)
        {
            if(p->next[i]!=NULL)
            {
                next[i]=new Node();
                next[i]->copy(p->next[i]);
            }
        }
    }
};
Node Tree;

void insert(const char *s,int n)
{
    strcpy(genes[gn].str,s);
    genes[gn].w=n;
    genes[gn].code=gn;
    genes[gn].len=strlen(s);
    int len=strlen(s);
    Node *now=&Tree;
    for(int i=0;i<len;i++)
    {
        if(now->next[mp(s[i])]==NULL)
            now->next[mp(s[i])]=new Node();
        now=now->next[mp(s[i])];
    }
    now->count+=n;
    now->code=gn;
    gn++;
}

void BuildAC()
{
    Node *now,*p;
    Tree.fail=NULL;
    queue<Node*> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            if(now->next[i]!=NULL)
            {
                que.push(now->next[i]);
                if(now==&Tree)
                    now->next[i]->fail=&Tree;
                else
                {
                    p=now->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            now->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                        now->next[i]->fail=&Tree;
                }
            }
        }
    }
}


int match(const char *str,int *state=new int)
{
    Node nTree;
    nTree.copy(&Tree);
    Node *p=&nTree;
    Node *tmp;
    state=0;
    int res=0;
    int i=0;
    while(str[i])
    {
        while(p!=&nTree&&p->next[mp(str[i])]==NULL)
            p=p->fail;
        if(p->next[mp(str[i])]!=NULL)
        {
            p=p->next[mp(str[i])];
            tmp=p;
            while(tmp->count!=-1&&tmp->fail!=NULL)
            {
                res+=tmp->count;
                *state|=1<<tmp->code;
                tmp->count=-1;
                tmp=tmp->fail;
            }
        }
    }
    return res;
}
priority_queue<Gene> que;
int search(string now,int state)
{
    if(now.size()==L||state==(1<<L)-1) return match(now.c_str());
    Gene ng;
    bool next=1;
    int res=-inf,t;
    while(!que.empty())
    {
        ng=que.top();
        if(state&ng.code==1||now.size()+ng.len>L)
        {
            que.pop();
            continue;
        }
        if(ng.kw>0) next=0;
        que.pop();
        t=search(now+string(ng.str),state|ng.state);
        if(t>res) res=t;
    }
    if(next)
    {
        for(int i=0;i<N;i++)
        {
            if((state&(1<<genes[i].code))==0&&now.size()+genes[i].len<=L)
            {
                t=search(now+string(genes[i].str),state|genes[i].state);
                if(t>res) res=t;
                if(genes[i].w>=0&&genes[i].kw>=0) next=0;
            }
        }
        if(next)
        {

        }
    }
}


int work()
{
    for(int i=0;i<N;i++)
    {
        genes[i].kw=match(genes[i].str,&genes[i].state);
        que.push(genes[i]);
    }

}

int main()
{
    char tmp[100+10];
    int n;
    while(~scanf("%d%d",&N,&L))
    {
        Tree.reset();
        gn=0;
        for(int i=0;i<N;i++)
        {
            scanf("%s%d",tmp,&n);
            insert(tmp,n);
        }
        BuildAC();


    }
    return 0;
}
