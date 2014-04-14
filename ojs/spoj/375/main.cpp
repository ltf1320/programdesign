#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+100;

int size[maxn],top[maxn],fa[maxn],w[maxn],dep[maxn];

struct Tree
{
    int mx,l,r;
};
Tree tree[4*maxn];
int end;
struct EDGE
{
    int to,next;
};
EDGE edge[maxn*2];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void dfs(int v)
{
    size[v]=0;
    son[v]=0;
    for(int i=box[v];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[v])
        {
            fa[edge[i].to]=v;
            dep[edge[i].to]=dep[v]+1;
            dfs(edge[i].to);
            size[v]++size[edge[i].to];
            if(son[v]||size[edge[i].to]>size[son[v]])
            {
                son[v]=edge[i].to;
            }
        }
    }
}

void insert_tree(int v,int tp)
{
    w[v]=++end;
    top[v]=tp;
    if(son[v])
        insert_tree(son[v],tp);
    for(int i=box[v];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[v]&&edge[i].to!=son[v])
        {
            insert_tree(edge[i].to,edge[i].to);
        }
    }
}

void build_tree(int now,int l,int r)
{
    tree[now].l=l;
    tree[now].r=r;
    tree[now].mx=-1;
    int m=(l+r)>>1;
    build_tree(now<<1,l,m);
    build_tree(now<<1|1,m+1,r);
}

void update(int now,int e,int v)
{
    if(tree[now].l==tree[now].r)
    {
        tree[now].mx=v;
        return;
    }
    int m=(tree[now].l+tree[now].r)/2;
    if(e<=m)
        update(now<<1,e,v);
    if(e>m)
        update(now<<1|1,e,v);
}

int getMx(int now,int l,int r)
{
    if(tree[now].l==l&&tree[now].r==r)
        return tree[now].mx;
    int m=(l+r)>>1;
    if(r<=m)
        return getMx(now<<1,l,r);
    else if(l>m)
        return getMx(now<<1|1,l,r);
    else
    {
        return max(
        getMx(now<<1,l,m),
        getMx(now<<1|1,m+1,r));
    }
}

void find(int a,int b)
{
    int fa=top[a],fb=top[b];
    while(fa!=fb)
    {
        if(dep[fa]<dep[fb])
        {
            swap(fa,fb);
            swap(a,b);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
