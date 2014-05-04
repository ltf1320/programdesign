#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef unsigned long long LL;

const int maxn=150+10;
const LL hasMod=((LL)1<<32)-2;
const int inf=20000;

struct Node
{
    Node *l,*r;
    LL h;
    int num;
    Node(){l=0;r=0;num=0;h=0;}
    void calHash()
    {
        LL lh=0,rh=0;
        if(l)
        {
            l->calHash();
            lh=l->h;
        }
        if(r)
        {
            r->calHash();
            rh=r->h;
        }
        h=(lh*rh+num)%hasMod;
    }
};
Node root[2];

void insert(char *s,int k)
{
    Node *now=&root[k];
    while(s)
    {
        now->num++;
        switch(s[0])
        {
            case '0':
                if(!now->l)
                    now->l=new Node();
                now=now->l;
                break;
            case '1':
                if(!now->r)
                    now->r=new Node();
                now=now->r;
                break;
        }
        s++;
    }
}

vector<Node*> ands[2],bnds[2];

void work()
{
    ands[0].push_back(&root[0]);
    bnds[0].push_back(&root[1]);
    for(int k=0;;k^=1)
    {
        if(ands[k].size()==0)
            break;
    }
}

int dfs(vector<Node*> a,vector<Node*> b)
{
    if(a.size()!=b.size())
        return inf;
    vector<Node*> na,nb;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]->l)
        {
            if(b[i]->l)
                if(a[i]->l->h==b[i]->l->h)
            {

            }
        }
    }

}

int main()
{

    return 0;
}
