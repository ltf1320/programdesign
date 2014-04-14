#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxn=30000+10;
const int maxs=8000;
int N,Q,n;

struct Node
{
    Node(string n,Node *fad,int hh):h(hh),name(n),fa(fad){}
    Node():fa(NULL){}
    int h;
    string name;
    Node* fa;
    vector<Node*> son;
    void reset()
    {
        son.clear();  //Â©ÁËclear,RE
        for(size_t i=0;i<son.size();i++)
        {
            son[i]->reset();
            delete son[i];
        }
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
    Node *t;
    while(ct==h+1)
    {
        t=new Node(tmp,a,h+1);
        a->son.push_back(t);
        fnmap[tmp.substr(ct,tmp.size())]=t;
        tmp=build(a->son[a->son.size()-1],h+1);
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
    sort(a->son.begin(),a->son.end(),cmp);
    for(size_t i=0;i<a->son.size();i++)
        sortNode(a->son[i]);
}

void print(Node *a)
{
    cout<<a->name<<endl;
    for(size_t i=0;i<a->son.size();i++)
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
                        printf("%d\n",t->son.size());
                    }
                    break;
                case 'c':
                    cin>>tmp>>tmp2;
                    t=fnmap[tmp];
                    t=t->fa;
                    if(t==NULL) break;
                    t2=fnmap[tmp2];
                    t2=t2->fa;
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
