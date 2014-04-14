#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=30000+10;
const int maxs=8000;
int N,Q,n;

struct Node
{
    Node(string n,Node *fad,int hh):h(hh),name(n),ns(0),fa(fad){}
    Node():ns(0),fa(NULL){}
    int h;
    string name;
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

map<string,Node*> fnmap;

int couts(const string &a)
{
    int res=0;
    for(size_t i=0;i<a.size();i++)
        if(a[i]=='.') res++;
        else break;
    return res;
}

string build(Node *a,int h)
{
    string tmp;
    if(n==N) return string("");
    cin>>tmp;
    n++;
    int ct=couts(tmp);
    while(ct==h+1)
    {
        a->son[a->ns]=new Node(tmp,a,h+1);
        fnmap[tmp.substr(ct,tmp.size())]=a->son[a->ns];
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
    fnmap.clear();
    Head.reset();
}

int main()
{
    freopen("in.txt","r",stdin);
    char cmd;
    string tmp,tmp2;
    Node *t,*t2;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        n=1;
        init();
        cin>>Head.name;
        fnmap[Head.name]=&Head;
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
                    t=fnmap[tmp];
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
                    t=fnmap[tmp];
                    if(t==NULL) break;
                    t2=fnmap[tmp2];
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
                        if(t->name==t2->name)
                            break;
                        t=t->fa;
                        t2=t2->fa;
                    }for(size_t i=t->h;i<t->name.size();i++)
                            cout<<t->name[i];
                        cout<<endl;
                    break;
            }
        }
    }
    return 0;
}
