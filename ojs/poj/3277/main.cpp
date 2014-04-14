#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int maxn=40000+100;
int N;
struct Building
{
    int a,b,h;
};
Building bds[maxn];
map<int,int> mp;
set<int> st;
int hs[maxn*2];
struct Node
{
    int l,r;
    bool flag;
    LL h;
};
Node tree[maxn*8];

void buildTree(int n,int l,int r)
{
    tree[n].flag=0;
    tree[n].l=l;
    tree[n].r=r;
    if(l==r) return;
    int m=(tree[n].l+tree[n].r)/2;
    buildTree(n<<1,l,m);
    buildTree(n<<1|1,m+1,r);
}

void update(int n,int l,int r,LL h)
{
    if(tree[n].flag)
    {
        if(tree[n].h>h) return;
        else
        {
            if(tree[n].l==tree[n].r)
            {
                tree[n].h=h;
                return;
            }
            int m=(tree[n].l+tree[n].r)/2;
            tree[n].flag=0;
            update(n<<1,tree[n].l,m,tree[n].h);
            update(n<<1|1,m+1,tree[n].r,tree[n].h);
        }
    }
    if(tree[n].l==l&&tree[n].r==r)
    {
        tree[n].flag=1;
        tree[n].h=h;
        return;
    }
    int m=(tree[n].l+tree[n].r)/2;
    if(r<=m)
        update(n<<1,l,r,h);
    else if(l>m)
        update(n<<1|1,l,r,h);
    else
    {
        update(n<<1,l,m,h);
        update(n<<1|1,m+1,r,h);
    }
    if(tree[n<<1].flag&&tree[n<<1|1].flag&&tree[n<<1].h==tree[n<<1|1].h)
    {
        tree[n].flag=1;
        tree[n].h=tree[n<<1].h;
    }
}
LL query(int n)
{
    if(tree[n].flag)
    {
        return (hs[tree[n].r+1]-hs[tree[n].l])*tree[n].h;
    }
    if(tree[n].l==tree[n].r)
        return 0;
    return query(n<<1)+query(n<<1|1);
}

int kn=1;
void work()
{
    for(set<int>::iterator iter=st.begin();iter!=st.end();iter++,kn++)
    {
        mp.insert(make_pair(*iter,kn));
        hs[kn]=*iter;
    }
    buildTree(1,1,kn);
    for(int i=0;i<N;i++)
    {
        update(1,mp[bds[i].a],mp[bds[i].b-1],bds[i].h);
    }
    printf("%I64d\n",query(1));
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&bds[i].a,&bds[i].b,&bds[i].h);
        st.insert(bds[i].a);
        st.insert(bds[i].b-1);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    input();
    work();
    return 0;
}
