#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int maxn=100+10;
int N,L;

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
    int count;
    Node()
    {
        fail=NULL;
        for(int i=0;i<4;i++)
            next[i]=0;
        count=0;
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
};
Node Tree;

void insert(const char *s,int n)
{
    int len=strlen(s);
    Node *now=&Tree;
    for(int i=0;i<len;i++)
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



int main()
{
    char tmp[100+10];
    int n;
    while(~scanf("%d%d",&N,&L))
    {
        Tree.reset();
        for(int i=0;i<N;i++)
        {
            scanf("%s%d",tmp,&n);
            insert(tmp,n);
        }
    }
    return 0;
}
