#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
const int inf=1E9;
struct Tree
{
    int l,r;
    int mx;
    bool flag;
};
Tree tree[4*maxn];

void buildTree(int n,int l,int r)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].mx=inf;
    tree[n].flag=1;
    if(l==r) return;
    int m=(l+r)>>1;
    buildTree(n<<1,l,m);
    buildTree(n<<1|1,m+1,r);
}

void add(int n,int l,int r,int d)
{
    if(tree[n].flag&&tree[n].l==l&&r==tree[n].r)
    {
        tree[n].mx+=d;
        return;
    }
    if(tree[n].flag==1)
    {
        tree[n<<1].flag=1;
        tree[n<<1].mx=min(tree[n<<1].mx,tree[n].mx);
        tree[n<<1|1].flag=1;
        tree[n<<1|1].mx=min(tree[n<<1|1].mx,tree[n].mx);
    }
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m)
        add(n<<1,l,r,d);
    else if(l>=m)
        add(n<<1|1,l,r,d);
    else
    {
        add(n<<1,l,m,d);
        add(n<<1,m+1,r,d);
    }
}

void change(int n,int l,int r,int mx)
{
    if(tree[n].flag&&tree[n].l==l&&r==tree[n].r)
    {
        tree[n].mx+=d;
        return;
    }
    if(tree[n].flag==1)
    {
        tree[n<<1].flag=1;
        tree[n<<1].mx=min(tree[n<<1].mx,tree[n].mx);
        tree[n<<1|1].flag=1;
        tree[n<<1|1].mx=min(tree[n<<1|1].mx,tree[n].mx);
    }
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m)
        add(n<<1,l,r,d);
    else if(l>=m)
        add(n<<1|1,l,r,d);
    else
    {
        add(n<<1,l,m,d);
        add(n<<1,m+1,r,d);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
