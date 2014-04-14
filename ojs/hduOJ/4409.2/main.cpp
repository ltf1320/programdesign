//RE:指针指错
//   指针范围不对（TreeNode)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=30000+10;
const int maxs=8000;
const int maxstr=60+1;
int N,Q,n;

struct Node
{
    Node(char* n,Node *fad,int hh):h(hh),ns(0),fa(fad){strcpy(name,n);}
    Node():ns(0),fa(NULL){}
    int h;
    char name[maxstr];
    int ns;
    Node* fa;
    Node* son[maxs];
    void reset()
    {
        for(int i=0;i<ns;i++)
        {
            son[i]->reset();
            delete son[i];
        }
        ns=0;
    }
};
Node Head;

struct TreeNode
{
    TreeNode *next[100];
    Node *p;
    TreeNode(){for(int i=0;i<100;i++) next[i]=NULL;p=NULL;}
    void reset()
    {
        for(int i=0;i<100;i++)
        {
            if(next[i]!=NULL) delete next[i];
            next[i]=NULL;
        }
    }
};
TreeNode TreeHead;

void insert(const char *s,Node *p)
{
    TreeNode *now=&TreeHead;
    int t;
    for(size_t i=0;i<strlen(s);i++)
    {
        if(s[i]<='9'&&s[i]>='0')
            t=s[i];
        else t=s[i]-'A'+10;
        if(now->next[t]==NULL) now->next[t]=new TreeNode();
        now=now->next[t];
    }
    now->p=p;
}

Node* find(const char *s)
{
    TreeNode *now=&TreeHead;
    int t;
    for(size_t i=0;i<strlen(s);i++)
    {
        if(s[i]<='9'&&s[i]>='0')
            t=s[i];
        else t=s[i]-'A'+10;
        if(now->next[t]==NULL) now->next[t]=new TreeNode();
        now=now->next[t];
    }
    return now->p;
}

int couts(const char* a)
{
    if(a==NULL) return -1;
    int res=0;
    for(size_t i=0;i<strlen(a);i++)
        if(a[i]=='.') res++;
        else break;
    return res;
}

char* build(Node *a,int h)
{
    char* tmp;
    tmp=new char[maxstr];
    if(n==N) return 0;
    cin>>tmp;
    n++;
    int ct=couts(tmp);
    while(ct==h+1)
    {
        a->son[a->ns]=new Node(tmp,a,h+1);
        insert(tmp+ct,a->son[a->ns]);
        delete [] tmp;
        tmp=build(a->son[a->ns],h+1);
        a->ns++;
        ct=couts(tmp);
    }
    return tmp;
}

bool cmp(Node *a,Node *b)
{
    return a->name<b->name;
}

void sortNode(Node *a)
{
    sort(a->son,a->son+a->ns,cmp);
    for(int i=0;i<a->ns;i++)
        sortNode(a->son[i]);
}

void print(Node *a)
{
    cout<<a->name<<endl;
    for(int i=0;i<a->ns;i++)
        print(a->son[i]);
}

void init()
{
    Head.reset();
    TreeHead.reset();
}

int main()
{
    freopen("in.txt","r",stdin);
    char cmd;
    char tmp[maxstr],tmp2[maxstr];
    Node *t,*t2;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        n=1;
        init();
        cin>>Head.name;
        insert(Head.name,&Head);
        build(&Head,0);
        sortNode(&Head);
        cin>>Q;
        while(Q--)
        {
            cin>>cmd;
            switch(cmd)
            {
                case 'L':print(&Head);break;
                case 'b':
                    cin>>tmp;
                    t=find(tmp);
                    if(t==NULL) break;
                    if(t->fa==NULL)
                        printf("%d\n",0);
                    else
                    {
                        t=t->fa;
                        printf("%d\n",t->ns);
                    }
                    break;
                case 'c':
                    cin>>tmp>>tmp2;
                    t=find(tmp);
                    if(t==NULL) break;
                    t2=find(tmp2);
                    if(t2==NULL) break;
                    while(t->h>t2->h)
                    {
                        t=t->fa;
                    }
                    while(t2->h>t->h)
                    {
                        t2=t2->fa;
                    }
                    while(true)
                    {
                        if(t==t2)
                            break;
                        t=t->fa;
                        t2=t2->fa;
                    }
                    if(t==NULL) break;
                    for(size_t i=t->h;i<strlen(t->name);i++)
                            cout<<t->name[i];
                        cout<<endl;
                    break;
            }
        }
    }
    return 0;
}
