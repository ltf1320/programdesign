#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
const int maxn=10000+100;
int N;
struct PD
{
    int f,t;
    bool v;
};
PD xd[maxn];
int pds[maxn];
int pdn;
set<int> pset;
map<int,int> mp;

struct Node
{
    int l,r;
    bool flag;
    bool v;
};
Node nds[4*maxn];

void buildTree(int l,int r,int n)
{
    nds[n].l=l;
    nds[n].r=r;
    nds[n].flag=0;
    if(l==r) return;
    int m=(l+r)>>1;
    buildTree(l,m,n<<1);
    buildTree(m+1,r,n<<1|1);
}

bool insert(bool v,int l,int r,int n)
{
    if(l==nds[n].l&&r=nds[n].r)
    {
        if(nds[n].flag)
        {
            if(nds[n].v!=v) return false;
        }
        else
        {
            nds[n].flag=1;
            nds[n].v=v;
        }
        return true;
    }
    int m=(nds[n].l+nds[n].r)>>1;
    if(r<=m)
        if(!insert(v,l,r,n<<1)) return false;
    if(l>m)
        if(!insert(v,l,r,n<<1|1)) return false;
    else
    {
        if(!insert(v,l,m,n<<1)) return false;
        if(!insert(v,m+1,r,n<<1|1)) return false;
    }
    if(nds[n<<1].flag&&nds[n<<1|1].flag)
    {
        if(nds[n].flag)
            if(nds[n].v!=nds[n<<1].v|nds[n<<1|1].v) return false
        else
        {
            nds[n].flag=true;
            nds[n].v=nds[n<<1].v|nds[n<<1|1].v;
        }
    }
}

int search(int l,int r,int n)
{
    if(l==nds[n].l&&r=nds[n].r)
    {
        if(nds[n].flag)
        {
            return nds[n].v;
        }
        return -1;
    }
    int m=(nds[n].l+nds[n].r)>>1;
    if(r<=m)
        return check(v,l,r,n<<1);
    if(l>m)
        return check(v,l,r,n<<1|1);
    else
    {
        int t1,t2;
        if((t1=check(v,l,m,n<<1))==-1) return -1;
        if((t2=check(v,m+1,r,n<<1|1))==-1) return -1;
        return t1|t2;
    }
}

void work()
{
    int t;
    for(int i=1;i<=N;i++)
    {
        t=search(mp[xd[i].f],mp[xd[i].t,1);
        if(t!=-1&&t!=xd[i].v)
            return i+1;
        insert(xd[i].v)
    }
}

void init()
{
    pdn=1;
    pset.clear();
}

void input()
{
    scanf("%d",&N);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        cin>>xd[i].f>>xd[i].t>>xd[i].v;
        pset.insert(xd[i].f);
        pset.insert(xd[i].t);
    }
    for(set<int>::iterator iter=pset.begin();iter!=pset.end();iter++)
    {
        pds[pdn]=*iter;
        mp[*iter]=pdn;
        pdn++;
    }
    buildTree(1,pdn-1,1);
}

int main()
{

    return 0;
}
