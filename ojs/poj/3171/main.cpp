#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000;
const int Inf=0x3f3f3f3f;

struct Node
{
    int flag,v;
    int l,r;
};
Node tree[4*maxn];

void buildtree(int l,int r,int n)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].flag=-1;
    tree[n].v=0;
    if(l==r)
        return;
    int m=(l+r)>>1;
    buildtree(l,m,n<<1);
    buildtree(m+1,r,n<<1|1);
    return;
}


void pushup(int n)
{
    if(tree[n<<1].v==tree[n<<1|1].v && tree[n<<1].flag==1 &&tree[n<<1|1].flag==1)
    {
        tree[n].v=tree[n<<1].v;
        tree[n].flag=1;
        tree[n<<1].flag=tree[n<<1|1].flag=-1;
    }
    else if(tree[n].flag==-1 && tree[n<<1].flag!=-1 && tree[n<<1|1].flag!=-1)
    {
        tree[n].flag=0;
    }
}

void change(int l,int r,const int v,int n)
{
    if(tree[n].l==l && tree[n].r==r)
    {
        if(tree[n].flag!=1)
        {
            tree[n].v=v;
            tree[n].flag=1;
            return;
        }
        else
        {
            if(v<tree[n].v)
                tree[n].v=v;
            return;
        }
    }
    else
    {
        int m=(tree[n].l+tree[n].r)>>1;
        if(r<=m)
            change(l,r,v,n<<1);
        else if(l<=m && r>m)
        {
            change(l,m,v,n<<1);
            change(m+1,r,v,n<<1|1);
        }
        else change(l,r,v,n<<1|1);
    }
    pushup(n);
}

int sums(int n)
{
    if(tree[n].flag==-1)
        return -1;
    if(tree[n].l==tree[n].r)
    {
        return 0;
    }
    else
    {
        if(tree[n].flag==1)
        {
            int s1=sums(n<<1);
            if(s1==-1) return tree[n].v;
            int s2=sums(n<<1|1);
            if(s2==-1) return tree[n].v;
            return min(s1+s2,tree[n].v);
        }
        int s1=sums(n<<1);
        if(s1==-1) return -1;
        int s2=sums(n<<1|1);
        if(s2==-1) return -1;
        return s1+s2;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int N,M,E;
    int r,l,v,res;
    while(~scanf("%d%d%d",&N,&M,&E))
    {
        buildtree(M,E+1,1);
        while(N--)
        {
            scanf("%d%d%d",&l,&r,&v);
            change(l,r+1,v,1);
        }
        res=sums(1);
        printf("%d\n",res);
    }
    return 0;
}
