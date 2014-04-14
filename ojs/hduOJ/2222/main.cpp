#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000000+100;

char str[maxn];

struct Node
{
    Node *fail;
    Node *next[30];
    int end;
    Node()
    {
        fail=NULL;
        for(int i=0; i<26; i++)
            next[i]=NULL;
        end=0;
    }
    void reset()
    {
        fail=NULL;
        for(int i=0; i<26; i++)
            if(next[i]!=NULL)
            {
                next[i]->reset();
                delete next[i];
                next[i]=NULL;
            }
        end=0;
    }
};
Node Tree;
queue<Node*> que;

void insert(const char *s)
{
    int len=strlen(s);
    Node *now=&Tree;
    for(int i=0; i<len; i++)
    {
        if(now->next[s[i]-'a']==NULL)
            now->next[s[i]-'a']=new Node();
        now=now->next[s[i]-'a'];
    }
    now->end++;
}

void BuildFail()
{
    while(!que.empty()) que.pop();
    que.push(&Tree);
    Node *now;
    Node *p;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0; i<26; i++)
        {
            if(now->next[i]!=NULL)
            {
                que.push(now->next[i]);
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
                if(p==NULL) now->next[i]->fail=&Tree;//ÌØ±ð×¢Òâ
            }
        }
    }
}

int match()
{
    int len=strlen(str);
    int res=0;
    Node *now=&Tree;
    Node *tmp;
    for(int i=0; i<len; i++)
    {
        while(now->next[str[i]-'a']==NULL&&now->fail!=NULL)
            now=now->fail;
        if(now->next[str[i]-'a']!=NULL)
        {
            now=now->next[str[i]-'a'];
            tmp=now;
            while(tmp->end!=-1&&tmp->fail!=NULL)
            {
                res+=tmp->end;
                tmp->end=-1;
                tmp=tmp->fail;
            }
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T,N;
    char tmp[100];
    scanf("%d",&T);
    while(T--)
    {
        Tree.reset();
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%s",tmp);
            insert(tmp);
        }
        BuildFail();
        scanf("%s",str);
        printf("%d\n",match());
    }
    return 0;
}
