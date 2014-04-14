#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=400+10;
struct Tree
{
    int l,r,num,lazy;
};
Tree tree[4*maxn];

void buildTree(int n,int l,int r)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].num=0;
    tree[n].lazy=1;
    if(l==r) return;
    int m=(r+l)/2;
    buildTree(2*n,l,m);
    buildTree(2*n+1,m+1,r);
}

void update(int n,int l,int r,int num)
{
    if(tree[n].l==tree[n].r)
    {
        tree[n].num+=num;
        return;
    }
    int m=(tree[n].l+tree[n].r)/2;
    if(l==tree[n].l&&r==tree[n].r)
    {
        if(tree[n].lazy)    tree[n].num+=num;
        else{
            update(n*2,l,m,num);
            update(n*2+1,m+1,r,num);
        }
    }
    else
    {
        if(tree[n].lazy&&tree[n].num)
        {
            update(n*2,tree[n].l,m,tree[n].num);
            update(n*2+1,m+1,tree[n].r,tree[n].num);
        }
        tree[n].lazy=0;
        if(r<=m)
            update(n*2,l,r,num);
        else if(l>=m+1)
            update(n*2+1,l,r,num);
        else
        {
            update(n*2,l,m,num);
            update(n*2+1,m+1,r,num);
        }
    }
    if(!tree[n].lazy)
        tree[n].num=max(tree[n<<1].num,tree[n<<1|1].num);
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int N;
    int l,r;
    scanf("%d",&T);
    while(T--)
    {
        buildTree(1,1,410);
        scanf("%d",&N);
        while(N--)
        {
            scanf("%d%d",&l,&r);
            update(1,(l+1)/2,(r+1)/2,1);
        }
        printf("%d\n",tree[1].num*10);
    }
    return 0;
}
