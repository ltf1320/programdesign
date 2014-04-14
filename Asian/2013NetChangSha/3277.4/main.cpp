#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=40000+100;
int N;
int ori[8*maxn];
int on;
set<int> st;
map<int,int> mp;
struct Node
{
    int a,b,h;
    bool operator<(const Node &p) const
    {
        return h<p.h;
    }
};
Node nds[maxn];

struct Tree
{
    int l,r,h;
    bool flag;
};
Tree tree[16*maxn];
void buildTree(int n,int l,int r)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].flag=0;
    tree[n].h=0;
    if(l+1==r) return;
    int m=(l+r)>>1;
    buildTree(n<<1,l,m);
    buildTree(n<<1|1,m,r);
}

void pushdown(int n)
{
    if(tree[n].flag)
    {
        tree[n].flag=0;
        tree[n<<1].flag=tree[n<<1|1].flag=1;
        tree[n<<1].h=tree[n<<1|1].h=tree[n].h;
    }
}

void change(int n,int l,int r,int h)
{
    pushdown(n);
    if(tree[n].l==l&&tree[n].r==r)
    {
        tree[n].flag=1;
        tree[n].h=h;
        return;
    }
    if(tree[n].l+1==tree[n].r) return;
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m)
        change(n<<1,l,r,h);
    else if(l>=m)
        change(n<<1|1,l,r,h);
    else
    {
        change(n<<1,l,m,h);
        change(n<<1|1,m,r,h);
    }
}

LL getSum(int n)
{
    if(tree[n].flag)
        return (ori[tree[n].r]-ori[tree[n].l])*(LL)tree[n].h;
    if(tree[n].l+1==tree[n].r) return 0;
    return getSum(n<<1)+getSum(n<<1|1);
}

int find(int n)
{
    int l=1,r=on;
    int m;
    while(l<r)
    {
        m=(l+r)/2;
        if(ori[m]==n) return m;
        if(ori[m]<n) l=m+1;
        else r=m;
    }
    return -10000;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    on=1;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&nds[i].a,&nds[i].b,&nds[i].h);
        ori[on++]=nds[i].a;
        ori[on++]=nds[i].b;
    }
    sort(ori+1,ori+on);
    on=unique(ori+1,ori+on)-ori;
    sort(nds,nds+N);
    buildTree(1,1,on);
    for(int i=0;i<N;i++)
        change(1,find(nds[i].a),find(nds[i].b),nds[i].h);
    printf("%I64d\n",getSum(1));
    return 0;
}
