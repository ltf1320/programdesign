#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int inf=0x3f3f3f3f;
int N;

int mabs(int a)
{
    return a>0?a:-a;
}

struct Node
{
    Node* parent;
    Node *left,*right;
    Node():parent(0),left(0),right(0){}
    Node(Node* p):parent(p),left(0),right(0){}
    int id,g;
    void reset()
    {
        if(left) {left->reset();delete left;left=0;}
        if(right) {right->reset();delete right;right=0;}
    }
};

Node root;

Node* insert(int id,int g)
{
    Node* now=&root;
    while(true)
    {
        if(g<now->g)
        {
            if(now->left)
            {
                now=now->left;
            }
            else
            {
                now->left=new Node(now);
                now->left->g=g;
                now->left->id=id;
                return now->left;
            }
        }
        else
        {
            if(now->right)
            {
                now=now->right;
            }
            else
            {
                now->right=new Node(now);
                now->right->g=g;
                now->right->id=id;
                return now->right;
            }
        }
    }
    return 0;
}

Node* findPre(Node* p)
{
    Node* parent=p->parent;
    Node* tt;
    if(parent->left==p)
    {
        while(true)
        {
            tt=parent->parent;
            if(!tt) return 0;
            if(tt->right==parent)
            {
                return tt;
            }
            parent=tt;
        }
    }
    else return parent;
}

Node* findNxt(Node *p)
{
    Node* parent=p->parent;
    Node* tt;
    if(parent->right==p)
    {
        while(true)
        {
            tt=parent->parent;
            if(!tt) return 0;
            if(tt->left==parent)
            {
                return tt;
            }
            parent=tt;
        }
    }
    else return parent;
}

int main()
{
    freopen("in.txt","r",stdin);
    root.id=1;
    root.g=1000000000;
    int now,ng;
    Node* p,*pre,*nxt;
    int rn,rg;
    while(~scanf("%d",&N)&&N)
    {
        root.reset();
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&now,&ng);
            p=insert(now,ng);
            pre=findPre(p);
            nxt=findNxt(p);
            rg=inf;
            if(pre)
            {
                if(mabs(pre->g-p->g)<rg)
                {
                    rn=pre->id;
                    rg=mabs(pre->g-p->g);
                }
            }
            if(nxt)
            {
                if(mabs(nxt->g-p->g)<rg)
                {
                    rn=nxt->id;
                    rg=mabs(nxt->g-p->g);
                }
            }
            printf("%d %d\n",now,rn);
        }
    }
    return 0;
}
