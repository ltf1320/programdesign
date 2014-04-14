#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100+10;
int N,L;
int mp(char c)
{
    switch(c)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'T':
        return 2;
    case 'C':
        return 3;
    }
    return -1;
}

struct Node
{
    Node *fail;
    Node *next[4];
    int count;
    Node()
    {
        fail=NULL;
        for(int i=0; i<4; i++)
            next[i]=0;
        count=0;
    }
    void reset()
    {
        fail=NULL;
        for(int i=0; i<4; i++)
        {
            if(next[i]!=NULL)
            {
                delete next[i];
                next[i]=NULL;
            }
        }
        count=0;
    }
    Node* copy(Node *p,Node *s)
    {
        fail=p->fail;
        count=p->count;
        Node *r=NULL;
        for(int i=0; i<4; i++)
        {
            if(p->next[i]!=NULL)
            {
                next[i]=new Node();
                if(r==NULL)
                    r=next[i]->copy(p->next[i],s);
                else next[i]->copy(p->next[i],s);
            }
        }
        if(p==s)
            return this;
        else return r;
    }
};
Node Tree;
Node Root[5];

struct DP
{
    Node *p;
    int w;
};
DP dp[maxn][5];

DP match(const DP &from,int a)
{
    DP res;
    Node *now=from.p;
    res.w=from.w;
    Node *tmp;
    while(now->next[a]==NULL&&now->fail!=NULL)
        now=now->fail;
    if(now->next[a]!=NULL)
    {
        now=now->next[a];
        tmp=now;
        while(tmp->count!=-1&&tmp->fail!=NULL)
        {
            res.w+=tmp->count;
//            tmp->count=-1;
            tmp=tmp->fail;
        }
    }
    res.p=now;
    return res;
}

void update(Node *now,int a)
{
    Node *tmp;
    while(now->next[a]==NULL&&now->fail!=NULL)
        now=now->fail;
    if(now->next[a]!=NULL)
    {
        now=now->next[a];
        tmp=now;
        while(tmp->count!=-1&&tmp->fail!=NULL)
        {
            tmp->count=-1;
            tmp=tmp->fail;
        }
    }
}

int work()
{
    DP tmp[5];
    int maxk,maxw;
    Node *t;
    for(int i=0; i<4; i++)
    {
        Root[i].copy(&Tree,&Tree);
        if(Root[i].next[i]!=NULL)
        {
            dp[0][i].p=Root[i].next[i];
            dp[0][i].w=Root[i].next[i]->count;
            Root[i].next[i]->count=-1;
        }
        else
        {
            dp[0][i].p=&Root[i];
            dp[0][i].w=0;
        }
    }
    for(int i=1; i<L; i++)
    {
        for(int j=0; j<4; j++)
        {
            maxw=-inf;
            for(int k=0; k<4; k++)
            {
                tmp[k]=match(dp[i-1][k],j);
                if(tmp[k].w>maxw)
                {
                    maxw=tmp[k].w;
                    maxk=k;
                }
            }
            if(maxk==j)
            {
                update(dp[i-1][maxk].p,maxk);
            }
            else
            {
                t=Root[j].copy(&Root[maxk],dp[i-1][maxk].p);
                update(t,maxk);
                tmp[maxk].p=t;
            }
            dp[i][j]=tmp[maxk];
        }
    }
    int res=-inf;
    for(int i=0; i<4; i++)
    {
        if(dp[L-1][i].w>res)
            res=dp[L-1][i].w;
    }
    return res;
}

void insert(const char *s,int n)
{
    int len=strlen(s);
    Node *now=&Tree;
    for(int i=0; i<len; i++)
    {
        if(now->next[mp(s[i])]==NULL)
            now->next[mp(s[i])]=new Node();
        now=now->next[mp(s[i])];
    }
    now->count+=n;
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
        for(int i=0; i<4; i++)
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



int main()
{
    freopen("in.txt","r",stdin);
    char tmp[100+10];
    int n,res;
    while(~scanf("%d%d",&N,&L))
    {
        Tree.reset();
        for(int i=0; i<N; i++)
        {
            scanf("%s%d",tmp,&n);
            insert(tmp,n);
        }
        res=work();
        if(res>=0)  printf("%d\n",res);
        else printf("No Rabbit after 2012!\n");
    }
    return 0;
}
