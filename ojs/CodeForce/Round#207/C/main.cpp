#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3*100000+100;
int N,M;

struct Node
{
    int l,r;
    int c;
};
Node tree[4*maxn];

void BuildTree(int n,int l,int r)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].c=0;
    if(l==r) return;
    int m=(l+r)/2;
    BuildTree(n<<1,l,m);
    BuildTree(n<<1|1,m+1,r);
}

void change(int n,int l,int r,int con)
{
    if(tree[n].c)
        return;
    if(tree[n].l==l&&tree[n].r==r)
    {
        tree[n].c=con;
        return;
    }
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m)
        change(n<<1,l,r,con);
    else if(l>m)
        change(n<<1|1,l,r,con);
    else
    {
        change(n<<1,l,m,con);
        change(n<<1|1,m+1,r,con);
    }
}

void print(int n)
{
    if(tree[n].l==tree[n].r)
    {
        if(tree[n].l>1)
            putchar(' ');
        printf("%d",tree[n].c);
        return;
    }
    if(tree[n].c)
    {
        if(!tree[n<<1|1].c)
            tree[n<<1|1].c=tree[n].c;
        if(!tree[n<<1].c)
            tree[n<<1].c=tree[n].c;
    }
    print(n<<1);
    print(n<<1|1);

}

int main()
{
    scanf("%d%d",&N,&M);
    BuildTree(1,1,N);
    int l,r,x;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        if(x>l)
            change(1,l,x-1,x);
        if(x<r)
            change(1,x+1,r,x);
    }
    print(1);
    return 0;
}
