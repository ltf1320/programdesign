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

void change(int n,int l,int r,int h)
{
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

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&nds[i].a,&nds[i].b,&nds[i].h);
        st.insert(nds[i].a);
        st.insert(nds[i].b);
    }
    on=1;
    for(set<int>::iterator iter=st.begin();iter!=st.end();iter++)
    {
        ori[on]=*iter;
        mp.insert(make_pair(*iter,on));
        on++;
    }
    sort(nds,nds+N);
    buildTree(1,1,on-1);
    for(int i=0;i<N;i++)
        change(1,mp[nds[i].a],mp[nds[i].b],nds[i].h);
    printf("%I64d\n",getSum(1));
    return 0;
}
